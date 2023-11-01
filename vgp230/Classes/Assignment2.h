#pragma once


#include "cocos2d.h"
#include "KeyboardControllerComponent.h"
#include "VelocityComponent.h"
#include "CollisionTestScene.h"
USING_NS_CC;

class Assignment2 : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();
    virtual void update(float dt);

    enum GameState
    {
        menu,
        running,
        victory
    }
    gameState = menu;


    //Sprite* Bullets[20];

    int FireTimer = 0;
    int FireCooldown = 20;

    int Velocity = 150;
    int BulletVelocity = 500;

    Sprite* ship2;
    Sprite* ship;

    Sprite* bullet;
    Sprite* healthBarBase;
    Sprite* healthBarHP;
    int HealthBarBaseOffset = 60;
    Vec2 HealthBarHPOffset = Vec2(100, 15);

    int Damage = 1;
    KeyboardControllerComponent* keyboard;
    VelocityComponent* VelComponent;

 
    DrawNode* debug;
    bool debugDrawEnabled = false;

    Label* label;

    Sprite* Bullets[20];

    Sprite* bullet01;
    Sprite* bullet02;
    Sprite* bullet03;
    Sprite* bullet04;
    Sprite* bullet05;
    Sprite* bullet06;
    Sprite* bullet07;
    Sprite* bullet08;
    Sprite* bullet09;
    Sprite* bullet10;
    Sprite* bullet11;
    Sprite* bullet12;
    Sprite* bullet13;
    Sprite* bullet14;
    Sprite* bullet15;
    Sprite* bullet16;
    Sprite* bullet17;
    Sprite* bullet18;
    Sprite* bullet19;
    Sprite* bullet20;

    int BulletArraySize = 20;

    Vec2 Bounds = (Vec2(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height));
    Vec2 MinBounds = (Vec2(0, -50));

    Sprite* Meteor;
    int meteorHP = 100;


     //implement the "static create()" method manually
    CREATE_FUNC(Assignment2);
};