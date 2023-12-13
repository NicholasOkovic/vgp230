
#include "Final.h"
//#include "LevelOneFinal.h"

class LevelTwoFinal : public Final
{
public:
	static Scene* createScene();

	virtual bool init();
	virtual void update(float dt);

	Vec2 LevelOffset = Vec2(Director::getInstance()->getVisibleSize().width, 0);

	int BoundryScale = 1000;

	Sprite* BoundryLeft;
	Sprite* BoundryRight;

	



	Sprite* Asteroid6_01;
	Sprite* Asteroid6_02;
	Sprite* Asteroid6_03;
	Sprite* Asteroid5_04;
	Sprite* Asteroid5_05;

	Sprite* Asteroid11_01;
	Sprite* Asteroid11_02;
	Sprite* Asteroid11_03;
	Sprite* Asteroid11_04;
	Sprite* Asteroid11_05;

	Sprite* LargeAstroid_01;
	Sprite* LargeAstroid_02;
	Sprite* LargeAstroid_03;
	Sprite* LargeAstroid_04;
	Sprite* LargeAstroid_05;


	CREATE_FUNC(LevelTwoFinal);

};
