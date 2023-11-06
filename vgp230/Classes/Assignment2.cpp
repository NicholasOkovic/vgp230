#include "Assignment2.h"

Scene* Assignment2::createScene()
{
	return Assignment2::create();
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
		Bullets[i]->addComponent(VelocityComponent::create(Vec2(0, BulletVelocity), BulletVelocity));
		Bullets[i]->setPosition(bulletInitPos);
		Bullets[i]->setVisible(false);
	}

	PUWeaponBoost = Sprite::create("cheese.png");
	this->addChild(PUWeaponBoost, 2);
	PUWeaponBoost->setPosition(Director::getInstance()->getVisibleSize().width / 3, Director::getInstance()->getVisibleSize().height / 2);
	PUWeaponBoost->addComponent(CollisionComponent::createCircle((PUWeaponBoost->getContentSize().height) / 2));
	PUWeaponBoost->setName("WeaponBoost");

	PUSpeedBoost = Sprite::create("carrot.png");
	this->addChild(PUSpeedBoost, 2);
	PUSpeedBoost->setPosition(Director::getInstance()->getVisibleSize().width / 1.5, Director::getInstance()->getVisibleSize().height / 2);
	PUSpeedBoost->addComponent(CollisionComponent::createCircle((PUSpeedBoost->getContentSize().height) / 2));
	PUSpeedBoost->setName("SpeedBoost");

	ship = Sprite::create("fighter.png");
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

	MeteorEndZone = Sprite::create("button_off.png");
	this->addChild(MeteorEndZone, 0);
	MeteorEndZone->setPosition(Director::getInstance()->getVisibleSize().width / 2, 0);
	MeteorEndZone->setScaleX(10);
	MeteorEndZone->addComponent(CollisionComponent::createBox(MeteorEndZone->getContentSize().width * MeteorEndZone->getScaleX(), MeteorEndZone->getContentSize().height * MeteorEndZone->getScaleY()));
	MeteorEndZone->setVisible(false);

	debug = DrawNode::create(5);
	this->addChild(debug, 5);

	label = Label::create();
	label->setScale(2);
	label->setString("Press Enter to play");
	label->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2 ,Director::getInstance()->getVisibleSize().height / 2));
	this->addChild(label, 5);

	victoryTxt = Label::create();
	victoryTxt->setScale(5);
	victoryTxt->setString("Victory");
	victoryTxt->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	this->addChild(victoryTxt, 6);
	victoryTxt->setVisible(false);

	defeatTxt = Label::create();
	defeatTxt->setScale(5);
	defeatTxt->setString("Defeat");
	this->addChild(defeatTxt, 6);
	defeatTxt->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	defeatTxt->setVisible(false);

	keyboard->initInput();

	scheduleUpdate();
	return true;
};

