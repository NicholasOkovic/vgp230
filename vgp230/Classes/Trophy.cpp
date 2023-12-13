#include "Trophy.h"
//#include "SpaceShip.h"
Scene* Trophy::createScene()
{
	return Trophy::create();
}



bool Trophy::init()
{
	sceneState = trophy;

	StartInit(this);

	particleSystem_01 = ParticleSystemQuad::create("Particle/Unlock.plist");
	this->addChild(particleSystem_01, 6);
	particleSystem_01->setScale(0.25);

	particleSystem_02 = ParticleSystemQuad::create("Particle/Unlock.plist");
	this->addChild(particleSystem_02, 6);
	particleSystem_02->setScale(0.25);

	particleSystem_01->setPosition(-1000, -1000);
	particleSystem_02->setPosition(-1000, -1000);

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

	SpaceShip->setPosition(SpaceShip->getContentSize().width * 2, Director::getInstance()->getVisibleSize().height / 2);

	LevelOneTimeTxt = Label::create();
	this->addChild(LevelOneTimeTxt);
	LevelOneTimeTxt->setPosition(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height / 1.25);
	LevelOneTimeTxt->setScale(5);

	if (SpaceShip::getInstance()->LevelOneTimeComp > 0)
	{
		int Minutes = (SpaceShip::getInstance()->LevelOneTimeComp / 60);
		
		int Seconds = (fmod(SpaceShip::getInstance()->LevelOneTimeComp, 60.0f));
		string MinToString = to_string(Minutes);								///////////////////////////////// Fix Time UI	
		string SecToString = to_string(Seconds);

		LevelOneTimeTxt->setString("Level 1");
		DisplayTime_01 = Label::create();
		this->addChild(DisplayTime_01);
		DisplayTime_01->setScale(5);
		DisplayTime_01->setPosition(LevelOneTimeTxt->getPosition().x, LevelOneTimeTxt->getPosition().y - LevelOneTimeTxt->getRenderingFontSize()* LevelOneTimeTxt->getScale());
		DisplayTime_01->setString(MinToString + ":" + SecToString);
	}
	else
		LevelOneTimeTxt->setString("       Level 1\nNot Completed");
	
	LevelTwoTimeTxt = Label::create();
	this->addChild(LevelTwoTimeTxt);
	LevelTwoTimeTxt->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, Director::getInstance()->getVisibleSize().height / 1.25);
	LevelTwoTimeTxt->setScale(5);

	if (SpaceShip::getInstance()->LevelTwoTimeComp > 0)
	{
		int Minutes = (SpaceShip::getInstance()->LevelTwoTimeComp / 60);

		int Seconds = (fmod(SpaceShip::getInstance()->LevelTwoTimeComp, 60.0f));
		string MinToString = to_string(Minutes);									
		string SecToString = to_string(Seconds);

		LevelTwoTimeTxt->setString("Level 2");
		DisplayTime_02 = Label::create();
		this->addChild(DisplayTime_02);
		DisplayTime_02->setScale(5);
		DisplayTime_02->setPosition(LevelTwoTimeTxt->getPosition().x, LevelTwoTimeTxt->getPosition().y - LevelTwoTimeTxt->getRenderingFontSize() * LevelTwoTimeTxt->getScale());
		DisplayTime_02->setString(MinToString + ":" + SecToString);
	}
	else
		LevelTwoTimeTxt->setString("       Level 2\nNot Completed");


	LevelOneItem_01 = Sprite::create("AddedImages/Gold_bar.webp");
	this->addChild(LevelOneItem_01);
	LevelOneItem_01->setPosition(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height / 2);
	LevelOneItem_01->setScale(0.2);
	LevelOneItem_01->addComponent(CollisionComponent::createBox(LevelOneItem_01->getContentSize().width * LevelOneItem_01->getScaleX(), LevelOneItem_01->getContentSize().height * LevelOneItem_01->getScaleY()));
	LevelOneItem_01->setColor(Color3B::Color3B(50, 50, 50));
	

	LevelOneItemTrig_01 = Sprite::create("blue.jpg");
	this->addChild(LevelOneItemTrig_01, 1);
	LevelOneItemTrig_01->setPosition(LevelOneItem_01->getPosition());
	LevelOneItemTrig_01->addComponent(CollisionComponent::createBox(LevelOneItemTrig_01->getContentSize().width*5, LevelOneItemTrig_01->getContentSize().height*10));
	LevelOneItemTrig_01->setName("Trigger");
	LevelOneItemTrig_01->setVisible(false);

	LevelOneItem_02 = Sprite::create("AddedImages/Golden_Ore.png");
	this->addChild(LevelOneItem_02);
	LevelOneItem_02->setPosition(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height / 5);
	LevelOneItem_02->setScale(0.02);
	LevelOneItem_02->addComponent(CollisionComponent::createBox(LevelOneItem_02->getContentSize().width * LevelOneItem_02->getScaleX(), LevelOneItem_02->getContentSize().height * LevelOneItem_02->getScaleX()));
	LevelOneItem_02->setColor(Color3B::Color3B(50, 50, 50));


	LevelOneItemTrig_02 = Sprite::create("blue.jpg");
	this->addChild(LevelOneItemTrig_02, 1);
	LevelOneItemTrig_02->setPosition(LevelOneItem_02->getPosition());
	LevelOneItemTrig_02->addComponent(CollisionComponent::createBox(LevelOneItemTrig_02->getContentSize().width * 5, LevelOneItemTrig_02->getContentSize().height * 10));
	LevelOneItemTrig_02->setName("Trigger");
	LevelOneItemTrig_02->setVisible(false);

	LevelTwoItem_01 = Sprite::create("AddedImages/Golden_Key.png");
	this->addChild(LevelTwoItem_01);
	LevelTwoItem_01->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, Director::getInstance()->getVisibleSize().height / 2);
	LevelTwoItem_01->setScale(0.05);
	LevelTwoItem_01->addComponent(CollisionComponent::createBox(LevelTwoItem_01->getContentSize().width * LevelTwoItem_01->getScaleX(), LevelTwoItem_01->getContentSize().height * LevelTwoItem_01->getScaleY()));
	LevelTwoItem_01->setColor(Color3B::Color3B(50, 50, 50));
	

	LevelTwoItemTrig_01 = Sprite::create("blue.jpg");
	this->addChild(LevelTwoItemTrig_01, 1);
	LevelTwoItemTrig_01->setPosition(LevelTwoItem_01->getPosition());
	LevelTwoItemTrig_01->addComponent(CollisionComponent::createBox(LevelTwoItemTrig_01->getContentSize().width * 5, LevelTwoItemTrig_01->getContentSize().height * 10));
	LevelTwoItemTrig_01->setName("Trigger");
	LevelTwoItemTrig_01->setVisible(false);

	LevelTwoItem_02 = Sprite::create("AddedImages/Golden_Crown.png");
	this->addChild(LevelTwoItem_02);
	LevelTwoItem_02->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, Director::getInstance()->getVisibleSize().height / 5);
	LevelTwoItem_02->setScale(0.1);
	LevelTwoItem_02->addComponent(CollisionComponent::createBox(LevelTwoItem_02->getContentSize().width * LevelTwoItem_02->getScaleX()/2, LevelTwoItem_02->getContentSize().height * LevelTwoItem_02->getScaleY()/2));
	LevelTwoItem_02->setColor(Color3B::Color3B(50, 50, 50));
	
	LevelTwoItemTrig_02 = Sprite::create("blue.jpg");
	this->addChild(LevelTwoItemTrig_02, 1);
	LevelTwoItemTrig_02->setPosition(LevelTwoItem_02->getPosition());
	LevelTwoItemTrig_02->addComponent(CollisionComponent::createBox(LevelTwoItemTrig_02->getContentSize().width * 5, LevelTwoItemTrig_02->getContentSize().height * 10));
	LevelTwoItemTrig_02->setName("Trigger");
	LevelTwoItemTrig_02->setVisible(false);

	LevelSelectCol = Sprite::create("blue.jpg");
	this->addChild(LevelSelectCol, 1);
	LevelSelectCol->addComponent(CollisionComponent::createBox(LevelSelectCol->getContentSize().width, LevelSelectCol->getContentSize().height));
	LevelSelectCol->setPosition(Director::getInstance()->getVisibleSize().width / 4, Director::getInstance()->getVisibleSize().height / 5);
	LevelSelectCol->setName("LevelSelect");

	LevelSelectTxt = Label::create();
	this->addChild(LevelSelectTxt, 1);
	LevelSelectTxt->setPosition(LevelSelectCol->getPosition() - TitleOffset);
	LevelSelectTxt->setString("Back");
	LevelSelectTxt->setScale(2);

	keyboard->initInput();
	scheduleUpdate();
	return true;
}



