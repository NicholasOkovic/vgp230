#pragma once
#include "Final.h"

class Trophy : public Final
{
public:
	static Scene* createScene();

	virtual bool init();
	virtual void update(float dt);


	CREATE_FUNC(Trophy);

private:

};
