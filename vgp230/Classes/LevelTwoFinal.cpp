#include "LevelTwoFinal.h"


Scene* LevelTwoFinal::createScene()
{
	return LevelTwoFinal::create();
}



bool LevelTwoFinal::init()
{

	StartInit(this);

	SpaceShip::getInstance()->LevelTwoTime = 0;

	BoundryRight = Sprite::create("blue.jpg");
	this->addChild(BoundryRight);
	BoundryRight->setPosition(LevelOffset.x * 2 + (BoundryRight->getContentSize().width) / 2, Director::getInstance()->getVisibleSize().height / 2);
	BoundryRight->setScaleY(BoundryScale);
	BoundryRight->addComponent(CollisionComponent::createBox((BoundryRight->getContentSize().width), BoundryRight->getContentSize().height * BoundryScale));
	BoundryRight->setOpacity(25);

	BoundryLeft = Sprite::create("blue.jpg");
	this->addChild(BoundryLeft);
	BoundryLeft->setPosition(LevelOffset.x - BoundryLeft->getContentSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	BoundryLeft->setScaleY(BoundryScale);
	BoundryLeft->addComponent(CollisionComponent::createBox((BoundryLeft->getContentSize().width), BoundryLeft->getContentSize().height * BoundryScale));
	BoundryLeft->setOpacity(25);

	LevelSelectCol = Sprite::create("blue.jpg");
	this->addChild(LevelSelectCol, 1);
	LevelSelectCol->addComponent(CollisionComponent::createBox(LevelSelectCol->getContentSize().width, LevelSelectCol->getContentSize().height));
	LevelSelectCol->setPosition(LevelOffset + Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height * 3));
	LevelSelectCol->setName("LevelSelect");




	LargeAstroid_01 = Sprite::create("AddedImages/Meteor_01.png");
	this->addChild(LargeAstroid_01);
	LargeAstroid_01->setScale(2);
	LargeAstroid_01->addComponent(CollisionComponent::createBox(LargeAstroid_01->getContentSize().width * LargeAstroid_01->getScaleX(), LargeAstroid_01->getContentSize().height * LargeAstroid_01->getScaleY()));
	LargeAstroid_01->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height);
	LargeAstroid_01->setRotation(180);


	LargeAstroid_05 = Sprite::create("AddedImages/Meteor_02.png");	
	this->addChild(LargeAstroid_05);
	LargeAstroid_05->setScale(0.5);
	LargeAstroid_05->addComponent(CollisionComponent::createBox(LargeAstroid_05->getContentSize().width * LargeAstroid_05->getScaleX(), LargeAstroid_05->getContentSize().height * LargeAstroid_05->getScaleY()));
	LargeAstroid_05->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width/2, Director::getInstance()->getVisibleSize().height * 1.5);
	


	LargeAstroid_04 = Sprite::create("AddedImages/Meteor_04.png");
	this->addChild(LargeAstroid_04);
	LargeAstroid_04->setScale(1);
	LargeAstroid_04->addComponent(CollisionComponent::createBox(LargeAstroid_04->getContentSize().width * (LargeAstroid_04->getScaleX() / 1.2), LargeAstroid_04->getContentSize().height * (LargeAstroid_04->getScaleY() / 1.2)));
	LargeAstroid_04->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width / 8, Director::getInstance()->getVisibleSize().height / 1.2);
	LargeAstroid_04->setRotation(140);


	LargeAstroid_01 = Sprite::create("AddedImages/Meteor_01.png");
	this->addChild(LargeAstroid_01);
	LargeAstroid_01->setScale(2);
	LargeAstroid_01->addComponent(CollisionComponent::createBox(LargeAstroid_01->getContentSize().width * LargeAstroid_01->getScaleX(), LargeAstroid_01->getContentSize().height * LargeAstroid_01->getScaleY()));
	LargeAstroid_01->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height * 2);
	LargeAstroid_01->setRotation(180);

	LargeAstroid_04 = Sprite::create("AddedImages/Meteor_04.png");
	this->addChild(LargeAstroid_04);
	LargeAstroid_04->setScale(1);
	LargeAstroid_04->addComponent(CollisionComponent::createBox(LargeAstroid_04->getContentSize().width * (LargeAstroid_04->getScaleX() / 1.2), LargeAstroid_04->getContentSize().height * (LargeAstroid_04->getScaleY() / 1.2)));
	LargeAstroid_04->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width / 8, Director::getInstance()->getVisibleSize().height * 2.5);
	LargeAstroid_04->setRotation(140);



	LevelTwoItem_01 = Sprite::create("AddedImages/Golden_Key.png");					
	this->addChild(LevelTwoItem_01);
	LevelTwoItem_01->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width / 6, Director::getInstance()->getVisibleSize().height * 1.2);
	LevelTwoItem_01->setScale(0.05);
	LevelTwoItem_01->addComponent(CollisionComponent::createBox(LevelTwoItem_01->getContentSize().width * LevelTwoItem_01->getScaleX(), LevelTwoItem_01->getContentSize().height * LevelTwoItem_01->getScaleY()));
	LevelTwoItem_01->setName("Item2-1");

	LevelTwoItem_02 = Sprite::create("AddedImages/Golden_Crown.png");
	this->addChild(LevelTwoItem_02);
	LevelTwoItem_02->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width / 2, 0 - Director::getInstance()->getVisibleSize().height / 4);
	LevelTwoItem_02->setScale(0.1);
	LevelTwoItem_02->addComponent(CollisionComponent::createBox(LevelTwoItem_02->getContentSize().width * LevelTwoItem_02->getScaleX(), LevelTwoItem_02->getContentSize().height * LevelTwoItem_02->getScaleX()));
	LevelTwoItem_02->setName("Item2-2");



	
	SpaceShip->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, 500);

	SpaceShip->addComponent(VelocityComponent::create(Vec2(0, 20), 20));
	sceneState = levelTwo;
	keyboard->initInput();

	scheduleUpdate();
	return true;
}

void LevelTwoFinal::update(float dt)
{
	SpaceShip::getInstance()->LevelTwoTime += (1 * dt);

	MovementAndHud(dt, this);
	
	

	CollisionAndDebug(this);



	PlayerPosition = SpaceShip->getPosition();		
	this->_defaultCamera->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, SpaceShip->getPosition().y);			
}