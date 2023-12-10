#include "LevelOneFinal.h"


Scene* LevelOneFinal::createScene()
{
	return LevelOneFinal::create();
}



bool LevelOneFinal::init()
{
	auto map = TMXTiledMap::create("tmx/Space_Map.tmx");



	//this->addChild(map, 1);
	//map->setPosition(LevelOffset - Vec2(5,0));

	auto collision = map->getLayer("Collision");

	

	BoundryRight = Sprite::create("blue.jpg");
	this->addChild(BoundryRight);
	BoundryRight->setPosition(LevelOffset.x * 2 + (BoundryRight->getContentSize().width)/2, Director::getInstance()->getVisibleSize().height / 2);
	BoundryRight->setScaleY(BoundryScale);
	BoundryRight->addComponent(CollisionComponent::createBox((BoundryRight->getContentSize().width), BoundryRight->getContentSize().height * BoundryScale));
	BoundryRight->setOpacity(25);

	BoundryLeft = Sprite::create("blue.jpg");
	this->addChild(BoundryLeft);
	BoundryLeft->setPosition(LevelOffset.x - BoundryLeft->getContentSize().width /2, Director::getInstance()->getVisibleSize().height / 2);
	BoundryLeft->setScaleY(BoundryScale);
	BoundryLeft->addComponent(CollisionComponent::createBox((BoundryLeft->getContentSize().width), BoundryLeft->getContentSize().height * BoundryScale));
	BoundryLeft->setOpacity(25);

	ObstacleTest = Sprite::create("AddedImages/asteroids_01.png");
	this->addChild(ObstacleTest);
	ObstacleTest->setPosition(LevelOffset + Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	//ObstacleTest->addComponent(CollisionComponent::createBox((BoundryLeft->getContentSize().width/1.5), BoundryLeft->getContentSize().height/1.5));
	ObstacleTest->setName("Obstacle");

	StartInit(this);
	keyboard->initInput();

	InitializeObstacles(collision, map);

	sceneState = levelOne;
	SpaceShip->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, 500);

	SpaceShip->addComponent(VelocityComponent::create(Vec2(0, 20), 20));
	scheduleUpdate();
	return true;
}





void LevelOneFinal::update(float dt)
{
	MovementAndHud(dt);

	CollisionAndDebug(this);

	PlayerPosition = SpaceShip->getPosition();
	this->_defaultCamera->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, PlayerPosition.y);				///make sure to fix ui
	//this->_defaultCamera->setPosition(PlayerPosition.x, PlayerPosition.y);
}

void LevelOneFinal::InitializeObstacles(TMXLayer* layer, TMXTiledMap* map)
{
	
	for (int i = 0; i < layer->getLayerSize().width; i++)
	{
		for (int j = 0; j < layer->getLayerSize().height; j++)
		{
			if (layer->getTileAt({ (float)i, (float)j }) != NULL)
			{
				//auto position = it->getPosition() + mapOffset + tileOffset;		//iterate over collision, when something isnt null create new sprite using get txture and then it work
				auto tile = layer->getTileAt({ (float)i, (float)j });																					
				//auto TempSprite = Sprite::createWithTexture(tile->getTexture());
				auto TempSprite = Sprite::createWithSpriteFrame(tile->getSpriteFrame());
				this->addChild(TempSprite, 1);
				//TempSprite->setScale(0.5);
				TempSprite->addComponent(CollisionComponent::createBox(tile->getTexture()->getContentSize().width/2.1, tile->getTexture()->getContentSize().height/2.1));
				TempSprite->setPosition(tile->getPosition().x + LevelOffset.x, tile->getPosition().y);
				TempSprite->setName("Obstacle");

				///create sprite using texture tile
				///Create CollisionComponent width / height this can be tested out and changed based upon debug draw
				///add component
				/// add new sprite to scene

				




				//CollisionComponent::createBox(1000, 1000);
				//layer->getTileAt({ (float)i, (float)j })->addComponent(CollisionComponent::createBox(1000, 1000));
				//tile->setScale(10);
				//tile->addComponent(CollisionComponent::createBox(map->getTileSize().width, map->getTileSize().height));
				//Sprite* test = Sprite::create("blue.jpg");
				//test->setPosition(Vec2(layer->getTileAt({ (float)i, (float)j })));
				//test->addComponent(CollisionComponent::createBox(test->getContentSize().width, test->getContentSize().height));
				//layer->getTileAt({ (float)i, (float)j })->/*addComponent(CollisionComponent::createBox(10, 10));*/
				
				//layer->getTileAt({ (float)i, (float)j })->addComponent(CollisionComponent::createBox(layer->getTileAt({ (float)i, (float)j })->getContentSize().width, layer->getTileAt({ (float)i, (float)j })->getContentSize().height));
				
			}
		}
	}

	return;
}


