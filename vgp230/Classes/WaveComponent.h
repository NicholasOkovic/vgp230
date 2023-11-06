#pragma once
#include "cocos2d.h"
#include <cstdlib>

using namespace std;

USING_NS_CC;

class WaveComponent : public Component
{
public:
	
	static WaveComponent* create(int w, int m, int HP, int timer, Scene* scene)
	{
		auto WaveManage = new WaveComponent(w, m, HP, timer);
		WaveManage->init(scene);
		WaveManage->autorelease();
		return WaveManage;
	}
	WaveComponent(int w, int m, int HP, int timer)
	{
		baseMeteorTimer = timer;
		meteorTimer = timer;
		meteorHP = HP;
		meteorSpeed = m;
		wave = w+1;
	}

	virtual bool init(Scene* scene)
	{
		srand(time(0));

		CMeteors.push_back(pair(Meteor01 = Sprite::create("meteor.png"), meteorHP));	
		CMeteors.push_back(pair(Meteor02 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor03 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor04 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor05 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor06 = Sprite::create("meteor.png"), meteorHP));	
		CMeteors.push_back(pair(Meteor07 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor08 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor09 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor10 = Sprite::create("meteor.png"), meteorHP));

		for (auto iMeteor : CMeteors)
		{
			iMeteor.first->setScale(meteorScale);
			scene->addChild(iMeteor.first, 2);					
			iMeteor.first->setName("Meteor");
			iMeteor.first->addComponent(CollisionComponent::createCircle(((iMeteor.first->getContentSize().height) / 2) * meteorScale));
			iMeteor.first->setPosition(meteorInitPos);
			iMeteor.first->setVisible(false);
		}

		meteorSpawnLoc = Director::getInstance()->getVisibleSize().width - ((CMeteors[0].first->getContentSize().width * CMeteors[0].first->getScale()) / 2);

		wavesTxt = Label::create();
		wavesTxt->setScale(2);
		wavesTxt->setString("Wave: 1");
		wavesTxt->setPosition(WavePlacement);
		scene->addChild(wavesTxt, 5);
		_name = "WavesComponent";
		return true;
	}

	virtual void update(float dt)			
	{
		if (iterator >= CMeteors.size() && !CMeteors[CMeteors.size()-1].first->isVisible())			//when wave is over	//checks if last meteor is destroyed to start next wave
		{
			wave++;
			//meteorHP += 10;	//kidna dont like this, but if you want to make the meteors healthier per wave you can
			if (baseMeteorTimer > 10)
			{
				baseMeteorTimer -= 10;
			}
			meteorSpeed -= 50;
			meteorTimer = baseMeteorTimer;
			iterator = 0;
			toString = to_string(wave);
			wavesTxt->setString("Wave: " + toString);

			MeteorReset(CMeteors);
		}
		else if (meteorTimer == 0 && iterator < CMeteors.size())
		{
			CMeteors[iterator].first->setPosition(randomNumber = rand() % meteorSpawnLoc + ((CMeteors[0].first->getContentSize().width * CMeteors[0].first->getScale()) / 2), Director::getInstance()->getVisibleSize().height);	//do a rand pos
			CMeteors[iterator].first->addComponent(VelocityComponent::create(Vec2(0, meteorSpeed), -meteorSpeed));
			CMeteors[iterator].first->setVisible(true);
			meteorTimer = baseMeteorTimer;
			iterator++;
		}
		meteorTimer -= 1 * dt;
	}
	void MeteorReset(vector<pair<Sprite*, int>>& Meteors)
	{
		for (int  m = 0; m < Meteors.size(); m++)
		{
			Meteors[m].first->removeComponent(Meteors[m].first->getComponent("VelocityComponent"));
			Meteors[m].second = meteorHP;
		}
	}

	vector<pair<Sprite*, int>> GetMeteors()
	{
		return CMeteors;
	}

	void DamageMeteor(int damage, int meteor)
	{
		CMeteors[meteor].second -= damage;
	}

	int GetWave() 
	{
		return wave+1;
	}

private:
	vector<pair<Sprite*, int>> CMeteors;

	Sprite* Meteor01;
	Sprite* Meteor02;
	Sprite* Meteor03;
	Sprite* Meteor04;
	Sprite* Meteor05;
	Sprite* Meteor06;
	Sprite* Meteor07;
	Sprite* Meteor08;
	Sprite* Meteor09;
	Sprite* Meteor10;

	float meteorScale = 0.1f;
	int baseMeteorTimer;
	int meteorTimer;
	int meteorHP;
	int meteorSpeed;
	int wave;
	int iterator = 0;
	int i2 = 0;
	string toString;
	Label* wavesTxt;
	Vec2 WavePlacement = Vec2(Director::getInstance()->getVisibleSize().width - 60, Director::getInstance()->getVisibleSize().height - 30);
	Vec2 meteorInitPos = Vec2(4000, 2000);
	int meteorSpawnLoc;
	int randomNumber;
};

