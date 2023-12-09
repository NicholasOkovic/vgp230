#include "Final.h"
#include "LevelOneFinal.h"

Scene* Final::createScene()
{
	return Final::create();
}





/// what needs to get done \\\
/// 
///
/// get camera to folloow player but not horiz
/// mkae sure player cant escape play area

/// add a menu
/// add level 1
/// add lvl 2
/// Make background stars
/// create healthbar


bool Final::init()
{
	StartInit(this);

	OOBTop = Sprite::create("blue.jpg");
	this->addChild(OOBTop);
	OOBTop->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height);
	OOBTop->setScaleX(OOBScale);
	OOBTop->addComponent(CollisionComponent::createBox((OOBTop->getContentSize().width * OOBScale), OOBTop->getContentSize().height));
	OOBTop->setOpacity(25);

	OOBBottom = Sprite::create("blue.jpg");
	this->addChild(OOBBottom);
	OOBBottom->setPosition(Director::getInstance()->getVisibleSize().width / 2, 0);
	OOBBottom->setScaleX(OOBScale);
	OOBBottom->addComponent(CollisionComponent::createBox((OOBTop->getContentSize().width * OOBScale), OOBTop->getContentSize().height));
	OOBBottom->setOpacity(25);

	OOBLeft = Sprite::create("blue.jpg");
	this->addChild(OOBLeft);
	OOBLeft->setPosition(0, Director::getInstance()->getVisibleSize().height / 2);
	OOBLeft->setScaleY(SideOOBScale);
	OOBLeft->addComponent(CollisionComponent::createBox((OOBTop->getContentSize().width), OOBTop->getContentSize().height * SideOOBScale));
	OOBLeft->setOpacity(25);

	OOBRight = Sprite::create("blue.jpg");
	this->addChild(OOBRight);
	OOBRight->setPosition(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height / 2);
	OOBRight->setScaleY(SideOOBScale);
	OOBRight->addComponent(CollisionComponent::createBox((OOBTop->getContentSize().width), OOBTop->getContentSize().height* SideOOBScale));
	OOBRight->setOpacity(25);
	
	if (FirstPlay == true)
	{
		Sprite* WASD = Sprite::create("WASDkeys.png");
		this->addChild(WASD, 1);
		WASD->setScale(0.5);
		WASD->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 3);
		WASD->setOpacity(80);
		Label* HowToPlayTxt = Label::create();
		this->addChild(HowToPlayTxt, 1);
		HowToPlayTxt->setString("To play");
		HowToPlayTxt->setPosition(WASD->getPosition() - Vec2(0, 80));
		HowToPlayTxt->setScale(2);
		HowToPlayTxt->setOpacity(200);
	}
	

	Sprite* LevelOneCol;
	Sprite* LevelTwoCol;
	Sprite* TrophiesCol;
	Sprite* LeaveCol;

	LevelOneCol = Sprite::create("cheese.png");
	this->addChild(LevelOneCol, 1);
	LevelOneCol->addComponent(CollisionComponent::createCircle((LevelOneCol->getContentSize().height) / 2));
	LevelOneCol->setPosition(200, 600);
	LevelOneCol->setName("LevelOne");

	LevelTwoCol = Sprite::create("carrot.png");
	this->addChild(LevelTwoCol);
	LevelTwoCol->addComponent(CollisionComponent::createBox(LevelTwoCol->getContentSize().width, LevelTwoCol->getContentSize().height));
	LevelTwoCol->setPosition(800, 600);
	LevelTwoCol->setName("LevelTwo");

	TrophiesCol = Sprite::create("carrot.png");
	this->addChild(TrophiesCol);
	TrophiesCol->addComponent(CollisionComponent::createBox(TrophiesCol->getContentSize().width, TrophiesCol->getContentSize().height));
	TrophiesCol->setPosition(800, 200);
	TrophiesCol->setName("Trophy");

	LeaveCol = Sprite::create("cheese.png");
	this->addChild(LeaveCol, 1);
	LeaveCol->addComponent(CollisionComponent::createCircle((LevelOneCol->getContentSize().height) / 2));
	LeaveCol->setPosition(200, 200);
	LeaveCol->setName("Leave");

	Vec2 TitleOffset = Vec2(0, 50);
	
	Label* LevelOneTxt = Label::create();
	LevelOneTxt->setPosition(LevelOneCol->getPosition() + TitleOffset);
	LevelOneTxt->setString("Level 1");
	this->addChild(LevelOneTxt, 5);
	LevelOneTxt->setScale(2);

	Label* LevelTwoTxt = Label::create();
	LevelTwoTxt->setPosition(LevelTwoCol->getPosition() + TitleOffset);
	LevelTwoTxt->setString("Level 2");
	this->addChild(LevelTwoTxt, 5);
	LevelTwoTxt->setScale(2);

	Label* TrophiesColTxt = Label::create();
	TrophiesColTxt->setPosition(TrophiesCol->getPosition() + TitleOffset);
	TrophiesColTxt->setString("Trophy room");
	this->addChild(TrophiesColTxt, 5);
	TrophiesColTxt->setScale(2);

	Label* LeaveColTxt = Label::create();
	LeaveColTxt->setPosition(LeaveCol->getPosition() + TitleOffset);
	LeaveColTxt->setString("Exit");
	this->addChild(LeaveColTxt, 5);
	LeaveColTxt->setScale(2);

	sceneState = levelSelect;

	keyboard->initInput();
	scheduleUpdate();
	return true;
};


void Final::update(float dt)
{
	MovementAndHud(dt);

	CollisionAndDebug(this);

	PlayerPosition = SpaceShip->getPosition();
	this->_defaultCamera->setPosition(PlayerPosition);

};


	void Final::SwitchToLevelOne()
	{
		Director::getInstance()->replaceScene(LevelOneFinal::createScene());
	}
