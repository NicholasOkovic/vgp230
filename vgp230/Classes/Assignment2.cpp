#include "Assignment2.h"

//#include "KeyboardControllerComponent.h"


class VelocityComponent : public Component
{
public:
	static VelocityComponent* create(/*Vec2 s*/bool d, float m)
	{
		auto rotating = new VelocityComponent(/*s*/d, m);
		rotating->init();
		rotating->autorelease();
		return rotating;
	}
	virtual bool init() 
    { 
        _name = "VelocityComponent"; return true; 

      /*  if (d == up)
        {

        }*/

    }
	VelocityComponent(/*Vec2 s*/bool d, float m) : _vel(s), _maxSpeed(m)
	{
	}
	virtual void update(float dt)
	{
		auto length = _vel.length();
		if (length > _maxSpeed)
		{
			_vel = Vec2((_vel.x / length) * _maxSpeed, (_vel.y / length) * _maxSpeed);
		}
		auto position = this->getOwner()->getPosition();
		this->getOwner()->setPosition(position + _vel * dt);
	}
	void operator+=(Vec2 const& v)
	{
		_vel += v;
	}
private:
	Vec2 _vel;
	float _maxSpeed;
};

//void Assignment2::keyPressed(EventKeyboard::KeyCode keyCode, Event* event)
//{
//	switch (keycode)
//	{
//	case EventKeyboard::KeyCode::KEY_A:
//		break;
//	}
//}

class KeyboardControllerComponent : public Component
{
public:
    typedef int KeyboardInputType;
    static constexpr int WASD = 0;
    static constexpr int ARROWS = 1;

    static KeyboardControllerComponent* create(/*const KeyboardInputType& type*/)
    {
        auto controller = new KeyboardControllerComponent(/*type*/);
        controller->init();
        controller->autorelease();
        return controller;
    }

    KeyboardControllerComponent(/*const KeyboardInputType& type*/)
    {
       /* if (type == WASD)
        {*/
            leftKeyCode = EventKeyboard::KeyCode::KEY_A;
            rightKeyCode = EventKeyboard::KeyCode::KEY_D;
            upKeyCode = EventKeyboard::KeyCode::KEY_W;
            downKeyCode = EventKeyboard::KeyCode::KEY_S;
        //}
       /* else
        {
            leftKeyCode = EventKeyboard::KeyCode::KEY_LEFT_ARROW;
            rightKeyCode = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
            upKeyCode = EventKeyboard::KeyCode::KEY_UP_ARROW;
            downKeyCode = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
        }*/
    }

    virtual bool init()
    {
       
        _name = "KeyboardControllerComponent";
        return true;
    }

    void initInput()
    {
        
        auto keyboardListener = EventListenerKeyboard::create();
        keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
            {
                if (keyCode == leftKeyCode)
                {
                    left = true;
                }
                else if (keyCode == rightKeyCode)
                {
                    right = true;
                }
                else if (keyCode == upKeyCode)
                {
                    up = true;
                }
                else if (keyCode == downKeyCode)
                {
                    down = true;
                }
            };
        keyboardListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
            {
                if (keyCode == leftKeyCode)
                {
                    left = false;
                }
                else if (keyCode == rightKeyCode)
                {
                    right = false;
                }
                else if (keyCode == upKeyCode)
                {
                    up = false;
                }
                else if (keyCode == downKeyCode)
                {
                    down = false;
                }
            };

        auto scene = this->getOwner()->getScene();
        auto dispatcher = Director::getInstance()->getEventDispatcher();

        dispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, scene);
    }

    bool IsLeftPressed()
    {
        return left;
    }

    bool IsRightPressed()
    {
        return right;
    }

    bool IsUpPressed()
    {
        return up;
    }

    bool IsDownPressed()
    {
        return down;
    }
private:

    EventKeyboard::KeyCode leftKeyCode;
    EventKeyboard::KeyCode rightKeyCode;
    EventKeyboard::KeyCode upKeyCode;
    EventKeyboard::KeyCode downKeyCode;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
};


Scene* Assignment2::createScene()
{
	return Assignment2::create();
}



bool Assignment2::init()
{
   
	

	auto hero = Sprite::create("fighter.png");



    auto keyboardControllerComponent = KeyboardControllerComponent::create();
    hero->addComponent(keyboardControllerComponent);

     

   /* auto velocityComponent = VelocityComponent::create(Vec2(10, 2), 100.0f);
	hero->addComponent(velocityComponent);*/

	//auto keyboardListener = EventListenerKeyboard::create();
	/*keyboardListener->onKeyPressed = CC_CALLBACK_2(Assignment2::keyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	auto keyboardControllerComponent = KeyboardControllerComponent::create(KeyboardInputType());
	hero->addComponent(KeyboardControllerComponent);*/

	hero->setPosition(500, 500);
	this->addChild(hero, 0);
	scheduleUpdate();
	return true;
};

void Assignment2::update(float dt)
{

};



