#include "Final.h"

Scene* Final::createScene()
{
	return Final::create();
}





/// what needs to get done \\\
/// 
/// changes sprite on direction going
/// get camera to folloow player but not horiz
/// make the player bouce off objects
/// add a menu
/// add level 1
/// add lvl 2
/// create healthbar



bool Final::init()
{
	Ship1Up = Sprite::create("carrier_01.png");
	Ship1Up->setVisible(false);
	this->addChild(Ship1Up, 1);
	Ship2 = Sprite::create("carrier_02.png");
	Ship2->setVisible(false);
	this->addChild(Ship2, 1);
	Ship3 = Sprite::create("carrier_03.png");
	//Ship3->setVisible(false);
	this->addChild(Ship3, 1);
	Ship4 = Sprite::create("carrier_04.png");
	Ship4->setVisible(false);
	this->addChild(Ship4, 1);
	Ship5 = Sprite::create("carrier_05.png");
	Ship5->setVisible(false);
	this->addChild(Ship5, 1);
	Ship6 = Sprite::create("carrier_06.png");
	Ship6->setVisible(false);
	this->addChild(Ship6, 1);
	Ship7 = Sprite::create("carrier_07.png");
	Ship7->setVisible(false);
	this->addChild(Ship7, 1);
	Ship8 = Sprite::create("carrier_08.png");
	Ship8->setVisible(false);
	this->addChild(Ship8, 1);
	
	Ship9Right = Sprite::create("carrier_09.png");
	Ship9Right->setVisible(false);
	this->addChild(Ship9Right, 1);
	Ship10 = Sprite::create("carrier_10.png");
	Ship10->setVisible(false);
	this->addChild(Ship10, 1);
	Ship11 = Sprite::create("carrier_11.png");
	Ship11->setVisible(false);
	this->addChild(Ship11, 1);
	Ship12 = Sprite::create("carrier_12.png");
	Ship12->setVisible(false);
	this->addChild(Ship12, 1);
	Ship13 = Sprite::create("carrier_13.png");
	Ship13->setVisible(false);
	this->addChild(Ship13, 1);
	Ship14 = Sprite::create("carrier_14.png");
	Ship14->setVisible(false);
	this->addChild(Ship14, 1);
	Ship15 = Sprite::create("carrier_15.png");
	Ship15->setVisible(false);
	this->addChild(Ship15, 1);
	Ship16 = Sprite::create("carrier_16.png");
	Ship16->setVisible(false);
	this->addChild(Ship16, 1);

	Ship17Down = Sprite::create("carrier_17.png");
	Ship17Down->setVisible(false);
	this->addChild(Ship17Down, 1);
	Ship18 = Sprite::create("carrier_18.png");
	Ship18->setVisible(false);
	this->addChild(Ship18, 1);
	Ship19 = Sprite::create("carrier_19.png");
	Ship19->setVisible(false);
	this->addChild(Ship19, 1);
	Ship20 = Sprite::create("carrier_20.png");
	Ship20->setVisible(false);
	this->addChild(Ship20, 1);
	Ship21 = Sprite::create("carrier_21.png");
	Ship21->setVisible(false);
	this->addChild(Ship21, 1);
	Ship22 = Sprite::create("carrier_22.png");
	Ship22->setVisible(false);
	this->addChild(Ship22, 1);
	Ship23 = Sprite::create("carrier_23.png");
	Ship23->setVisible(false);
	this->addChild(Ship23, 1);
	Ship24 = Sprite::create("carrier_24.png");
	Ship24->setVisible(false);
	this->addChild(Ship24, 1);

	Ship25Left = Sprite::create("carrier_25.png");
	Ship25Left->setVisible(false);
	this->addChild(Ship25Left, 1);
	Ship26 = Sprite::create("carrier_26.png");
	Ship26->setVisible(false);
	this->addChild(Ship26, 1);
	Ship27 = Sprite::create("carrier_27.png");
	Ship27->setVisible(false);
	this->addChild(Ship27, 1);
	Ship28 = Sprite::create("carrier_28.png");
	Ship28->setVisible(false);
	this->addChild(Ship28, 1);
	Ship29 = Sprite::create("carrier_29.png");
	Ship29->setVisible(false);
	this->addChild(Ship29, 1);
	Ship30 = Sprite::create("carrier_30.png");
	Ship30->setVisible(false);
	this->addChild(Ship30, 1);
	Ship31 = Sprite::create("carrier_31.png");
	Ship31->setVisible(false);
	this->addChild(Ship31, 1);
	Ship32 = Sprite::create("carrier_32.png");
	Ship32->setVisible(false);
	this->addChild(Ship32, 1);






	SpaceShipSprite = Ship3;

	keyboard = KeyboardControllerComponent::create(0);
	SpaceShip = Sprite::create("carrier_01.png");
	SpaceShip->setVisible(false);
	this->addChild(SpaceShip, 2);
	SpaceShip->addComponent(keyboard);
	SpaceShip->addComponent(CollisionComponent::createCircle((SpaceShip->getContentSize().height) / 3));
	SpaceShip->setName("Player");
	SpaceShip->setPosition(500, 500);






	LevelOneCol = Sprite::create("cheese.png");
	this->addChild(LevelOneCol, 1);
	LevelOneCol->addComponent(CollisionComponent::createCircle((LevelOneCol->getContentSize().height) / 2));
	LevelOneCol->setPosition(100, 400);
	LevelOneCol->setName("LevelOne");


	debug = DrawNode::create(5);
	this->addChild(debug, 5);


	DashTimerTxt = Label::create();
	this->addChild(DashTimerTxt, 2);
	DashTimerTxt->setScale(2);
	DashTimerTxt->setPosition(100, 100);

	keyboard->initInput();
	scheduleUpdate();
	return true;
};


