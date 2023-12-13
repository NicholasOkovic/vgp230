#pragma once
#include "cocos2d.h"
#include "KeyboardControllerComponent.h"
#include "CollisionComponent.h"
#include "VelocityComponent.h"
#include "SpaceShip.h"

//try to only do basic things that would be used in all levels here


USING_NS_CC;
using namespace std;

class Final : public Scene
{
public:
	static Scene* createScene();

	enum SceneState
	{
		levelSelect,
		levelOne,
		levelTwo,
		trophy,
		death
	}
	sceneState = levelSelect;

	



	virtual bool init();
	virtual void update(float dt);

	int DashCooldown = 2.5;
	float DashTimer = 0;
	int DashSpeed = 300;
	int DiagonalDashSpeed = 200;

	Vec2 ShipVelocity = Vec2(0,0);
	int ShipSpeed = 2;
	int SpeedLimiter = 150;
	int DecelerationSpeed = 3;

	Sprite* VelocityBarW;
	Sprite* VelocityBarN;
	Sprite* VelocityBarS;
	Sprite* VelocityBarE;

	Sprite* VelArrowW_01;
	Sprite* VelArrowW_02;
	Sprite* VelArrowW_03;
	Sprite* VelArrowW_04;
	Sprite* VelArrowW_05;
	Sprite* VelArrowW_06;
	Sprite* VelArrowW_07;
	Sprite* VelArrowW_08;
	Sprite* VelArrowW_09;
	Sprite* VelArrowW_10;


	Sprite* VelArrowN_01;
	Sprite* VelArrowN_02;
	Sprite* VelArrowN_03;
	Sprite* VelArrowN_04;
	Sprite* VelArrowN_05;
	Sprite* VelArrowN_06;
	Sprite* VelArrowN_07;
	Sprite* VelArrowN_08;
	Sprite* VelArrowN_09;
	Sprite* VelArrowN_10;

	Sprite* VelArrowS_01;
	Sprite* VelArrowS_02;
	Sprite* VelArrowS_03;
	Sprite* VelArrowS_04;
	Sprite* VelArrowS_05;
	Sprite* VelArrowS_06;
	Sprite* VelArrowS_07;
	Sprite* VelArrowS_08;
	Sprite* VelArrowS_09;
	Sprite* VelArrowS_10;

	Sprite* VelArrowE_01;
	Sprite* VelArrowE_02;
	Sprite* VelArrowE_03;
	Sprite* VelArrowE_04;
	Sprite* VelArrowE_05;
	Sprite* VelArrowE_06;
	Sprite* VelArrowE_07;
	Sprite* VelArrowE_08;
	Sprite* VelArrowE_09;
	Sprite* VelArrowE_10;

	Vec2 UIOffset = Vec2(-150, -300);
	int StartArrowOffset = 70;
	int ArrowOffset = 15;
	int NextUI = 100;

	Vec2 PlayerPosition;

	int MovingObjectBounce = -80;

	//offsets
	Vec2 CooldownOffset = Vec2(-250, -350);
	


	int PlayerHP = 100;
	int PlayerMaxHP = 100;
	int InvinciblilityLength = 1;
	float InvincibilityFrames = 0;

	ParticleSystemQuad* ShipDamageParticle;
	

	Sprite* SpaceShip = NULL;

	Sprite* SpaceShipSprite = NULL;

	

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

	Vec2 TitleOffset = Vec2(0, 50);

	Sprite* LevelOneCol;		
	Sprite* LevelTwoCol;
	Sprite* LevelSelectCol;

	Label* LevelSelectTxt;

	

	Sprite* LevelOneItem_01;
	Sprite* LevelOneItem_02;

	Sprite* LevelTwoItem_01;
	Sprite* LevelTwoItem_02;



	void SwitchToLevelOne();
	void SwitchToLevelTwo();
	void SwitchToTrophy();
	
	void SwitchToLevelSelect()
	{
		Director::getInstance()->replaceScene(Final::createScene());
	}


	
	


	Sprite* OOBTop;
	Sprite* OOBBottom;
	Sprite* OOBRight;
	Sprite* OOBLeft;
	int OOBScale = 15;
	int SideOOBScale = 13;

	KeyboardControllerComponent* keyboard;



	DrawNode* debug;
	bool debugDrawEnabled = false;


	Label* DashTimerTxt;												////testing thing



	Sprite* BackgroundStarsS_01;
	Sprite* BackgroundStarsS_02;

	Sprite* BackgroundStarsL_01;
	Sprite* BackgroundStarsL_02;
	

	

	void FirstPlayOff()
	{
		SpaceShip::getInstance()->FirstPlay = false;
	}

	void StartInit(Scene* scene)
	{
		PlayerHP = PlayerMaxHP;

		ShipDamageParticle = ParticleSystemQuad::create("Particle/Ship_Damage.plist");
		scene->addChild(ShipDamageParticle, 1);
		ShipDamageParticle->setScale(0.2);
		ShipDamageParticle->setPosition(-1000, -1000);

		BackgroundStarsS_01 = Sprite::create("AddedImages/Stars_01.png");
		scene->addChild(BackgroundStarsS_01, 0);
		BackgroundStarsS_01->setPosition(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height / 2);
		BackgroundStarsS_01->setScale(2);
		BackgroundStarsS_01->addComponent(VelocityComponent::create(Vec2(0, -2), 2));
		BackgroundStarsS_01->setOpacity(150);

		BackgroundStarsS_02 = Sprite::create("AddedImages/Stars_01.png");
		scene->addChild(BackgroundStarsS_02, 0);
		BackgroundStarsS_02->setPosition(BackgroundStarsS_01->getPositionX(), BackgroundStarsS_01->getPositionY() + BackgroundStarsS_01->getContentSize().height);
		BackgroundStarsS_02->setScale(2);
		BackgroundStarsS_02->addComponent(VelocityComponent::create(Vec2(0, -2), 2));
		BackgroundStarsS_02->setOpacity(150);

		BackgroundStarsL_01 = Sprite::create("AddedImages/Stars_02.png");
		scene->addChild(BackgroundStarsL_01, -1);
		BackgroundStarsL_01->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, Director::getInstance()->getVisibleSize().height/3 );
		BackgroundStarsL_01->setScale(1.25);
		BackgroundStarsL_01->addComponent(VelocityComponent::create(Vec2(0, -10), 10));
	

