#pragma once


#include "cocos2d.h"

USING_NS_CC;

class Assignment2 : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    virtual void update(float dt);

    virtual void keyPressed(EventKeyboard::KeyCode keyCode, Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(Assignment2);
};