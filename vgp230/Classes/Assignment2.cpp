#include "Assignment2.h"


Scene* Assignment2::createScene()
{
	return Assignment2::create();
}



bool Assignment2::init()
{/*
	auto bullet01 = Sprite::create("bullet1");			don't know how to do object pooling, ask next class
	auto bullet02 = Sprite::create("bullet1");
	auto bullet03 = Sprite::create("bullet1");
	auto bullet04 = Sprite::create("bullet1");
	auto bullet05 = Sprite::create("bullet1");
	auto bullet06 = Sprite::create("bullet1");
	auto bullet07 = Sprite::create("bullet1");
	auto bullet08 = Sprite::create("bullet1");
	auto bullet09 = Sprite::create("bullet1");
	auto bullet10 = Sprite::create("bullet1");
	auto bullet11 = Sprite::create("bullet1");
	auto bullet12 = Sprite::create("bullet1");
	auto bullet13 = Sprite::create("bullet1");
	auto bullet14 = Sprite::create("bullet1");
	auto bullet15 = Sprite::create("bullet1");
	auto bullet16 = Sprite::create("bullet1");
	auto bullet17 = Sprite::create("bullet1");
	auto bullet18 = Sprite::create("bullet1");
	auto bullet19 = Sprite::create("bullet1");
	auto bullet20 = Sprite::create("bullet1");

	for (int i = 0; i < sizeof(Bullets)/sizeof(int); i++)
	{
	}*/
	//int arr[20] = { int a = 1 };
	//Sprite Bullets[2] = { Sprite::create("bullet1") = auto bullet21 , auto bullet22 = Sprite::create("bullet1") };

	//bullet01->setOpacity(100);

	healthBarBase = Sprite::create("bar_empty.png");
	this->addChild(healthBarBase, 3);

	healthBarHP = Sprite::create("bar_red.png");
	this->addChild(healthBarHP, 4);

	ship = Sprite::create("fighter.png");
	ship->setPosition(500, 50);
	this->addChild(ship, 2);

    keyboard = KeyboardControllerComponent::create(1);
    ship->addComponent(keyboard);
	
	scheduleUpdate();
	return true;
};

void Assignment2::update(float dt)
{
	if (FireTimer >= 0)
	{
		FireTimer = FireTimer - (1 * dt);
	}

	keyboard->initInput();

	if (keyboard->IsRightPressed())
	{
		ship->setPosition((Vec2((ship->getPosition().x + (Velocity * dt)), (ship->getPosition().y))));
	}
	if (keyboard->IsLeftPressed())
	{
		ship->setPosition((Vec2((ship->getPosition().x + ((Velocity * dt)*-1)), (ship->getPosition().y))));
	}
	if (keyboard->IsDownPressed())
	{
		ship->setPosition((Vec2((ship->getPosition().x ), (ship->getPosition().y + ((Velocity * dt) * -1)))));
	}
	if (keyboard->IsUpPressed())
	{
		ship->setPosition((Vec2((ship->getPosition().x), (ship->getPosition().y + (Velocity * dt)))));
	}
	if (keyboard->IsFirePressed() && FireTimer == 0)
	{
		//(when object pool is created) create a for loop looking for an inactive bullet, when it finds one activate it	
		bullet = Sprite::create("bullet1.png");
		this->addChild(bullet, 1);
		auto VelComponent = VelocityComponent::create(Vec2(0, BulletVelocity), BulletVelocity);
		bullet->addComponent(VelComponent);
		bullet->setPosition(Vec2(ship->getPositionX(), ship->getPositionY()));
		
		FireTimer = 20;
	}

	healthBarBase->setPosition(Vec2(ship->getPositionX(), ship->getPositionY() - HealthBarBaseOffset));
	healthBarHP->setPosition(healthBarBase->getPosition() - HealthBarHPOffset);
	healthBarHP->setAnchorPoint(Vec2(0, 0));
	if (healthBarHP->getScaleX() >= 0)
	{
		healthBarHP->setScaleX(healthBarHP->getScaleX() - (Damage * 0.001f));
	}
};



