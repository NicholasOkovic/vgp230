#pragma once
#include "cocos2d.h"
#include "KeyboardControllerComponent.h"


USING_NS_CC;
using namespace std;

class Final : public Scene
{
public:
	static Scene* createScene();

	virtual bool init();
	virtual void update(float dt);


	Sprite* SpaceShip;

	CREATE_FUNC(Final);
private:

};

