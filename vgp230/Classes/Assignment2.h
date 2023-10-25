#pragma once


#include "cocos2d.h"
#include "KeyboardControllerComponent.h"
#include "VelocityComponent.h"
USING_NS_CC;

class Assignment2 : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();
    virtual void update(float dt);

    //Sprite* Bullets[20];

    int FireTimer = 0;

    int Velocity = 150;
    int BulletVelocity = 500;

    Sprite* ship;
    Sprite* bullet;
    Sprite* healthBarBase;
    Sprite* healthBarHP;
    int HealthBarBaseOffset = 60;
    Vec2 HealthBarHPOffset = Vec2(100, 15);

    int Damage = 1;
    KeyboardControllerComponent* keyboard;

     //implement the "static create()" method manually
    CREATE_FUNC(Assignment2);
};