#pragma once


#include "cocos2d.h"
#include "KeyboardControllerComponent.h"
#include "VelocityComponent.h"
#include "CollisionComponent.h"
#include "WaveComponent.h"
#include <cocostudio/SimpleAudioEngine.h>

using namespace CocosDenshion;


USING_NS_CC;
using namespace std;

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
        victory,
        defeat
    }
    gameState = menu;

    Sprite* PUSpeedBoost;
    int SpeedBoostAmount = 125;
    Sprite* PUWeaponBoost;
    int WeaponBoostAmount = -15;

    Sprite* WinCon;

    Sprite* MeteorEndZone;

    Sprite* ship;
    int ShipVelocity = 250;


    Sprite* healthBarBase;
    Sprite* healthBarHP;
    int HealthBarBaseOffset = 60;
    Vec2 HealthBarHPOffset = Vec2(100, 15);

    KeyboardControllerComponent* keyboard;
    WaveComponent* WaveControl;
 
    DrawNode* debug;
    bool debugDrawEnabled = false;

    Label* label;
    Label* scoreTxt;
    Label* victoryTxt;
    Label* defeatTxt;

    int iScore = 0;

    int bombAmount = 2;

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
    int BulletVelocity = 500;
    int bulletDamage = 40;
    int FireTimer = 0;
    int FireCooldown = 30;
    Vec2 bulletInitPos = Vec2(2000, 2000);   

    int meteorDamage = 10;
    Vec2 meteorInitPos = Vec2(4000, 2000);
    int meteorHP = 100;
    int wavesCompleted = 0;
    int baseMeteorTimer = 100;
    int MeteorVelocity = -75;

    Vec2 MaxBounds = (Vec2(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height));
    Vec2 MinBounds = (Vec2(0, -50));
    Vec2 ScorePlacement = Vec2(60, Director::getInstance()->getVisibleSize().height - 30);

    SimpleAudioEngine* backgroundMusic;


     //implement the "static create()" method manually
    CREATE_FUNC(Assignment2);
};