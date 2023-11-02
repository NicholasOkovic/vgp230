#pragma once
#include "cocos2d.h"
#include <cstdlib>

using namespace std;

USING_NS_CC;

class WaveComponent : public Component
{
public:
	
	static WaveComponent* create(int w, int m, int HP, int timer, vector<pair<Sprite*, int>>& Meteors)
	{
		auto WaveManage = new WaveComponent(w, m, HP, timer, Meteors);
		WaveManage->init();
		WaveManage->autorelease();
		return WaveManage;
	}
	WaveComponent(int w, int m, int HP, int timer, vector<pair<Sprite*, int>>& Meteors)
	{
		//init all meteors
		
		srand(time(0));

		baseMeteorTimer = timer;
		meteorTimer = timer;
		meteorHP = HP;
		meteorSpeed = m;
		wavesCompleted = w;

		for (auto iMeteor : Meteors)
		{
			componentMeteors.push_back(pair(iMeteor.first, meteorHP));
		}


		meteorSpawnLoc = Director::getInstance()->getVisibleSize().width - ((componentMeteors[0].first->getContentSize().width * componentMeteors[0].first->getScale())/2);

	}

	virtual bool init()
	{
		_name = "WavesComponent";
		return true;
	}

	virtual void update(float dt)
	{
		if (iterator >= componentMeteors.size())//needs to check if meteor is destroyed
		{
			finished = true;
		}
		else if (meteorTimer == 0)
		{

			componentMeteors[iterator].first->setPosition(randomNumber = rand() % meteorSpawnLoc + ((componentMeteors[0].first->getContentSize().width * componentMeteors[0].first->getScale()) / 2), Director::getInstance()->getVisibleSize().height);	//do a rand pos
			componentMeteors[iterator].first->addComponent(VelocityComponent::create(Vec2(0, meteorSpeed), 100));
			componentMeteors[iterator].first->setVisible(true);
			meteorTimer = baseMeteorTimer;
			iterator++;
		}
		meteorTimer -= 1 * dt;
	}

	bool WaveDone() 
	{
		return finished;
	}

private:
	vector<pair<Sprite*, int>> componentMeteors;
	int baseMeteorTimer;
	int meteorTimer;
	int meteorHP;
	int meteorSpeed;
	int wavesCompleted;
	int iterator = 0;
	bool finished = false;
	int meteorSpawnLoc;
	int randomNumber;
};

