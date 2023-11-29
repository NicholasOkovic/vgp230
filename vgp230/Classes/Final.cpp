#include "Final.h"

Scene* Final::createScene()
{
	return Final::create();
}


bool Final::init()
{

	SpaceShip = Sprite::create("carrier_01.png");
	this->addChild(SpaceShip, 1);

	SpaceShip->setPosition(500, 500);



	scheduleUpdate();
	return true;
};


void Final::update(float dt)
{






};
