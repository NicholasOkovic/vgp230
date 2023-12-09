#include "LevelOneFinal.h"


Scene* LevelOneFinal::createScene()
{
	return LevelOneFinal::create();
}



bool LevelOneFinal::init()
{

	BoundryRight = Sprite::create("blue.jpg");
	this->addChild(BoundryRight);
	BoundryRight->setPosition(LevelOffset.x * 2 + (BoundryRight->getContentSize().width)/2, Director::getInstance()->getVisibleSize().height / 2);
	BoundryRight->setScaleY(SideOOBScale);
	BoundryRight->addComponent(CollisionComponent::createBox((BoundryRight->getContentSize().width), BoundryRight->getContentSize().height * BoundryScale));
	BoundryRight->setOpacity(25);

	BoundryLeft = Sprite::create("blue.jpg");
	this->addChild(BoundryLeft);
	BoundryLeft->setPosition(LevelOffset.x - BoundryLeft->getContentSize().width /2, Director::getInstance()->getVisibleSize().height / 2);
	BoundryLeft->setScaleY(SideOOBScale);
	BoundryLeft->addComponent(CollisionComponent::createBox((BoundryLeft->getContentSize().width), BoundryLeft->getContentSize().height * BoundryScale));
	BoundryLeft->setOpacity(25);


	ObstacleTest = Sprite::create("blue.jpg");
	this->addChild(ObstacleTest);
	ObstacleTest->setPosition(LevelOffset + Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	ObstacleTest->addComponent(CollisionComponent::createBox((BoundryLeft->getContentSize().width), BoundryLeft->getContentSize().height));
	//ObstacleTest->addComponent(VelocityComponent::create(Vec2(0, -20), 10));
	ObstacleTest->setName("Obstacle");

	StartInit(this);
	keyboard->initInput();

	sceneState = levelOne;
	SpaceShip->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, 500);

	SpaceShip->addComponent(VelocityComponent::create(Vec2(0, 20), 20));
	scheduleUpdate();
	return true;
}





void LevelOneFinal::update(float dt)
{
	//ShipVelocity += Vec2(0,2);
	MovementAndHud(dt);

	CollisionAndDebug(this);

	PlayerPosition = SpaceShip->getPosition();
	this->_defaultCamera->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, PlayerPosition.y);				///make sure to fix ui

}


