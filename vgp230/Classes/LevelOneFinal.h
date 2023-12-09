
//#include "cocos2d.h"
//#include "SpaceShip.h"
#include "Final.h"
#include "VelocityComponent.h"

class LevelOneFinal : public Final
{
public:

	static Scene* createScene();

	virtual bool init();
	virtual void update(float dt);


	Vec2 LevelOffset = Vec2(Director::getInstance()->getVisibleSize().width, 0);

	int BoundryScale = 1000;

	Sprite* BoundryLeft;
	Sprite* BoundryRight;


	Sprite* ObstacleTest;


	CREATE_FUNC(LevelOneFinal);


};