void Assignment2::update(float dt)
{
	if (gameState == running)
	{

		if (FireTimer >= 0)
		{
			FireTimer -= (1 * dt);
		}

		//CONTROLLER

		if (keyboard->IsRightPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x + (ShipVelocity * dt)), (ship->getPosition().y))));
		}
		if (keyboard->IsLeftPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x + ((ShipVelocity * dt) * -1)), (ship->getPosition().y))));
		}
		if (keyboard->IsDownPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x), (ship->getPosition().y + ((ShipVelocity * dt) * -1)))));
		}
		if (keyboard->IsUpPressed())
		{
			ship->setPosition((Vec2((ship->getPosition().x), (ship->getPosition().y + (ShipVelocity * dt)))));
		}
		if (keyboard->IsFirePressed() && FireTimer == 0)
		{
			for (int i = 0; i < BulletArraySize; i++)
			{
				if (Bullets[i]->isVisible() == false)		
				{
					SimpleAudioEngine::getInstance()->playEffect("blasterSound.mp3");					
					Bullets[i]->setPosition(Vec2(ship->getPositionX(), ship->getPositionY() + HealthBarBaseOffset));
					Bullets[i]->setVisible(true);
					break;
				}
			}
			FireTimer = FireCooldown;
		}
		if (bombAmount > 0 && keyboard->IsBombPressed())
		{
			for (int i = 0; i < WaveControl->GetMeteors().size(); i++)
			{
				if (WaveControl->GetMeteors()[i].first->isVisible() == true)
				{
					WaveControl->DamageMeteor(9999, i);
				}
			}
			bombAmount--;
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
				for (auto it2 = it + 1; it2 != children.end(); it2++)
				{
					auto other = dynamic_cast<CollisionComponent*>((*it2)->getComponent("CollisionComponent"));
					if (other != nullptr)
					{
						if (collision->IsColliding(other))
						{
							if (collision->GetCollisionType() == CollisionComponent::Point && other->getOwner()->getName() == "Meteor")		//if meteor colliding with bullet
							{
								collision->getOwner()->setVisible(false);
								collision->getOwner()->setPosition(bulletInitPos);

								for (int i = 0; i < WaveControl->GetMeteors().size(); i++)
								{
									if (other->getOwner() == WaveControl->GetMeteors()[i].first)
									{
										WaveControl->DamageMeteor(bulletDamage, i);
									}
								}
							}
							else if (collision->getOwner() == ship)
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
							}
							else if (other->getOwner() == ship)
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
							}
							else if (collision->GetCollisionType() == CollisionComponent::Box && other->getOwner()->getName() == "Meteor")		//if meteor colliding with bullet
							{
								other->getOwner()->setVisible(false);
								other->getOwner()->setPosition(MaxBounds + MaxBounds);
								healthBarHP->setScaleX(healthBarHP->getScaleX() - (meteorDamage * 0.01f));
							}
							collision->SetColliding(true);							
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
						auto radius = collision->GetRadius();
						debug->drawCircle(position, radius, 10, 360, false, color);
					}
					break;
					case CollisionComponent::Point:
						debug->drawDot(position, 3, color);
						break;
					}
					for (int i = 0; i < WaveControl->GetMeteors().size(); i++)
					{
						if (collision->getOwner() == WaveControl->GetMeteors()[i].first)
						{
							if (WaveControl->GetMeteors()[i].second <= meteorHP /2)
							{
								debug->drawCircle(position, collision->GetRadius() / 2, 10, 360, false, Color4F::RED);
							}
							else if (WaveControl->GetMeteors()[i].second >= meteorHP / 2 && WaveControl->GetMeteors()[i].second < meteorHP)
							{
								debug->drawCircle(position, collision->GetRadius() / 2, 10, 360, false, Color4F::YELLOW);
							}
							else
							{
								debug->drawCircle(position, collision->GetRadius() / 2, 10, 360, false, Color4F::GREEN);
							}
						}
					}
				}
			}
		}

		//if a meteor dies

		for (int i = 0; i < WaveControl->GetMeteors().size(); i++)
		{
			if (WaveControl->GetMeteors()[i].first->isVisible() && WaveControl->GetMeteors()[i].second <= 0)	//can also do is damaged / switch sprite
			{
				WaveControl->GetMeteors()[i].first->setVisible(false);
				WaveControl->GetMeteors()[i].first->setPosition(meteorInitPos);
				iScore++;
				string toString = to_string(iScore);
				scoreTxt->setString("Score: " + toString);

				if (iScore == 10)	//create win condition
				{
					WinCon = Sprite::create("CloseNormal.png");
					this->addChild(WinCon, 2);
					WinCon->addComponent(CollisionComponent::createCircle((WinCon->getContentSize().height) / 2));
					WinCon->setName("Win");
					WinCon->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 1.1);
				}
			}
		}
		//if death
		if (healthBarHP->getScaleX() <= 0.01)
		{
			gameState = defeat;
		}
	}
	//more gamestates checks
	else if (gameState == menu)
	{
		if (keyboard->IsFirePressed())
		{
			backgroundMusic->getInstance()->playBackgroundMusic("Field of Hopes and Dreams.mp3", true);
			backgroundMusic->getInstance()->setBackgroundMusicVolume(0.1);

			gameState = running;
			label->setVisible(false);
			scoreTxt = Label::create();
			scoreTxt->setScale(2);
			scoreTxt->setString("Score: 0");
			scoreTxt->setPosition(ScorePlacement);
			this->addChild(scoreTxt, 5);

			WaveControl = WaveComponent::create(wavesCompleted, MeteorVelocity, meteorHP, baseMeteorTimer, this);
			ship->addComponent(WaveControl);					
		}
	}
	else if (gameState == victory)
	{
		victoryTxt->setVisible(true);
	}
	else if (gameState == defeat)
	{
		defeatTxt->setVisible(true);
	}
};