		BackgroundStarsL_02 = Sprite::create("AddedImages/Stars_02.png");
		scene->addChild(BackgroundStarsL_02, -1);
		BackgroundStarsL_02->setPosition(BackgroundStarsL_01->getPositionX(), BackgroundStarsL_01->getPositionY() + BackgroundStarsL_01->getContentSize().height);
		BackgroundStarsL_02->setScale(1.25);
		BackgroundStarsL_02->addComponent(VelocityComponent::create(Vec2(0, -10), 10));


		Ship1Up = Sprite::create("carrier_01.png");
		//Ship1Up->setVisible(false);
		scene->addChild(Ship1Up, 5);
		Ship2 = Sprite::create("carrier_02.png");
		Ship2->setVisible(false);
		scene->addChild(Ship2, 5);
		Ship3 = Sprite::create("carrier_03.png");
		Ship3->setVisible(false);
		scene->addChild(Ship3, 5);
		Ship4 = Sprite::create("carrier_04.png");
		Ship4->setVisible(false);
		scene->addChild(Ship4, 5);
		Ship5 = Sprite::create("carrier_05.png");
		Ship5->setVisible(false);
		scene->addChild(Ship5, 5);
		Ship6 = Sprite::create("carrier_06.png");
		Ship6->setVisible(false);
		scene->addChild(Ship6, 5);
		Ship7 = Sprite::create("carrier_07.png");
		Ship7->setVisible(false);
		scene->addChild(Ship7, 5);
		Ship8 = Sprite::create("carrier_08.png");
		Ship8->setVisible(false);
		scene->addChild(Ship8, 5);

		Ship9Right = Sprite::create("carrier_09.png");
		Ship9Right->setVisible(false);
		scene->addChild(Ship9Right, 5);
		Ship10 = Sprite::create("carrier_10.png");
		Ship10->setVisible(false);
		scene->addChild(Ship10, 5);
		Ship11 = Sprite::create("carrier_11.png");
		Ship11->setVisible(false);
		scene->addChild(Ship11, 5);
		Ship12 = Sprite::create("carrier_12.png");
		Ship12->setVisible(false);
		scene->addChild(Ship12, 5);
		Ship13 = Sprite::create("carrier_13.png");
		Ship13->setVisible(false);
		scene->addChild(Ship13, 5);
		Ship14 = Sprite::create("carrier_14.png");
		Ship14->setVisible(false);
		scene->addChild(Ship14, 5);
		Ship15 = Sprite::create("carrier_15.png");
		Ship15->setVisible(false);
		scene->addChild(Ship15, 5);
		Ship16 = Sprite::create("carrier_16.png");
		Ship16->setVisible(false);
		scene->addChild(Ship16, 5);

		Ship17Down = Sprite::create("carrier_17.png");
		Ship17Down->setVisible(false);
		scene->addChild(Ship17Down, 5);
		Ship18 = Sprite::create("carrier_18.png");
		Ship18->setVisible(false);
		scene->addChild(Ship18, 5);
		Ship19 = Sprite::create("carrier_19.png");
		Ship19->setVisible(false);
		scene->addChild(Ship19, 5);
		Ship20 = Sprite::create("carrier_20.png");
		Ship20->setVisible(false);
		scene->addChild(Ship20, 5);
		Ship21 = Sprite::create("carrier_21.png");
		Ship21->setVisible(false);
		scene->addChild(Ship21, 5);
		Ship22 = Sprite::create("carrier_22.png");
		Ship22->setVisible(false);
		scene->addChild(Ship22, 5);
		Ship23 = Sprite::create("carrier_23.png");
		Ship23->setVisible(false);
		scene->addChild(Ship23, 5);
		Ship24 = Sprite::create("carrier_24.png");
		Ship24->setVisible(false);
		scene->addChild(Ship24, 5);

		Ship25Left = Sprite::create("carrier_25.png");
		Ship25Left->setVisible(false);
		scene->addChild(Ship25Left, 5);
		Ship26 = Sprite::create("carrier_26.png");
		Ship26->setVisible(false);
		scene->addChild(Ship26, 5);
		Ship27 = Sprite::create("carrier_27.png");
		Ship27->setVisible(false);
		scene->addChild(Ship27, 5);
		Ship28 = Sprite::create("carrier_28.png");
		Ship28->setVisible(false);
		scene->addChild(Ship28, 5);
		Ship29 = Sprite::create("carrier_29.png");
		Ship29->setVisible(false);
		scene->addChild(Ship29, 5);
		Ship30 = Sprite::create("carrier_30.png");
		Ship30->setVisible(false);
		scene->addChild(Ship30, 5);
		Ship31 = Sprite::create("carrier_31.png");
		Ship31->setVisible(false);
		scene->addChild(Ship31, 5);
		Ship32 = Sprite::create("carrier_32.png");
		Ship32->setVisible(false);
		scene->addChild(Ship32, 5);


		SpaceShipSprite = Ship1Up;

		keyboard = KeyboardControllerComponent::create(0);
		SpaceShip = Sprite::create("carrier_01.png");
		SpaceShip->setVisible(false);
		scene->addChild(SpaceShip, 2);
		SpaceShip->addComponent(keyboard);
		SpaceShip->addComponent(CollisionComponent::createCircle((SpaceShip->getContentSize().height) / 4));
		SpaceShip->setName("Player");
		SpaceShip->setPosition(Director::getInstance()->getVisibleSize().width /2, Director::getInstance()->getVisibleSize().height / 2);
		PlayerPosition = SpaceShip->getPosition();




		 VelocityBarN = Sprite::create("AddedImages/Hollow_Bar.png");
		 scene->addChild(VelocityBarN, 10);
		 VelocityBarN->setScaleY(0.75);

		 VelocityBarS = Sprite::create("AddedImages/Hollow_Bar.png");
		 scene->addChild(VelocityBarS, 10);
		 VelocityBarS->setScaleY(0.75);

		 VelocityBarE = Sprite::create("AddedImages/Hollow_Bar.png");
		 scene->addChild(VelocityBarE, 10);
		 VelocityBarE->setScaleY(0.75);

		 VelocityBarW = Sprite::create("AddedImages/Hollow_Bar.png");
		 scene->addChild(VelocityBarW, 10);
		 VelocityBarW->setScaleY(0.75);

