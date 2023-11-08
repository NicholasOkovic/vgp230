#pragma once


#include "cocos2d.h"

USING_NS_CC;

class Assignment1 : public Scene
{
public:
   ///* static Scene* Assignment1::createScene()
   // {
   //     return Assignment1::create();
   // }*/
   static Scene* createScene();

    virtual bool init();

    virtual void update(float dt);

    Sprite* dvd;

    cocos2d::Size* ScreenSize;

    int VelocityX = 80;
    int VelocityY = 80;

    // implement the "static create()" method manually
    CREATE_FUNC(Assignment1);
};