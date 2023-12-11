#pragma once
#include "Final.h"

class Trophy : public Final
{
public:
	static Scene* createScene();

	virtual bool init();
	virtual void update(float dt);

	ParticleSystemQuad* particleSystem_01;
	ParticleSystemQuad* particleSystem_02;


	Sprite* LevelOneItemTrig_01;
	Sprite* LevelOneItemTrig_02;

	Sprite* LevelTwoItemTrig_01;
	Sprite* LevelTwoItemTrig_02;

	Sprite* LevelOneItem_01;
	Sprite* LevelOneItem_02;

	Sprite* LevelTwoItem_01;
	Sprite* LevelTwoItem_02;


	Label* LevelOneTimeTxt;
	Label* LevelTwoTimeTxt;

	Label* DisplayTime_01;
	Label* DisplayTime_02;

	CREATE_FUNC(Trophy);

private:

};
