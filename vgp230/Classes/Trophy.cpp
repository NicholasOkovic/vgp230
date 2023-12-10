#include "Trophy.h"

Scene* Trophy::createScene()
{
	return Trophy::create();
}



bool Trophy::init()
{
	StartInit(this);

	OOBTop = Sprite::create("blue.jpg");
	this->addChild(OOBTop);
	OOBTop->setPosition(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height);
	OOBTop->setScaleX(OOBScale + SideOOBScale);
	OOBTop->addComponent(CollisionComponent::createBox((OOBTop->getContentSize().width * (OOBScale + SideOOBScale)), OOBTop->getContentSize().height));
	OOBTop->setOpacity(25);

	OOBBottom = Sprite::create("blue.jpg");
	this->addChild(OOBBottom);
	OOBBottom->setPosition(Director::getInstance()->getVisibleSize().width, 0);
	OOBBottom->setScaleX(OOBScale + SideOOBScale);
	OOBBottom->addComponent(CollisionComponent::createBox((OOBBottom->getContentSize().width * (OOBScale + SideOOBScale)), OOBBottom->getContentSize().height));
	OOBBottom->setOpacity(25);

	OOBLeft = Sprite::create("blue.jpg");
	this->addChild(OOBLeft);
	OOBLeft->setPosition(0 + OOBLeft->getContentSize().width * 1.5, Director::getInstance()->getVisibleSize().height / 2 );
	OOBLeft->setScaleY(SideOOBScale);
	OOBLeft->addComponent(CollisionComponent::createBox((OOBTop->getContentSize().width), OOBTop->getContentSize().height * SideOOBScale));
	OOBLeft->setOpacity(25);

	OOBRight = Sprite::create("blue.jpg");
	this->addChild(OOBRight);
	OOBRight->setPosition(Director::getInstance()->getVisibleSize().width * 2 - OOBRight->getContentSize().width * 1.5, Director::getInstance()->getVisibleSize().height / 2);
	OOBRight->setScaleY(SideOOBScale);
	OOBRight->addComponent(CollisionComponent::createBox((OOBTop->getContentSize().width), OOBTop->getContentSize().height * SideOOBScale));
	OOBRight->setOpacity(25);


	keyboard->initInput();
	scheduleUpdate();
	return true;
}



void Trophy::update(float dt)
{
	MovementAndHud(dt);

	CollisionAndDebug(this);


	PlayerPosition = SpaceShip->getPosition();
	this->_defaultCamera->setPosition(PlayerPosition.x, Director::getInstance()->getVisibleSize().height /2);
}