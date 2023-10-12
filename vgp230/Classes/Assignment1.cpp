#include "Assignment1.h"

Scene* Assignment1::createScene()
{
	return Assignment1::create();
}

bool Assignment1::init() {
	//runs once at start
	//auto visibleSize = Director::getInstance()->getVisibleSize();
	//*ScreenSize = visibleSize;

	auto sprite = Sprite::create("bullet_bill.png");
	dvd = sprite;

	sprite->setPosition(Vec2(500, 500));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	scheduleUpdate();
	return true;
}

void Assignment1::update(float dt)
{
	dvd->setPosition((Vec2((dvd->getPosition().x + (VelocityX* dt)), (dvd->getPosition().y + (VelocityY *dt)))));


	if (dvd->getPosition().x >= (Director::getInstance()->getVisibleSize().width) - dvd->getContentSize().width/2 || dvd->getPosition().x <= 0 + dvd->getContentSize().width/2)
	{
		VelocityX *= -1;
	}

	if (dvd->getPosition().y >= (Director::getInstance()->getVisibleSize().height) - dvd->getContentSize().height/4 || dvd->getPosition().y <= 0 + dvd->getContentSize().height/4)
	{
		VelocityY *= -1;
	}

}
