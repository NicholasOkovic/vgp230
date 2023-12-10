#pragma once
#include "cocos2d.h"
#include "KeyboardControllerComponent.h"
#include "CollisionComponent.h"
#include "VelocityComponent.h"

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

	bool FirstPlay = true;



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

	Vec2 PlayerPosition;

	//offsets
	Vec2 CooldownOffset = Vec2(-250, -350);
	

	int PlayerHP = 100;
	int InvinciblilityLength = 1;
	float InvincibilityFrames = 0;

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



	Sprite* LevelOneCol;		//use for best time in trophy
	Sprite* LevelTwoCol;
	bool LevelTwoLock = true;
	
	
	int MovingObjectBounce = -100;


	Sprite* OOBTop;
	Sprite* OOBBottom;
	Sprite* OOBRight;
	Sprite* OOBLeft;
	int OOBScale = 15;
	int SideOOBScale = 13;

	KeyboardControllerComponent* keyboard;



	DrawNode* debug;
	bool debugDrawEnabled = false;


	Label* DashTimerTxt;



	Sprite* BackgroundStarsS_01;
	Sprite* BackgroundStarsS_02;
	Sprite* BackgroundStarsS_03;

	Sprite* BackgroundStarsL_01;
	Sprite* BackgroundStarsL_02;
	Sprite* BackgroundStarsL_03;
	

	void SwitchToLevelOne();
	void SwitchToLevelTwo();
	void SwitchToTrophy();




	void FirstPlayOff()
	{
		FirstPlay = false;
	}

	void StartInit(Scene* scene)
	{
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

		BackgroundStarsS_03 = Sprite::create("AddedImages/Stars_01.png");
		scene->addChild(BackgroundStarsS_03, 0);
		BackgroundStarsS_03->setPosition(BackgroundStarsS_02->getPositionX(), BackgroundStarsS_02->getPositionY() + BackgroundStarsS_02->getContentSize().height);
		BackgroundStarsS_03->setScale(2);
		BackgroundStarsS_03->addComponent(VelocityComponent::create(Vec2(0, -2), 2));
		BackgroundStarsS_03->setOpacity(150);

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


		BackgroundStarsL_03 = Sprite::create("AddedImages/Stars_02.png");
		scene->addChild(BackgroundStarsL_03, -1);
		BackgroundStarsL_03->setPosition(BackgroundStarsL_02->getPositionX(), BackgroundStarsL_02->getPositionY() + BackgroundStarsL_02->getContentSize().height);
		BackgroundStarsL_03->setScale(1.25);
		BackgroundStarsL_03->addComponent(VelocityComponent::create(Vec2(0, -10), 10));
		BackgroundStarsL_03->setRotation(180);

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
		SpaceShip->addComponent(CollisionComponent::createCircle((SpaceShip->getContentSize().height) / 3));
		SpaceShip->setName("Player");
		SpaceShip->setPosition(Director::getInstance()->getVisibleSize().width /2, Director::getInstance()->getVisibleSize().height / 2);
		PlayerPosition = SpaceShip->getPosition();


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


	void MovementAndHud(float dt)
	{
		
		//timer and string
		string toString = to_string(round((DashTimer*1000))/1000);							//change to ui later
		DashTimerTxt->setString("Cooldown " + toString);
		DashTimerTxt->setPosition(SpaceShip->getPosition() + CooldownOffset);


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
		if (InvincibilityFrames >= 0)
		{
			InvincibilityFrames -= (1 * dt);
			SpaceShipSprite->setOpacity(100);
		}
		else
		{
			SpaceShipSprite->setOpacity(500);
		}


		//paralax
		
		if (BackgroundStarsL_01->getPosition().y + BackgroundStarsL_01->getContentSize().height* BackgroundStarsL_01->getScaleY() < SpaceShip->getPosition().y)
		{
			BackgroundStarsL_01->setPositionY(BackgroundStarsL_03->getPositionY() + BackgroundStarsL_03->getContentSize().height * BackgroundStarsL_03->getScaleY());
		}
		if (BackgroundStarsL_02->getPosition().y + BackgroundStarsL_02->getContentSize().height * BackgroundStarsL_02->getScaleY() < SpaceShip->getPosition().y)
		{
			BackgroundStarsL_02->setPositionY(BackgroundStarsL_01->getPositionY() + BackgroundStarsL_01->getContentSize().height * BackgroundStarsL_01->getScaleY());
		}
		if (BackgroundStarsL_03->getPosition().y + BackgroundStarsL_03->getContentSize().height * BackgroundStarsL_03->getScaleY() < SpaceShip->getPosition().y)
		{
			BackgroundStarsL_03->setPositionY(BackgroundStarsL_02->getPositionY() + BackgroundStarsL_02->getContentSize().height * BackgroundStarsL_02->getScaleY());
		}
		if (BackgroundStarsS_01->getPosition().y + BackgroundStarsS_01->getContentSize().height * BackgroundStarsS_01->getScaleY() < SpaceShip->getPosition().y)
		{
			BackgroundStarsS_01->setPositionY(BackgroundStarsS_03->getPositionY() + BackgroundStarsS_03->getContentSize().height * BackgroundStarsS_03->getScaleY());
		}
		if (BackgroundStarsS_02->getPosition().y + BackgroundStarsS_02->getContentSize().height * BackgroundStarsS_02->getScaleY() < SpaceShip->getPosition().y)
		{
			BackgroundStarsS_02->setPositionY(BackgroundStarsS_01->getPositionY() + BackgroundStarsS_01->getContentSize().height * BackgroundStarsS_01->getScaleY());
		}
		if (BackgroundStarsS_03->getPosition().y + BackgroundStarsS_03->getContentSize().height * BackgroundStarsS_03->getScaleY() < SpaceShip->getPosition().y)
		{
			BackgroundStarsS_03->setPositionY(BackgroundStarsS_02->getPositionY() + BackgroundStarsS_02->getContentSize().height * BackgroundStarsS_02->getScaleY());
		}
		
	}

   
	//auto GetChildren(Scene* scene)
	//{
	//	auto children = scene->getChildren();

	//	Vector<Node*> testChildren;

	//	for (auto it : children)
	//	{
	//		auto map = dynamic_cast<TMXTiledMap*>(it);

	//		if (map != NULL)
	//		{
	//			int i = 0;
	//			++i;

	//			for (auto it2 : map->getChildren())
	//			{
	//				auto layer = static_cast<TMXLayer*>(it2);

	//				for (auto tile : layer->getChildren())
	//				{
	//					auto sprite = (Sprite*)tile;

	//					auto collision = dynamic_cast<CollisionComponent*>(sprite->getComponent("CollisionComponent"));
	//					if (collision != nullptr)
	//					{
	//						int i = 0;
	//						++i;
	//					}

	//					testChildren.pushBack(tile);
	//				}
	//			}
	//		}
	//	}
	//	for (auto it2 : testChildren)
	//	{
	//		children.pushBack(it2);
	//	}
	//	return testChildren;
	//}

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
								else if (collision->getOwner()->getName() == "LevelTwo" && LevelTwoLock == false)
								{
									SwitchToLevelTwo();															
								}
								else if (collision->getOwner()->getName() == "Trophy")
								{
									SwitchToTrophy();															
								}
								else if (collision->getOwner()->getName() == "Leave")
								{
									Director::getInstance()->end();
								}
								else 
								{
									Vec2 collisionNormal = SpaceShip->getPosition() - collision->getOwner()->getBoundingBox().size;
									//Vec2 collisionNormal = Vec2(SpaceShip->getPosition().getAngle() + collision->getOwner()->getPosition().getAngle(), SpaceShip->getPosition().getAngle() + collision->getOwner()->getPosition().getAngle());

									Vec2 Velocity = ShipVelocity;

									ShipVelocity.x *= (collisionNormal.x >= 0) ? -1.0f : 1.0f;
									ShipVelocity.y *= (collisionNormal.y >= 0) ? -1.0f : 1.0f;

									if (collision->getOwner()->getName() == "Obstacle")
									{
										if (ShipVelocity.x == Velocity.x * -1 && ShipVelocity.y == Velocity.y * -1)
										{
											ShipVelocity.y *= -1;
										}


										//if (ShipVelocity.y < 10 && ShipVelocity.y > -10)
										//{
										//	//ShipVelocity.x *= -1;
										//}
										if (Velocity.y/* + 10*/ > 0)
										ShipVelocity.y = MovingObjectBounce;
										if (Velocity.y/* - 10*/ <= 0)
											ShipVelocity.y = -MovingObjectBounce;
									}
									/*ShipVelocity.x *= (collisionNormal.x >= 0) ? -1.0f : 1.0f;
									ShipVelocity.y *= (collisionNormal.y >= 0) ? -1.0f : 1.0f;*/

									
									if (sceneState == levelSelect || sceneState == trophy)
									{
										continue;
									}
									//take damage when bouncing
									if (InvincibilityFrames <= 0)
									{
										PlayerHP -= 20;

										InvincibilityFrames = InvinciblilityLength;
									}
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



	CREATE_FUNC(Final);

};

