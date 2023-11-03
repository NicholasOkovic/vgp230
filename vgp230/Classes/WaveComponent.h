#pragma once
#include "cocos2d.h"
#include <cstdlib>

using namespace std;

USING_NS_CC;

class WaveComponent : public Component
{
public:
	
	static WaveComponent* create(int w, int m, int HP, int timer/*, vector<pair<Sprite*, int>>& Meteors*/, Scene* scene)
	{
		auto WaveManage = new WaveComponent(w, m, HP, timer/*, Meteors*/);
		WaveManage->init(scene);
		WaveManage->autorelease();
		return WaveManage;
	}
	WaveComponent(int w, int m, int HP, int timer/*, vector<pair<Sprite*, int>>& Meteors*/)
	{

		//init all meteors
		
		//srand(time(0));

		//CMeteors.push_back(pair(Meteor01 = Sprite::create("meteor.png"), meteorHP));	//////test
		//CMeteors.push_back(pair(Meteor02 = Sprite::create("meteor.png"), meteorHP));
		//CMeteors.push_back(pair(Meteor03 = Sprite::create("meteor.png"), meteorHP));
		//CMeteors.push_back(pair(Meteor04 = Sprite::create("meteor.png"), meteorHP));
		//CMeteors.push_back(pair(Meteor05 = Sprite::create("meteor.png"), meteorHP));


		//for (auto iMeteor : CMeteors)
		//{
		//	iMeteor.first->setScale(meteorScale);
		//	this->getOwner()->addChild(iMeteor.first, 2);					///find a way to add them as children to the scene
		//	iMeteor.first->setName("Meteor");
		//	iMeteor.first->addComponent(CollisionComponent::createCircle(((iMeteor.first->getContentSize().height) / 2) * meteorScale));
		//	iMeteor.first->setPosition(meteorInitPos);
		//	iMeteor.first->setVisible(false);
		//}

		baseMeteorTimer = timer;
		meteorTimer = timer;
		meteorHP = HP;
		meteorSpeed = m;
		wavesCompleted = w;

		/*for (auto iMeteor : Meteors)
		{
			CMeteors.push_back(pair(iMeteor.first, iMeteor.second));
		}*/


		//meteorSpawnLoc = Director::getInstance()->getVisibleSize().width - ((CMeteors[0].first->getContentSize().width * CMeteors[0].first->getScale())/2);

	}

	virtual bool init(Scene* scene)
	{


		srand(time(0));

		CMeteors.push_back(pair(Meteor01 = Sprite::create("meteor.png"), meteorHP));	//////test
		CMeteors.push_back(pair(Meteor02 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor03 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor04 = Sprite::create("meteor.png"), meteorHP));
		CMeteors.push_back(pair(Meteor05 = Sprite::create("meteor.png"), meteorHP));


		for (auto iMeteor : CMeteors)
		{
			iMeteor.first->setScale(meteorScale);
			scene->addChild(iMeteor.first, 2);					///find a way to add them as children to the scene
			iMeteor.first->setName("Meteor");
			iMeteor.first->addComponent(CollisionComponent::createCircle(((iMeteor.first->getContentSize().height) / 2) * meteorScale));
			iMeteor.first->setPosition(meteorInitPos);
			iMeteor.first->setVisible(false);
		}
		/*for (auto iMeteor : Meteors)
		{
			CMeteors.push_back(pair(iMeteor.first, iMeteor.second));
		}*/


		meteorSpawnLoc = Director::getInstance()->getVisibleSize().width - ((CMeteors[0].first->getContentSize().width * CMeteors[0].first->getScale()) / 2);


		_name = "WavesComponent";
		return true;
	}

	virtual void update(float dt)			//reset all the meteor in comp, and edit var in comp | limit: wave detection, nvm create comp object and method detect wave
	{


		if (iterator >= CMeteors.size() && !CMeteors[CMeteors.size()-1].first->isVisible())	//when wave is over	//only checks if last meteor is destroyed to start next wave
		{
			//finished = true;
			wavesCompleted++;
			meteorHP += 5;
			baseMeteorTimer - 100;
			meteorSpeed -= 100;
			meteorTimer = baseMeteorTimer;
			iterator = 0;

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

	bool IsWaveDone() 
	{
		return finished;
	}

private:
	vector<pair<Sprite*, int>> CMeteors;

	Sprite* Meteor01;
	Sprite* Meteor02;
	Sprite* Meteor03;
	Sprite* Meteor04;
	Sprite* Meteor05;

	float meteorScale = 0.1f;
	int baseMeteorTimer;
	int meteorTimer;
	int meteorHP;
	int meteorSpeed;
	int wavesCompleted;
	int iterator = 0;
	int i2 = 0;
	bool finished = false;
	Vec2 meteorInitPos = Vec2(4000, 2000);
	int meteorSpawnLoc;
	int randomNumber;
};

