//#pragma once
//#include "cocos2d.h"
#ifndef FOO_H
#define FOO_H

	
	//variables

class SpaceShip
{
public:
	static SpaceShip* getInstance();
	
	bool FirstPlay = true;

	bool LevelTwoLock = true;

	bool HasLevelOneItem_01 = false;
	bool HasLevelOneItem_02 = false;

	bool HasLevelTwoItem_01 = false;
	bool HasLevelTwoItem_02 = false;

	float LevelOneTimeComp = 0;
	float LevelOneTime = 0;
	float LevelTwoTimeComp = 0;
	float LevelTwoTime = 0;

private:
	SpaceShip();
	static SpaceShip* instance;
};



#endif