		 VelArrowE_01 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_01, 10);
		 VelArrowE_01->setRotation(-90);
		 VelArrowE_01->setScaleX(1.5);
		 VelArrowE_02 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_02, 10);
		 VelArrowE_02->setRotation(-90);
		 VelArrowE_02->setScaleX(1.5);
		 VelArrowE_03 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_03, 10);
		 VelArrowE_03->setRotation(-90);
		 VelArrowE_03->setScaleX(1.5);
		 VelArrowE_04 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_04, 10);
		 VelArrowE_04->setRotation(-90);
		 VelArrowE_04->setScaleX(1.5);
		 VelArrowE_05 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_05, 10);
		 VelArrowE_05->setRotation(-90);
		 VelArrowE_05->setScaleX(1.5);
		 VelArrowE_06 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_06, 10);
		 VelArrowE_06->setRotation(-90);
		 VelArrowE_06->setScaleX(1.5);
		 VelArrowE_07 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_07, 10);
		 VelArrowE_07->setRotation(-90);
		 VelArrowE_07->setScaleX(1.5);
		 VelArrowE_08 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_08, 10);
		 VelArrowE_08->setRotation(-90);
		 VelArrowE_08->setScaleX(1.5);
		 VelArrowE_09 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_09, 10);
		 VelArrowE_09->setRotation(-90);
		 VelArrowE_09->setScaleX(1.5);
		 VelArrowE_10 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowE_10, 10);
		 VelArrowE_10->setRotation(-90);
		 VelArrowE_10->setScaleX(1.5);



		 VelArrowS_01 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_01, 10);
		 VelArrowS_01->setRotation(-90);
		 VelArrowS_01->setScaleX(1.5);
		 VelArrowS_02 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_02, 10);
		 VelArrowS_02->setRotation(-90);
		 VelArrowS_02->setScaleX(1.5);
		 VelArrowS_03 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_03, 10);
		 VelArrowS_03->setRotation(-90);
		 VelArrowS_03->setScaleX(1.5);
		 VelArrowS_04 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_04, 10);
		 VelArrowS_04->setRotation(-90);
		 VelArrowS_04->setScaleX(1.5);
		 VelArrowS_05 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_05, 10);
		 VelArrowS_05->setRotation(-90);
		 VelArrowS_05->setScaleX(1.5);
		 VelArrowS_06 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_06, 10);
		 VelArrowS_06->setRotation(-90);
		 VelArrowS_06->setScaleX(1.5);
		 VelArrowS_07 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_07, 10);
		 VelArrowS_07->setRotation(-90);
		 VelArrowS_07->setScaleX(1.5);
		 VelArrowS_08 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_08, 10);
		 VelArrowS_08->setRotation(-90);
		 VelArrowS_08->setScaleX(1.5);
		 VelArrowS_09 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_09, 10);
		 VelArrowS_09->setRotation(-90);
		 VelArrowS_09->setScaleX(1.5);
		 VelArrowS_10 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowS_10, 10);
		 VelArrowS_10->setRotation(-90);
		 VelArrowS_10->setScaleX(1.5);


		 VelArrowN_01 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_01, 10);
		 VelArrowN_01->setRotation(-90);
		 VelArrowN_01->setScaleX(1.5);
		 VelArrowN_02 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_02, 10);
		 VelArrowN_02->setRotation(-90);
		 VelArrowN_02->setScaleX(1.5);
		 VelArrowN_03 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_03, 10);
		 VelArrowN_03->setRotation(-90);
		 VelArrowN_03->setScaleX(1.5);
		 VelArrowN_04 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_04, 10);
		 VelArrowN_04->setRotation(-90);
		 VelArrowN_04->setScaleX(1.5);
		 VelArrowN_05 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_05, 10);
		 VelArrowN_05->setRotation(-90);
		 VelArrowN_05->setScaleX(1.5);
		 VelArrowN_06 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_06, 10);
		 VelArrowN_06->setRotation(-90);
		 VelArrowN_06->setScaleX(1.5);
		 VelArrowN_07 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_07, 10);
		 VelArrowN_07->setRotation(-90);
		 VelArrowN_07->setScaleX(1.5);
		 VelArrowN_08 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_08, 10);
		 VelArrowN_08->setRotation(-90);
		 VelArrowN_08->setScaleX(1.5);
		 VelArrowN_09 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_09, 10);
		 VelArrowN_09->setRotation(-90);
		 VelArrowN_09->setScaleX(1.5);
		 VelArrowN_10 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowN_10, 10);
		 VelArrowN_10->setRotation(-90);
		 VelArrowN_10->setScaleX(1.5);

		 VelArrowW_01 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_01, 10);
		 VelArrowW_01->setRotation(-90);
		 VelArrowW_01->setScaleX(1.5);
		 VelArrowW_02 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_02, 10);
		 VelArrowW_02->setRotation(-90);
		 VelArrowW_02->setScaleX(1.5);
		 VelArrowW_03 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_03, 10);
		 VelArrowW_03->setRotation(-90);
		 VelArrowW_03->setScaleX(1.5);
		 VelArrowW_04 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_04, 10);
		 VelArrowW_04->setRotation(-90);
		 VelArrowW_04->setScaleX(1.5);
		 VelArrowW_05 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_05, 10);
		 VelArrowW_05->setRotation(-90);
		 VelArrowW_05->setScaleX(1.5);
		 VelArrowW_06 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_06, 10);
		 VelArrowW_06->setRotation(-90);
		 VelArrowW_06->setScaleX(1.5);
		 VelArrowW_07 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_07, 10);
		 VelArrowW_07->setRotation(-90);
		 VelArrowW_07->setScaleX(1.5);
		 VelArrowW_08 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_08, 10);
		 VelArrowW_08->setRotation(-90);
		 VelArrowW_08->setScaleX(1.5);
		 VelArrowW_09 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_09, 10);
		 VelArrowW_09->setRotation(-90);
		 VelArrowW_09->setScaleX(1.5);
		 VelArrowW_10 = Sprite::create("AddedImages/FullArrow.png");
		 scene->addChild(VelArrowW_10, 10);
		 VelArrowW_10->setRotation(-90);
		 VelArrowW_10->setScaleX(1.5);


		debug = DrawNode::create(5);
		scene->addChild(debug, 5);


		DashTimerTxt = Label::create();
		scene->addChild(DashTimerTxt, 2);
		DashTimerTxt->setScale(2);
		DashTimerTxt->setPosition(100, 100);
	}


	void changeActiveSprite(Sprite* newActive)
	{
		SpaceShipSprite->setVisible(false);
		SpaceShipSprite = newActive;
		SpaceShipSprite->setVisible(true);
	}


	void MovementAndHud(float dt, Scene* scene)
	{
		if (sceneState == death)
		{
			//play explosion anim
			SpaceShip->removeAllComponents();

			ShipVelocity = Vec2(0, 0);

		}
		else
		{
			//timer and string
			//string toString = to_string(round((DashTimer * 1000)) / 1000);							//change to ui later
			//DashTimerTxt->setString("Cooldown " + toString);
			//DashTimerTxt->setPosition(SpaceShip->getPosition() + CooldownOffset);


			//limiter
			if (ShipVelocity.x > SpeedLimiter)
			{
				ShipVelocity.x -= DecelerationSpeed;
				
			}
			else if (ShipVelocity.x < (SpeedLimiter * -1))
			{
				ShipVelocity.x += DecelerationSpeed;
			}
			if (ShipVelocity.y > SpeedLimiter)
			{
				ShipVelocity.y -= DecelerationSpeed;
			}
			else if (ShipVelocity.y < (SpeedLimiter * -1))
			{
				ShipVelocity.y += DecelerationSpeed;
			}



			//super complex and cool sprite change shtuff, very cool and things and yeah!

			if (ShipVelocity.y > 0)
			{
				//up 
				if (ShipVelocity.y / ShipVelocity.x > 10 || ShipVelocity.x == 0)
				{
					changeActiveSprite(Ship1Up);
				}
				else if (ShipVelocity.y / ShipVelocity.x > 6)
				{
					changeActiveSprite(Ship2);
				}
				else if (ShipVelocity.y / ShipVelocity.x > 4)
				{
					changeActiveSprite(Ship3);
				}
				else if (ShipVelocity.y / ShipVelocity.x >= 2)
				{
					changeActiveSprite(Ship4);
				}
				//up right
				else if (ShipVelocity.y / ShipVelocity.x > 0.8)
				{
					changeActiveSprite(Ship5);
				}
				else if (ShipVelocity.y / ShipVelocity.x > 0.6)
				{
					changeActiveSprite(Ship6);
				}
				else if (ShipVelocity.y / ShipVelocity.x > 0.4)
				{
					changeActiveSprite(Ship7);
				}
				else if (ShipVelocity.y / ShipVelocity.x > 0.2)
				{
					changeActiveSprite(Ship8);
				}



				if (ShipVelocity.x < 0)
				{
					if (ShipVelocity.y / ShipVelocity.x > -0.2)
					{
						changeActiveSprite(Ship26);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -0.4)
					{
						changeActiveSprite(Ship27);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -0.6)
					{
						changeActiveSprite(Ship28);
					}
					//up left
					else if (ShipVelocity.y / ShipVelocity.x > -0.8)
					{
						changeActiveSprite(Ship29);
					}
					else if (ShipVelocity.y / ShipVelocity.x >= -2)
					{
						changeActiveSprite(Ship30);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -4)
					{
						changeActiveSprite(Ship31);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -6)
					{
						changeActiveSprite(Ship32);
					}
				}
			}
			else
			{
				//Left
				if (ShipVelocity.y == 0 && ShipVelocity.x < 0)
				{
					changeActiveSprite(Ship25Left);
				}
				//right
				else if (ShipVelocity.y == 0 && ShipVelocity.x > 0)
				{
					changeActiveSprite(Ship9Right);
				}

				if (ShipVelocity.x <= 0)
				{
					//Down
					if (ShipVelocity.y / ShipVelocity.x < -10 || ShipVelocity.x == 0)
					{
						changeActiveSprite(Ship17Down);
					}
					if (ShipVelocity.y / ShipVelocity.x > 6)
					{
						changeActiveSprite(Ship18);
					}
					else if (ShipVelocity.y / ShipVelocity.x > 4)
					{
						changeActiveSprite(Ship19);
					}
					else if (ShipVelocity.y / ShipVelocity.x >= 2)
					{
						changeActiveSprite(Ship20);
					}
					//down left
					else if (ShipVelocity.y / ShipVelocity.x > 0.8)
					{
						changeActiveSprite(Ship21);
					}
					else if (ShipVelocity.y / ShipVelocity.x > 0.6)
					{
						changeActiveSprite(Ship22);
					}
					else if (ShipVelocity.y / ShipVelocity.x > 0.4)
					{
						changeActiveSprite(Ship23);
					}
					else if (ShipVelocity.y / ShipVelocity.x > 0.2)
					{
						changeActiveSprite(Ship24);
					}
				}
				else
				{
					if (ShipVelocity.y / ShipVelocity.x > -0.2)
					{
						changeActiveSprite(Ship10);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -0.4)
					{
						changeActiveSprite(Ship11);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -0.6)
					{
						changeActiveSprite(Ship12);
					}
					//down right
					else if (ShipVelocity.y / ShipVelocity.x > -0.8)
					{
						changeActiveSprite(Ship13);
					}
					else if (ShipVelocity.y / ShipVelocity.x >= -2)
					{
						changeActiveSprite(Ship14);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -4)
					{
						changeActiveSprite(Ship15);
					}
					else if (ShipVelocity.y / ShipVelocity.x > -6)
					{
						changeActiveSprite(Ship16);
					}
				}
			}




			//movment
			SpaceShip->setPosition(SpaceShip->getPosition() + (ShipVelocity * dt));
			SpaceShipSprite->setPosition(SpaceShip->getPosition());

			if (keyboard->IsRightPressed())
			{
				ShipVelocity += Vec2(ShipSpeed, 0);
			}
			if (keyboard->IsLeftPressed())
			{
				ShipVelocity += Vec2(-ShipSpeed, 0);
			}
			if (keyboard->IsDownPressed())
			{
				ShipVelocity += Vec2(0, -ShipSpeed);
			}
			if (keyboard->IsUpPressed())
			{
				ShipVelocity += Vec2(0, ShipSpeed);
			}
			//dash
			if (keyboard->IsFirePressed() && DashTimer <= 0)
			{
				//up and right
				if (keyboard->IsUpPressed() && keyboard->IsRightPressed())
				{
					ShipVelocity = Vec2(DiagonalDashSpeed, DiagonalDashSpeed);
					DashTimer = DashCooldown;
				}
				//up and left
				else if (keyboard->IsUpPressed() && keyboard->IsLeftPressed())
				{
					ShipVelocity = Vec2(-DiagonalDashSpeed, DiagonalDashSpeed);
					DashTimer = DashCooldown;
				}
				//down left
				else if (keyboard->IsDownPressed() && keyboard->IsLeftPressed())
				{
					ShipVelocity = Vec2(-DiagonalDashSpeed, -DiagonalDashSpeed);
					DashTimer = DashCooldown;
				}
				//down right
				else if (keyboard->IsDownPressed() && keyboard->IsRightPressed())
				{
					ShipVelocity = Vec2(DiagonalDashSpeed, -DiagonalDashSpeed);
					DashTimer = DashCooldown;
				}

				//down
				else if (keyboard->IsDownPressed())
				{
					ShipVelocity = Vec2(0, -DashSpeed);
					DashTimer = DashCooldown;
				}
				//up
				else if (keyboard->IsUpPressed())
				{
					ShipVelocity = Vec2(0, DashSpeed);
					DashTimer = DashCooldown;
				}
				//right
				else if (keyboard->IsRightPressed())
				{
					ShipVelocity = Vec2(DashSpeed, 0);
					DashTimer = DashCooldown;
				}
				//left
				else if (keyboard->IsLeftPressed())
				{
					ShipVelocity = Vec2(-DashSpeed, 0);
					DashTimer = DashCooldown;
				}

			}
			//timer
			if (DashTimer >= 0)
			{
				DashTimer -= (1 * dt);
			}
			if (InvincibilityFrames >= 0)																		//////////timers
			{
				InvincibilityFrames -= (1 * dt);
				SpaceShipSprite->setOpacity(100);
			}
			else
			{
				SpaceShipSprite->setOpacity(500);
			}


			//paralax


			if (SpaceShip->getPosition().y > BackgroundStarsL_01->getPosition().y)
			{
				BackgroundStarsL_02->setPositionY(BackgroundStarsL_01->getPositionY() + BackgroundStarsL_01->getContentSize().height);
			}
			else if (SpaceShip->getPosition().y < BackgroundStarsL_01->getPosition().y)
			{
				BackgroundStarsL_02->setPositionY(BackgroundStarsL_01->getPositionY() - BackgroundStarsL_01->getContentSize().height);
			}
			if (SpaceShip->getPosition().y > BackgroundStarsL_02->getPosition().y)
			{
				BackgroundStarsL_01->setPositionY(BackgroundStarsL_02->getPositionY() + BackgroundStarsL_02->getContentSize().height);
			}
			else if (SpaceShip->getPosition().y < BackgroundStarsL_02->getPosition().y)
			{
				BackgroundStarsL_01->setPositionY(BackgroundStarsL_02->getPositionY() - BackgroundStarsL_02->getContentSize().height);
			}

			if (SpaceShip->getPosition().y > BackgroundStarsS_01->getPosition().y)
			{
				BackgroundStarsS_02->setPositionY(BackgroundStarsS_01->getPositionY() + BackgroundStarsS_01->getContentSize().height * 2);
			}
			else if (SpaceShip->getPosition().y < BackgroundStarsS_01->getPosition().y)
			{
				BackgroundStarsS_02->setPositionY(BackgroundStarsS_01->getPositionY() - BackgroundStarsS_01->getContentSize().height * 2);
			}
			if (SpaceShip->getPosition().y > BackgroundStarsS_02->getPosition().y)
			{
				BackgroundStarsS_01->setPositionY(BackgroundStarsS_02->getPositionY() + BackgroundStarsS_02->getContentSize().height * 2);
			}
			else if (SpaceShip->getPosition().y < BackgroundStarsS_02->getPosition().y)
			{
				BackgroundStarsS_01->setPositionY(BackgroundStarsS_02->getPositionY() - BackgroundStarsS_02->getContentSize().height * 2);
			}


			
			/////// Spaceship HUD

			VelocityBarW->setPosition(scene->getDefaultCamera()->getPosition() + UIOffset );
			VelocityBarN->setPosition(VelocityBarW->getPositionX() + NextUI, VelocityBarW->getPositionY());
			VelocityBarS->setPosition(VelocityBarN->getPositionX() + NextUI, VelocityBarN->getPositionY());
			VelocityBarE->setPosition(VelocityBarS->getPositionX() + NextUI, VelocityBarS->getPositionY());

			VelArrowE_01->setPosition(VelocityBarE->getPositionX(), VelocityBarE->getPositionY() - StartArrowOffset);
			VelArrowE_02->setPosition(VelArrowE_01->getPositionX(), VelArrowE_01->getPositionY() + ArrowOffset);
			VelArrowE_03->setPosition(VelArrowE_02->getPositionX(), VelArrowE_02->getPositionY() + ArrowOffset);
			VelArrowE_04->setPosition(VelArrowE_03->getPositionX(), VelArrowE_03->getPositionY() + ArrowOffset);
			VelArrowE_05->setPosition(VelArrowE_04->getPositionX(), VelArrowE_04->getPositionY() + ArrowOffset);
			VelArrowE_06->setPosition(VelArrowE_05->getPositionX(), VelArrowE_05->getPositionY() + ArrowOffset);
			VelArrowE_07->setPosition(VelArrowE_06->getPositionX(), VelArrowE_06->getPositionY() + ArrowOffset);
			VelArrowE_08->setPosition(VelArrowE_07->getPositionX(), VelArrowE_07->getPositionY() + ArrowOffset);
			VelArrowE_09->setPosition(VelArrowE_08->getPositionX(), VelArrowE_08->getPositionY() + ArrowOffset);
			VelArrowE_10->setPosition(VelArrowE_09->getPositionX(), VelArrowE_09->getPositionY() + ArrowOffset);

			VelArrowN_01->setPosition(VelocityBarN->getPositionX(), VelocityBarN->getPositionY() - StartArrowOffset);
			VelArrowN_02->setPosition(VelArrowN_01->getPositionX(), VelArrowN_01->getPositionY() + ArrowOffset);
			VelArrowN_03->setPosition(VelArrowN_02->getPositionX(), VelArrowN_02->getPositionY() + ArrowOffset);
			VelArrowN_04->setPosition(VelArrowN_03->getPositionX(), VelArrowN_03->getPositionY() + ArrowOffset);
			VelArrowN_05->setPosition(VelArrowN_04->getPositionX(), VelArrowN_04->getPositionY() + ArrowOffset);
			VelArrowN_06->setPosition(VelArrowN_05->getPositionX(), VelArrowN_05->getPositionY() + ArrowOffset);
			VelArrowN_07->setPosition(VelArrowN_06->getPositionX(), VelArrowN_06->getPositionY() + ArrowOffset);
			VelArrowN_08->setPosition(VelArrowN_07->getPositionX(), VelArrowN_07->getPositionY() + ArrowOffset);
			VelArrowN_09->setPosition(VelArrowN_08->getPositionX(), VelArrowN_08->getPositionY() + ArrowOffset);
			VelArrowN_10->setPosition(VelArrowN_09->getPositionX(), VelArrowN_09->getPositionY() + ArrowOffset);

			VelArrowS_01->setPosition(VelocityBarS->getPositionX(), VelocityBarS->getPositionY() - StartArrowOffset);
			VelArrowS_02->setPosition(VelArrowS_01->getPositionX(), VelArrowS_01->getPositionY() + ArrowOffset);
			VelArrowS_03->setPosition(VelArrowS_02->getPositionX(), VelArrowS_02->getPositionY() + ArrowOffset);
			VelArrowS_04->setPosition(VelArrowS_03->getPositionX(), VelArrowS_03->getPositionY() + ArrowOffset);
			VelArrowS_05->setPosition(VelArrowS_04->getPositionX(), VelArrowS_04->getPositionY() + ArrowOffset);
			VelArrowS_06->setPosition(VelArrowS_05->getPositionX(), VelArrowS_05->getPositionY() + ArrowOffset);
			VelArrowS_07->setPosition(VelArrowS_06->getPositionX(), VelArrowS_06->getPositionY() + ArrowOffset);
			VelArrowS_08->setPosition(VelArrowS_07->getPositionX(), VelArrowS_07->getPositionY() + ArrowOffset);
			VelArrowS_09->setPosition(VelArrowS_08->getPositionX(), VelArrowS_08->getPositionY() + ArrowOffset);
			VelArrowS_10->setPosition(VelArrowS_09->getPositionX(), VelArrowS_09->getPositionY() + ArrowOffset);

			VelArrowW_01->setPosition(VelocityBarW->getPositionX(), VelocityBarW->getPositionY() - StartArrowOffset);
			VelArrowW_02->setPosition(VelArrowW_01->getPositionX(), VelArrowW_01->getPositionY() + ArrowOffset);
			VelArrowW_03->setPosition(VelArrowW_02->getPositionX(), VelArrowW_02->getPositionY() + ArrowOffset);
			VelArrowW_04->setPosition(VelArrowW_03->getPositionX(), VelArrowW_03->getPositionY() + ArrowOffset);
			VelArrowW_05->setPosition(VelArrowW_04->getPositionX(), VelArrowW_04->getPositionY() + ArrowOffset);
			VelArrowW_06->setPosition(VelArrowW_05->getPositionX(), VelArrowW_05->getPositionY() + ArrowOffset);
			VelArrowW_07->setPosition(VelArrowW_06->getPositionX(), VelArrowW_06->getPositionY() + ArrowOffset);
			VelArrowW_08->setPosition(VelArrowW_07->getPositionX(), VelArrowW_07->getPositionY() + ArrowOffset);
			VelArrowW_09->setPosition(VelArrowW_08->getPositionX(), VelArrowW_08->getPositionY() + ArrowOffset);
			VelArrowW_10->setPosition(VelArrowW_09->getPositionX(), VelArrowW_09->getPositionY() + ArrowOffset);

			// N
			HudVelocity(ShipVelocity.y, VelArrowN_01, VelArrowN_02, VelArrowN_03, VelArrowN_04, VelArrowN_05, VelArrowN_06, VelArrowN_07, VelArrowN_08, VelArrowN_09, VelArrowN_10);
			HudVelocity(ShipVelocity.y * -1, VelArrowS_01, VelArrowS_02, VelArrowS_03, VelArrowS_04, VelArrowS_05, VelArrowS_06, VelArrowS_07, VelArrowS_08, VelArrowS_09, VelArrowS_10);
			HudVelocity(ShipVelocity.x * -1, VelArrowW_01, VelArrowW_02, VelArrowW_03, VelArrowW_04, VelArrowW_05, VelArrowW_06, VelArrowW_07, VelArrowW_08, VelArrowW_09, VelArrowW_10);
			HudVelocity(ShipVelocity.x, VelArrowE_01, VelArrowE_02, VelArrowE_03, VelArrowE_04, VelArrowE_05, VelArrowE_06, VelArrowE_07, VelArrowE_08, VelArrowE_09, VelArrowE_10);


			if (PlayerHP <= 0)
			{
				sceneState = death;
			}


		}
	}
   


	void CollisionAndDebug(Scene* scene)
	{
		if (keyboard->IsDebugPressed())
		{
			debugDrawEnabled = true;
		}
		else if (!keyboard->IsDebugPressed())
		{
			debugDrawEnabled = false;
		}

		auto& children = scene->getChildren();

		for (auto it : children)
		{
			if (auto collision = dynamic_cast<CollisionComponent*>(it->getComponent("CollisionComponent")))
			{
				collision->SetColliding(false);
			}
		}

		for (auto it = children.begin(); it != children.end(); it++)
		{
			auto collision = dynamic_cast<CollisionComponent*>((*it)->getComponent("CollisionComponent"));
				for (auto it2 = it + 1; it2 != children.end(); it2++)
				{
					auto other = dynamic_cast<CollisionComponent*>((*it2)->getComponent("CollisionComponent"));
					if (other != nullptr && collision != nullptr)
					{
						if (other->getOwner()->getName() == "Player")
						{
							if (collision->IsColliding(other))
							{

								if (collision->getOwner()->getName() == "LevelOne")
								{
									SwitchToLevelOne();															
								}
								else if (collision->getOwner()->getName() == "LevelTwo" && SpaceShip::getInstance()->LevelTwoLock == false)
								{
									SwitchToLevelTwo();															
								}
								else if (collision->getOwner()->getName() == "Trophy")
								{
									SwitchToTrophy();															
								}
								else if (collision->getOwner()->getName() == "LevelSelect")
								{
									SpaceShip::getInstance()->FirstPlay = false;
									if (SpaceShip::getInstance()->LevelOneTimeComp < SpaceShip::getInstance()->LevelOneTime)
									{
										SpaceShip::getInstance()->LevelOneTimeComp = SpaceShip::getInstance()->LevelOneTime;
										SpaceShip::getInstance()->LevelTwoLock = false;
									}
									
									if (SpaceShip::getInstance()->LevelTwoTimeComp < SpaceShip::getInstance()->LevelTwoTime)
										SpaceShip::getInstance()->LevelTwoTimeComp = SpaceShip::getInstance()->LevelTwoTime;

									SwitchToLevelSelect();
									
								}
								else if (collision->getOwner()->getName() == "Leave")
								{
									Director::getInstance()->end();
								}
								else if (collision->getOwner()->getName() == "Trigger")
								{
									collision->getOwner()->setName("Activated");
								}
								else if (collision->getOwner()->getName() == "FalseCollision")
								{ 

								}
								else if (collision->getOwner()->getName() == "Item1-1")
								{
									SpaceShip::getInstance()->HasLevelOneItem_01 = true;
									LevelOneItem_01->setVisible(false);
									LevelOneItem_01->setPosition(-1000, -1000);
								}
								else if (collision->getOwner()->getName() == "Item1-2")
								{
									SpaceShip::getInstance()->HasLevelOneItem_02 = true;
									LevelOneItem_02->setVisible(false);
									LevelOneItem_02->setPosition(-1000, -1000);
								}
								else if (collision->getOwner()->getName() == "Item2-1")
								{
									SpaceShip::getInstance()->HasLevelTwoItem_01 = true;
									LevelTwoItem_01->setVisible(false);
									LevelTwoItem_01->setPosition(-1000, -1000);
								}
								else if (collision->getOwner()->getName() == "Item2-2")
								{
									SpaceShip::getInstance()->HasLevelTwoItem_02 = true;
									LevelTwoItem_02->setVisible(false);
									LevelTwoItem_02->setPosition(-1000, -1000);
								}
								else 
								{
									/*if (SpaceShip->getPosition().x + SpaceShip->getContentSize().width /2 < collision->getOwner()->getPosition().x)
									{
										ShipVelocity.x *= -1;
									}
									else if (PlayerPosition.y > collision->getOwner()->getPosition().y)
									{
										ShipVelocity.y *= -1;
									}*/

									////IF ANCHOR IS MIDDLE

									//// top right									going down left
									//if (ShipVelocity.x < 0 && ShipVelocity.y < 0)
									//{
									//	if (collision->getOwner()->getPosition().x + (collision->getOwner()->getContentSize().width / 2) > SpaceShip->getPosition().x - SpaceShip->getContentSize().width / 2)
									//	{
									//		ShipVelocity.y *= -1;
									//	}
									//	else 
									//	ShipVelocity.x *= -1;
									//}
									////bottom right										going top left
									//else if (ShipVelocity.x < 0 && ShipVelocity.y > 0)
									//{
									//	if (collision->getOwner()->getPosition().x + (collision->getOwner()->getContentSize().width / 2) > SpaceShip->getPosition().x + SpaceShip->getContentSize().width / 2)
									//	{
									//		ShipVelocity.y *= -1;
									//	}
									//	else
									//		ShipVelocity.x *= -1;
									//}
									////bottom left									going top right
									//if (ShipVelocity.x > 0 && ShipVelocity.y > 0)
									//{
									//	if (collision->getOwner()->getPosition().x - (collision->getOwner()->getContentSize().width / 2) > SpaceShip->getPosition().x - SpaceShip->getContentSize().width / 2)
									//	{
									//		ShipVelocity.x *= -1;
									//	}
									//	else
									//		ShipVelocity.y *= -1;
									//}
									////top left									going bottom right
									//else if (ShipVelocity.x > 0 && ShipVelocity.y < 0)
									//{
									//	if (collision->getOwner()->getPosition().x - ((collision->getOwner()->getContentSize().width * collision->getOwner()->getScaleX()) / 2) > SpaceShip->getPosition().x + SpaceShip->getContentSize().width/2)
									//	{
									//		ShipVelocity.y *= -1;
									//		if (SpaceShip->getPosition().x > collision->getOwner()->getPosition().x)
									//		{
									//			Sprite* spritetest = Sprite::create("blue.jpg");
									//			scene->addChild(spritetest, 10);
									//			spritetest->setPosition(SpaceShip->getPosition());
									//		}
									//		
									//	}
									//	else
									//		ShipVelocity.x *= -1;
									//}
									//
									
									////anchor is bootom left

									//// top right									going bottom left
									//if (ShipVelocity.x < 0 && ShipVelocity.y < 0)
									//{
									//	if (collision->getOwner()->getPosition().x + collision->getOwner()->getContentSize().width * collision->getOwner()->getScaleX() > SpaceShip->getPosition().x + SpaceShip->getContentSize().width/2)
									//	{
									//		ShipVelocity.y *= -1;
									//	}
									//	else 
									//	ShipVelocity.x *= -1;
									//}
									////bottom right										going top left
									// if (ShipVelocity.x < 0 && ShipVelocity.y > 0)
									//{
									//	if (collision->getOwner()->getPosition().x + collision->getOwner()->getContentSize().width * collision->getOwner()->getScaleX() > SpaceShip->getPosition().x + SpaceShip->getContentSize().width / 2)
									//	{
									//		ShipVelocity.y *= -1;
									//	}
									//	else
									//		ShipVelocity.x *= -1;
									//}
									////bottom left									going top right
									//if (ShipVelocity.x > 0 && ShipVelocity.y > 0)
									//{
									//	if (collision->getOwner()->getPosition().x  > SpaceShip->getPosition().x + SpaceShip->getContentSize().width / 2)
									//	{
									//		ShipVelocity.x *= -1;
									//	}
									//	else
									//		ShipVelocity.y *= -1;
									//}
									////top left									going bottom right
									// if (ShipVelocity.x > 0 && ShipVelocity.y < 0)
									//{
									//	if (collision->getOwner()->getPosition().x > SpaceShip->getPosition().x + SpaceShip->getContentSize().width / 2)
									//	{
									//		ShipVelocity.y *= -1;
									//	}
									//	else
									//		ShipVelocity.x *= -1;
									//}

									/*else if (SpaceShip->getPosition().x + SpaceShip->getContentSize().width / 2 > collision->getOwner()->getPosition().x)
									{
										ShipVelocity.x *= -1;
									}*/


									


									Vec2 collisionNormal = SpaceShip->getPosition() - collision->getOwner()->getBoundingBox().size;
									 

									Vec2 Velocity = ShipVelocity;

									ShipVelocity.x *= (collisionNormal.x >= 0) ? -1.0f : 1.0f;			
									ShipVelocity.y *= (collisionNormal.y >= 0) ? -1.0f : 1.0f;

									/*ShipVelocity.x *= 0.8;
									ShipVelocity.y *= 0.8;*/

									if (collision->getOwner()->getName() == "Obstacle")
									{
										/*if (ShipVelocity.x == Velocity.x * -1 && ShipVelocity.y == Velocity.y * -1)		//create clear bounces here
										{
											ShipVelocity.y *= -1;
										}*/


										//if (ShipVelocity.y < 10 && ShipVelocity.y > -10)
										//{
										//	//ShipVelocity.x *= -1;
										//}
										if (Velocity.y + 10 > 0 && SpaceShip->getPosition().y < collision->getOwner()->getPosition().y)
										ShipVelocity.y += MovingObjectBounce;
										else if (Velocity.y - 10 <= 0)
											ShipVelocity.y = -MovingObjectBounce* 1.5;
										


									}

									
									if (sceneState == levelSelect || sceneState == trophy)
									{
										continue;
									}
									//take damage when bouncing
									if (InvincibilityFrames <= 0)
									{
										PlayerHP -= 20;
										ShipDamageParticle->setPosition(SpaceShip->getPosition());
										ShipDamageParticle->start();
										InvincibilityFrames = InvinciblilityLength;
									}
									return;		//stops bug that breaks collider when colliding with multiple objects
								}
								collision->SetColliding(true);
								other->SetColliding(true);
							}
						}
					}
			}
		}


		//debug
		debug->clear();
		debug->setLineWidth(5);

		if (debugDrawEnabled)
		{

			for (auto it : children)
			{
				auto collision = dynamic_cast<CollisionComponent*>(it->getComponent("CollisionComponent"));

				if (collision != NULL)
				{
					auto position = it->getPosition();

					auto color = collision->IsColliding() ? Color4F::RED : Color4F::GREEN;

					switch (collision->GetCollisionType())
					{
					case CollisionComponent::Box:
					{
						auto dx = collision->GetWidth() / 2.0f;
						auto dy = collision->GetHeight() / 2.0f;
						debug->drawRect(Vec2(position.x - dx, position.y + dy), Vec2(position.x + dx, position.y + dy), Vec2(position.x + dx, position.y - dy), Vec2(position.x - dx, position.y - dy), color);
					}
					break;
					case CollisionComponent::Circle:
					{
						auto radius = collision->GetRadius();
						debug->drawCircle(position, radius, 10, 360, false, color);
					}
					break;
					case CollisionComponent::Point:
						debug->drawDot(position, 3, color);
						break;
					}
				}
			}


		}
	}



	void HudVelocity(int Velocity, Sprite* Arrow_01, Sprite* Arrow_02, Sprite* Arrow_03, Sprite* Arrow_04, Sprite* Arrow_05, Sprite* Arrow_06, Sprite* Arrow_07, Sprite* Arrow_08, Sprite* Arrow_09, Sprite* Arrow_10)
	{
		if (Velocity >= SpeedLimiter)
		{
			Arrow_10->setVisible(true);
			Arrow_09->setVisible(true);
			Arrow_08->setVisible(true);
			Arrow_07->setVisible(true);
			Arrow_06->setVisible(true);
			Arrow_05->setVisible(true);
			Arrow_04->setVisible(true);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 1)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(true);
			Arrow_08->setVisible(true);
			Arrow_07->setVisible(true);
			Arrow_06->setVisible(true);
			Arrow_05->setVisible(true);
			Arrow_04->setVisible(true);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 2)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(true);
			Arrow_07->setVisible(true);
			Arrow_06->setVisible(true);
			Arrow_05->setVisible(true);
			Arrow_04->setVisible(true);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 3)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(true);
			Arrow_06->setVisible(true);
			Arrow_05->setVisible(true);
			Arrow_04->setVisible(true);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 4)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(false);
			Arrow_06->setVisible(true);
			Arrow_05->setVisible(true);
			Arrow_04->setVisible(true);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 5)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(false);
			Arrow_06->setVisible(false);
			Arrow_05->setVisible(true);
			Arrow_04->setVisible(true);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 6)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(false);
			Arrow_06->setVisible(false);
			Arrow_05->setVisible(false);
			Arrow_04->setVisible(true);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 7)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(false);
			Arrow_06->setVisible(false);
			Arrow_05->setVisible(false);
			Arrow_04->setVisible(false);
			Arrow_03->setVisible(true);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 8)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(false);
			Arrow_06->setVisible(false);
			Arrow_05->setVisible(false);
			Arrow_04->setVisible(false);
			Arrow_03->setVisible(false);
			Arrow_02->setVisible(true);
			Arrow_01->setVisible(true);
		}
		else if (Velocity >= SpeedLimiter - (SpeedLimiter / 10) * 9)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(false);
			Arrow_06->setVisible(false);
			Arrow_05->setVisible(false);
			Arrow_04->setVisible(false);
			Arrow_03->setVisible(false);
			Arrow_02->setVisible(false);
			Arrow_01->setVisible(true);
		}

		else if (Velocity <= 0)
		{
			Arrow_10->setVisible(false);
			Arrow_09->setVisible(false);
			Arrow_08->setVisible(false);
			Arrow_07->setVisible(false);
			Arrow_06->setVisible(false);
			Arrow_05->setVisible(false);
			Arrow_04->setVisible(false);
			Arrow_03->setVisible(false);
			Arrow_02->setVisible(false);
			Arrow_01->setVisible(false);
		}

		


	}

	CREATE_FUNC(Final);

};