void Trophy::update(float dt)
{
	MovementAndHud(dt, this);

	CollisionAndDebug(this);

	//particle activation check
	
	if (LevelOneItemTrig_01->getName() == "Activated" && SpaceShip::getInstance()->HasLevelOneItem_01)
	{
		particleSystem_01->setPosition(LevelOneItem_01->getPosition());
		particleSystem_01->start();
		LevelOneItem_01->setColor(Color3B::Color3B(255, 255, 255));
		LevelOneItemTrig_01->setName("FalseCollision");

	}
	else if (LevelOneItemTrig_01->getName() == "Activated")
	{
		LevelOneItemTrig_01->setName("FalseCollision");
	}
	if (LevelOneItemTrig_02->getName() == "Activated" && SpaceShip::getInstance()->HasLevelOneItem_02)
	{
		particleSystem_02->setPosition(LevelOneItem_02->getPosition());
		particleSystem_02->start();
		LevelOneItem_02->setColor(Color3B::Color3B(255, 255, 255));
		LevelOneItemTrig_02->setName("FalseCollision");
	}
	else if (LevelOneItemTrig_02->getName() == "Activated")
	{
		LevelOneItemTrig_02->setName("FalseCollision");
	}
	if (LevelTwoItemTrig_01->getName() == "Activated" && SpaceShip::getInstance()->HasLevelTwoItem_01)
	{
		particleSystem_01->setPosition(LevelTwoItem_01->getPosition());
		particleSystem_01->start();
		LevelTwoItem_01->setColor(Color3B::Color3B(255, 255, 255));
		LevelTwoItemTrig_01->setName("FalseCollision");
	}
	else if (LevelTwoItemTrig_01->getName() == "Activated")
	{
		LevelTwoItemTrig_01->setName("FalseCollision");
	}
	if (LevelTwoItemTrig_02->getName() == "Activated" && SpaceShip::getInstance()->HasLevelTwoItem_02)
	{
		particleSystem_02->setPosition(LevelTwoItem_02->getPosition());
		particleSystem_02->start();
		LevelTwoItem_02->setColor(Color3B::Color3B(255, 255, 255));
		LevelTwoItemTrig_02->setName("FalseCollision");
	}
	else if (LevelTwoItemTrig_02->getName() == "Activated")
	{
		LevelTwoItemTrig_02->setName("FalseCollision");
	}

	PlayerPosition = SpaceShip->getPosition();
	this->_defaultCamera->setPosition(PlayerPosition.x, Director::getInstance()->getVisibleSize().height /2);
}


