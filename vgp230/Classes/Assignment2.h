#pragma once


#include "cocos2d.h"
#include "KeyboardControllerComponent.h"
#include "VelocityComponent.h"
#include "CollisionTestScene.h"
#include "WaveComponent.h"

USING_NS_CC;
using namespace std;

class Assignment2 : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();
    virtual void update(float dt);

    void Wave1(float dt);

    enum GameState
    {
        menu,
        running,
        victory
    }
    gameState = menu;

    bool switchstate = true;

    //Sprite* Bullets[20];

    int FireTimer = 0;
    int FireCooldown = 20;

    int Velocity = 150;
    int BulletVelocity = 500;
    int MeteorVelocity = -250;

    Sprite* ship2;
    Sprite* ship;

    Sprite* bullet;
    Sprite* healthBarBase;
    Sprite* healthBarHP;
    int HealthBarBaseOffset = 60;
    Vec2 HealthBarHPOffset = Vec2(100, 15);

    int Damage = 20;
    KeyboardControllerComponent* keyboard;

 
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

    vector<pair<Sprite*, int>> Meteors;

    Sprite* Meteor01;
    Sprite* Meteor02;
    Sprite* Meteor03;
    Sprite* Meteor04;
    Sprite* Meteor05;

    float meteorScale = 0.1f;

    int meteorHP = 100;

    int meteor01HP;
    int meteor02HP;
    int meteor03HP;
    int meteor04HP;
    int meteor05HP;

    int wavesCompleted = 0;
    //waves will be a component that will be added to teh player an dthen will be checked if completeion, upon completion it will remove
    //itself and then ++ var, when reached certain var, deploy crown to win, or countinue for endless gamemode

    int baseMeteorTimer = 200;

    Vec2 MaxBounds = (Vec2(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height));
    Vec2 MinBounds = (Vec2(0, -50));




     //implement the "static create()" method manually
    CREATE_FUNC(Assignment2);
};