void Final::update(float dt)
{
	//timer and string
	string toString = to_string(DashTimer);
	DashTimerTxt->setString("Cooldown " + toString);

	if (DashTimer != 0)
	{
		DashTimer -= (1 * dt);
	}

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
		else if ( ShipVelocity.y / ShipVelocity.x > 0.8)
		{
			changeActiveSprite(Ship5);
		}
		else if ( ShipVelocity.y / ShipVelocity.x > 0.6)
		{
			changeActiveSprite(Ship6);
		}
		else if ( ShipVelocity.y / ShipVelocity.x > 0.4)
		{
			changeActiveSprite(Ship7);
		}
		else if ( ShipVelocity.y / ShipVelocity.x > 0.2)
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
	if (keyboard->IsFirePressed() && DashTimer == 0)
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
	if (keyboard->IsDebugPressed())
	{
		debugDrawEnabled = true;
	}
	else if (!keyboard->IsDebugPressed())
	{
		debugDrawEnabled = false;
	}

	//collision component

	for (auto it : this->getChildren())
	{
		if (auto collision = dynamic_cast<CollisionComponent*>(it->getComponent("CollisionComponent")))
		{
			collision->SetColliding(false);
		}
	}

	auto& children = this->getChildren();

	for (auto it = children.begin(); it != children.end(); it++)
	{
		auto collision = dynamic_cast<CollisionComponent*>((*it)->getComponent("CollisionComponent"));
		if (collision != nullptr)
		{
			for (auto it2 = it + 1; it2 != children.end(); it2++)
			{
				auto other = dynamic_cast<CollisionComponent*>((*it2)->getComponent("CollisionComponent"));
				if (other != nullptr)
				{
					if (collision->IsColliding(other))
					{


						if (collision->getOwner()->getName() == "LevelOne")			//temp level switch teleport
						{
							SpaceShip->setPosition(1, 10);
							ShipVelocity = Vec2(0,0);
							
						}
						else if (other->getOwner()->getName() == "Player")
						{

							ShipVelocity *= -1;
						}

						//if (collision->GetCollisionType() == CollisionComponent::Point && other->getOwner()->getName() == "Meteor")		//if meteor colliding with bullet
						//{
						//	collision->getOwner()->setVisible(false);
						//	collision->getOwner()->setPosition(bulletInitPos);

						//	for (int i = 0; i < WaveControl->GetMeteors().size(); i++)
						//	{
						//		if (other->getOwner() == WaveControl->GetMeteors()[i].first)
						//		{
						//			WaveControl->DamageMeteor(bulletDamage, i);
						//		}
						//	}
						//}
						/*else if (collision->getOwner() == ship)
						{
							if (other->getOwner()->getName() == "Meteor")
							{
								healthBarHP->setScaleX(healthBarHP->getScaleX() - (meteorDamage * 0.01f));
								other->getOwner()->setVisible(false);
								other->getOwner()->setPosition(MaxBounds + MaxBounds);
							}
							else if (other->getOwner()->getName() == "Win")
							{
								gameState = victory;
							}
						}*/
						/*else if (other->getOwner() == ship)
						{
							if (collision->getOwner()->getName() == "SpeedBoost")
							{
								ShipVelocity += SpeedBoostAmount;
								collision->getOwner()->setVisible(false);
								collision->getOwner()->setPosition(MaxBounds + MaxBounds);
							}
							else if (collision->getOwner()->getName() == "WeaponBoost")
							{
								FireCooldown += WeaponBoostAmount;
								collision->getOwner()->setVisible(false);
								collision->getOwner()->setPosition(MaxBounds + MaxBounds);
							}
						}*/
						//else if (collision->GetCollisionType() == CollisionComponent::Box && other->getOwner()->getName() == "Meteor")		//if meteor colliding with bullet
						//{
						//	other->getOwner()->setVisible(false);
						//	other->getOwner()->setPosition(MaxBounds + MaxBounds);
						//	healthBarHP->setScaleX(healthBarHP->getScaleX() - (meteorDamage * 0.01f));
						//}
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

		for (auto it : this->getChildren())
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

};


void Final::changeActiveSprite(Sprite* newActive)
{
	SpaceShipSprite->setVisible(false);
	SpaceShipSprite = newActive;
	SpaceShipSprite->setVisible(true);
}
