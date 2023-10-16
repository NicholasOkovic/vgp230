#include "Assignment2.h"

#include "KeyboardControllerComponent.h"







Scene* Assignment2::createScene()
{
	return Assignment2::create();
}



bool Assignment2::init()
{
	auto hero = Sprite::create("fighter.png");

	auto keyboardListener = EventListenerKeyboard::create();

	keyboardListener->onKeyPressed = CC_CALLBACK_2(Assignment2::keyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);


	auto keyboardControllerComponent = KeyboardControllerComponent::create(KeyboardInputType());


	hero->addComponent(KeyboardControllerComponent);

	hero->setPosition(500, 500);
	this->addChild(hero, 0);
	scheduleUpdate();
	return true;
};

void Assignment2::update(float dt)
{
	if (true)
	{

	}




};

void Assignment2::keyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_A:
		break;
	}
}

