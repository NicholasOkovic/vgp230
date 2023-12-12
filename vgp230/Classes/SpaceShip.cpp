#include "SpaceShip.h"


SpaceShip* SpaceShip::instance = nullptr;

SpaceShip::SpaceShip()
{

}

SpaceShip* SpaceShip::getInstance()
{
	if (!instance)
	{
		instance = new SpaceShip();
	}
	return instance;
}
