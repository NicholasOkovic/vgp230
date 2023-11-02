#include "Assignment2.h"



Scene* Assignment2::createScene()
{
	return Assignment2::create();
}

void Assignment2::Wave1(float dt)
{
	//random numebr across x axis

	//auto iMeteor : Meteors
	int i = 0;


	while (baseMeteorTimer > 0)
	{
		if (baseMeteorTimer == 0)
		{
			Meteors[i].first->setPosition(100, 100 * i);
		}

		baseMeteorTimer -= (1 * dt);
	}
	/*for (auto iMeteor : Meteors)
	{

		iMeteor.first->setPosition();
		baseMeteorTimer
	}*/

	//Meteor
	

	
}


bool Assignment2::init()
{
	Bullets[0] = bullet01 = Sprite::create("bullet1.png");
	Bullets[1] = bullet02 = Sprite::create("bullet1.png");
	Bullets[2] = bullet03 = Sprite::create("bullet1.png");
	Bullets[3] = bullet04 = Sprite::create("bullet1.png");
	Bullets[4] = bullet05 = Sprite::create("bullet1.png"),
	Bullets[5] = bullet06 = Sprite::create("bullet1.png");
	Bullets[6] = bullet07 = Sprite::create("bullet1.png");
	Bullets[7] = bullet08 = Sprite::create("bullet1.png");
	Bullets[8] = bullet09 = Sprite::create("bullet1.png");
	Bullets[9] = bullet10 = Sprite::create("bullet1.png");
	Bullets[10] = bullet11 = Sprite::create("bullet1.png");
	Bullets[11] = bullet12 = Sprite::create("bullet1.png");
	Bullets[12] = bullet13 = Sprite::create("bullet1.png");
	Bullets[13] = bullet14 = Sprite::create("bullet1.png");
	Bullets[14] = bullet15 = Sprite::create("bullet1.png");
	Bullets[15] = bullet16 = Sprite::create("bullet1.png");
	Bullets[16] = bullet17 = Sprite::create("bullet1.png");
	Bullets[17] = bullet18 = Sprite::create("bullet1.png");
	Bullets[18] = bullet19 = Sprite::create("bullet1.png");
	Bullets[19] = bullet20 = Sprite::create("bullet1.png");

	for (int i = 0; i < BulletArraySize-1; i++)
	{
		this->addChild(Bullets[i], 1);
		Bullets[i]->addComponent(CollisionComponent::createDot());
		//Bullets[i]->addComponent(CollisionComponent::createCircle((Bullets[i]->getContentSize().height) / 2));
		Bullets[i]->addComponent(VelocityComponent::create(Vec2(0, BulletVelocity), BulletVelocity));
		Bullets[i]->setVisible(false);
	}



	

	Meteors.push_back(pair(Meteor01 = Sprite::create("meteor.png"), meteor01HP));
	Meteors.push_back(pair(Meteor02 = Sprite::create("meteor.png"), meteor02HP));
	Meteors.push_back(pair(Meteor03 = Sprite::create("meteor.png"), meteor03HP));
	Meteors.push_back(pair(Meteor04 = Sprite::create("meteor.png"), meteor04HP));
	Meteors.push_back(pair(Meteor05 = Sprite::create("meteor.png"), meteor05HP));


	for (auto iMeteor : Meteors)
	{
		iMeteor.first->setScale(meteorScale);
		this->addChild(iMeteor.first, 2);
		iMeteor.first->addComponent(CollisionComponent::createCircle(((iMeteor.first->getContentSize().height) / 2) * meteorScale));
		iMeteor.first->setPosition(Vec2(MaxBounds + MaxBounds));
		iMeteor.first->setVisible(false);
	}

	

	ship = Sprite::create("fighter.png");
	//ship->removeAllComponents();				////
	ship->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 10);
	this->addChild(ship, 2);


	keyboard = KeyboardControllerComponent::create(0);
	ship->addComponent(keyboard);
	
	ship->addComponent(CollisionComponent::createCircle((ship->getContentSize().height) / 3));

	healthBarBase = Sprite::create("bar_empty.png");
	healthBarBase->setPosition(Vec2(ship->getPositionX(), ship->getPositionY() - HealthBarBaseOffset));
	this->addChild(healthBarBase, 3);

	healthBarHP = Sprite::create("bar_red.png");
	healthBarHP->setAnchorPoint(Vec2(0, 0));
	healthBarHP->setPosition(healthBarBase->getPosition() - HealthBarHPOffset);
	this->addChild(healthBarHP, 4);

	debug = DrawNode::create(5);
	this->addChild(debug, 5);


	label = Label::create();
	label->setScale(2);
	label->setString("Press Enter to play");

	label->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2 ,Director::getInstance()->getVisibleSize().height / 2));
	this->addChild(label, 5);

	keyboard->initInput();

	scheduleUpdate();
	return true;
};

