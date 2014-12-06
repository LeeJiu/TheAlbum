#ifndef INCLUDED_GAMECONTENT_DYNAMIC_OBJECT_H
#define INCLUDED_GAMECONTENT_DYNAMIC_OBJECT_H

class Image;
class StaticObject;

//게임 내 오브젝트 중에 움직이는 것들을 정의.
class DynamicObject{
public:
	enum Type{
		TYPE_PLAYER,
		TYPE_ENEMY,

		TYPE_NONE, //?귪궳귏궥
	};
	DynamicObject();
	void set( int x, int y, Type );
	void draw( const Image* ) const;
	//댷벍
	void move( const int* wallsX, int* wallsY, int wallNumber );
	//궵궞궻?긚궸뭷륲궕궇귡궻궔궫궦궺귡갃
	void getCell( int* x, int* y ) const;
	//dx,dy궬궚댷벍궢궫띧궸뢣궶궯궲궋귡?긚띆뷭귩봹쀱궸볺귢궲뺅궥갃
	//덙릶궼int[4]궕볫궰갃뽣귟뭠궼볺귢궫릶갃1,2,4궻궵귢궔갃
	int getIntersectionCell( int* xArray, int* yArray, int dx, int dy ) const;
	//륢궯궲궋귡띍묈4?긚귩롷궚롦궯궲돒뱴귩뛱궎갃
	void doCollisionReactionToStatic( StaticObject** o, int cellNumber );
	void doCollisionReactionToDynamic( DynamicObject* );

	//DynamicObject궴궻뚴뜼뵽믦
	bool isIntersect( const DynamicObject& ) const;
	//빮뾭
	bool isIntersectWall( int wallCellX, int wallCellY );

	//뺇뿕듫릶똒
	bool hasBombButtonPressed() const;	//뵚뭙??깛궕돓궠귢궫궔뮧귊귡
	bool isPlayer() const;
	bool isEnemy() const;
	void die(); //?궸귏궥(mType귩NONE궸궥귡궞궴궳?뙸)
	bool isDead() const; //?귪궳귏궥궔갎

	//뮳먝궋궣귟궫궩궎궶귖궻궼private궸궼궢궶궋갃븆붖궸State궔귞럊궎귖궻궬궔귞궬갃
	Type mType;
	//긵깒귽깂?먭뾭
	int mBombPower; //뵚뵯쀍
	int mBombNumber; //뵚뭙릶
	int mPlayerID; //긵깒귽깂?붥뜂
	//뵚뭙귩뭫궘릐먭뾭
	int mLastBombX[ 2 ];
	int mLastBombY[ 2 ];
private:
	//빮뾭
	static bool isIntersectWall( int x, int y, int wallCellX, int wallCellY );
	//뜞긲깒??궻댷벍쀊귩롦벦
	void getVelocity( int* dx, int* dy ) const;
	//댷벍뺴뛀귩롦벦
	void getDirection( int* dx, int* dy ) const;
	//띆뷭(볙븫뭁댧)
	int mX;
	int mY;
	//밎먭뾭
	int mDirectionX;
	int mDirectionY;
};

#endif
