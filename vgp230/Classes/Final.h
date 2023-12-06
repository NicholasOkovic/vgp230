#pragma once
#include "cocos2d.h"
#include "KeyboardControllerComponent.h"
#include "CollisionComponent.h"

//try to only do basic things that would be used in all levels here


USING_NS_CC;
using namespace std;

class Final : public Scene
{
public:
	static Scene* createScene();

	virtual bool init();
	virtual void update(float dt);

	int DashCooldown = 100;
	int DashTimer = 0;
	int DashSpeed = 300;
	int DiagonalDashSpeed = 200;

	Vec2 ShipVelocity = Vec2(0,0);
	int ShipSpeed = 2;
	int SpeedLimiter = 150;
	int DecelerationSpeed = 3;
	

	Sprite* SpaceShip = NULL;

	Sprite* SpaceShipSprite = NULL;
	/// Test sprite change
	

	Sprite* Ship1Up = NULL;
	Sprite* Ship2 = NULL;
	Sprite* Ship3 = NULL;
	Sprite* Ship4 = NULL;
	Sprite* Ship5 = NULL;
	Sprite* Ship6 = NULL;
	Sprite* Ship7 = NULL;
	Sprite* Ship8 = NULL;

	Sprite* Ship9Right = NULL;
	Sprite* Ship10 = NULL;
	Sprite* Ship11 = NULL;
	Sprite* Ship12 = NULL;
	Sprite* Ship13 = NULL;
	Sprite* Ship14 = NULL;
	Sprite* Ship15 = NULL;
	Sprite* Ship16 = NULL;

	Sprite* Ship17Down = NULL;
	Sprite* Ship18 = NULL;
	Sprite* Ship19 = NULL;
	Sprite* Ship20 = NULL;
	Sprite* Ship21 = NULL;
	Sprite* Ship22 = NULL;
	Sprite* Ship23 = NULL;
	Sprite* Ship24 = NULL;

	Sprite* Ship25Left = NULL;
	Sprite* Ship26 = NULL;
	Sprite* Ship27 = NULL;
	Sprite* Ship28 = NULL;
	Sprite* Ship29 = NULL;
	Sprite* Ship30 = NULL;
	Sprite* Ship31 = NULL;
	Sprite* Ship32 = NULL;

	bool down = false;
	bool left = false;
	bool up = false;
	bool right = false;

	void changeActiveSprite(Sprite* newActive);
	

	Sprite* LevelOneCol;

	KeyboardControllerComponent* keyboard;



	DrawNode* debug;
	bool debugDrawEnabled = false;


	Label* DashTimerTxt;



	CREATE_FUNC(Final);
private:

};