void Assignment2::update(float dt)
{
	if (gameState != running)
	{
		if (keyboard->IsFirePressed())
		{
			gameState = running;
			label->setVisible(false);
			
			ship->addComponent(WaveComponent::create(wavesCompleted, MeteorVelocity, meteorHP, baseMeteorTimer, Meteors));					//start wave 1
		}
	}
	else
	{
		if (FireTimer >= 0)
		{
			FireTimer = FireTimer - (1 * dt);
		}

		//CONTROLLER

		if (keyboard->IsRightPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x + (Velocity * dt)), (ship->getPosition().y))));
		}
		if (keyboard->IsLeftPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x + ((Velocity * dt) * -1)), (ship->getPosition().y))));
		}
		if (keyboard->IsDownPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x), (ship->getPosition().y + ((Velocity * dt) * -1)))));
		}
		if (keyboard->IsUpPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x), (ship->getPosition().y + (Velocity * dt)))));
		}
		if (keyboard->IsFirePressed() && FireTimer == 0)
		{
			for (int i = 0; i < BulletArraySize; i++)
			{
				if (Bullets[i]->isVisible() == false)		
				{
					Bullets[i]->setPosition(Vec2(ship->getPositionX(), ship->getPositionY() + HealthBarBaseOffset));
					Bullets[i]->setVisible(true);
					break;
				}
			}
			FireTimer = FireCooldown;
		}

		if (keyboard->IsDebugPressed())
		{
			debugDrawEnabled = true;		
		}
		else if (!keyboard->IsDebugPressed())
		{
			debugDrawEnabled = false;
		}

		//BULLETS OUT OF SCOPE

		for (int i = 0; i < BulletArraySize-1; i++)		
		{
			if (Bullets[i]->isVisible())
			{
				if (Bullets[i]->getPosition().x > MaxBounds.x || Bullets[i]->getPosition().x < MinBounds.x || Bullets[i]->getPosition().y > MaxBounds.y|| Bullets[i]->getPosition().y < MinBounds.y)
				{
					Bullets[i]->setVisible(false);
				}
			}
		}

		//HEALTH BAR

		healthBarBase->setPosition(Vec2(ship->getPositionX(), ship->getPositionY() - HealthBarBaseOffset));
		healthBarHP->setPosition(healthBarBase->getPosition() - HealthBarHPOffset);
		/*if (healthBarHP->getScaleX() >= 0)
		{
			healthBarHP->setScaleX(healthBarHP->getScaleX() - (Damage * 0.001f));
		}*/

		//COLLISION

		debug->clear();
		debug->setLineWidth(5);

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

				//works if placed here

				
				for (auto it2 = it + 1; it2 != children.end(); it2++)
				{
					//works if placed here
					
					auto other = dynamic_cast<CollisionComponent*>((*it2)->getComponent("CollisionComponent"));
					//if (other != nullptr && other->getOwner() == ship && other->IsColliding())				//if something collides with the ship
					//{
					//	healthBarHP->setScaleX(healthBarHP->getScaleX() - (10 * 0.001f));
					//}
					if (other != nullptr)
					{
						//works here if other instead of collision
						if (collision->IsColliding(other))
						{
							if (other->getOwner() == ship)				//it works somehow
							{
								healthBarHP->setScaleX(healthBarHP->getScaleX() - (Damage * 0.01f));
								collision->getOwner()->setPosition(100, 100);
							}
							collision->SetColliding(true);							//works if other is NOT // out
							other->SetColliding(true);					
							
						}
					}
				}
			}
		}

		//debug mode

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
						//if (collision->getOwner() == ship && collision->IsColliding())				//if something collides with the ship
						//{
						//	healthBarHP->setScaleX(healthBarHP->getScaleX() - (10 * 0.001f));
						//	
						//}
						
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
};








