#include "LevelOneFinal.h"


Scene* LevelOneFinal::createScene()
{
	return LevelOneFinal::create();
}



bool LevelOneFinal::init()
{
	SpaceShip::getInstance()->LevelOneTime = 0;


	auto map = TMXTiledMap::create("tmx/Space_Map.tmx");



	///Obstacles


	Asteroid7_01 = Sprite::create("AddedImages/asteroids_07.png");
	

	Asteroid7_02 = Sprite::create("AddedImages/asteroids_07.png");

	Asteroid7_03 = Sprite::create("AddedImages/asteroids_07.png");

	Asteroid7_04 = Sprite::create("AddedImages/asteroids_07.png");

	Asteroid7_05 = Sprite::create("AddedImages/asteroids_07.png");

	Asteroid11_01 = Sprite::create("AddedImages/asteroids_011.png");

	Asteroid11_02 = Sprite::create("AddedImages/asteroids_011.png");

	Asteroid11_03 = Sprite::create("AddedImages/asteroids_011.png");

	Asteroid11_04 = Sprite::create("AddedImages/asteroids_011.png");

	Asteroid11_05 = Sprite::create("AddedImages/asteroids_011.png");

	LargeAstroid_01 = Sprite::create("AddedImages/Meteor_01.png");
	this->addChild(LargeAstroid_01);
	LargeAstroid_01->setScale(2);
	LargeAstroid_01->addComponent(CollisionComponent::createBox(LargeAstroid_01->getContentSize().width * LargeAstroid_01->getScaleX(), LargeAstroid_01->getContentSize().height * LargeAstroid_01->getScaleY()));
	LargeAstroid_01->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height/2);
	LargeAstroid_01->setRotation(180);

	LargeAstroid_02 = Sprite::create("AddedImages/Meteor_05.png");
	this->addChild(LargeAstroid_02);
	LargeAstroid_02->setScale(0.2);
	LargeAstroid_02->addComponent(CollisionComponent::createBox(LargeAstroid_02->getContentSize().width * LargeAstroid_02->getScaleX(), LargeAstroid_02->getContentSize().height * LargeAstroid_02->getScaleY()));
	LargeAstroid_02->setPosition(LevelOffset.x, Director::getInstance()->getVisibleSize().height / 2);


	LargeAstroid_03 = Sprite::create("AddedImages/Meteor_05.png");
	this->addChild(LargeAstroid_03);
	LargeAstroid_03->setScale(0.6);
	LargeAstroid_03->addComponent(CollisionComponent::createBox(LargeAstroid_03->getContentSize().width * LargeAstroid_03->getScaleX(), LargeAstroid_03->getContentSize().height * LargeAstroid_03->getScaleY()));
	LargeAstroid_03->setPosition(LevelOffset.x, Director::getInstance()->getVisibleSize().height * 1.8);
	LargeAstroid_03->setRotation(180);


	LargeAstroid_04 = Sprite::create("AddedImages/Meteor_04.png");
	this->addChild(LargeAstroid_04);
	LargeAstroid_04->setScale(1);
	LargeAstroid_04->addComponent(CollisionComponent::createBox(LargeAstroid_04->getContentSize().width * LargeAstroid_04->getScaleX()/ 1.2, LargeAstroid_04->getContentSize().height * LargeAstroid_04->getScaleY()/1.2));
	LargeAstroid_04->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height * 2);
	LargeAstroid_04->setRotation(140);

	LevelOneItem_01 = Sprite::create("AddedImages/Gold_bar.webp");
	this->addChild(LevelOneItem_01);
	LevelOneItem_01->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width / 6, Director::getInstance()->getVisibleSize().height * 1.2);
	LevelOneItem_01->setScale(0.2);
	LevelOneItem_01->addComponent(CollisionComponent::createBox(LevelOneItem_01->getContentSize().width * LevelOneItem_01->getScaleX(), LevelOneItem_01->getContentSize().height * LevelOneItem_01->getScaleY()));
	LevelOneItem_01->setName("Item1-1");

	LevelOneItem_02 = Sprite::create("AddedImages/Golden_Ore.png");
	this->addChild(LevelOneItem_02);
	LevelOneItem_02->setPosition(LevelOffset.x + Director::getInstance()->getVisibleSize().width/ 1.5, 0 + Director::getInstance()->getVisibleSize().height * 2);
	LevelOneItem_02->setScale(0.02);
	LevelOneItem_02->addComponent(CollisionComponent::createBox(LevelOneItem_02->getContentSize().width * LevelOneItem_02->getScaleX(), LevelOneItem_02->getContentSize().height * LevelOneItem_02->getScaleX()));
	LevelOneItem_02->setName("Item1-2");




	//this->addChild(map, 1);
	//map->setPosition(LevelOffset - Vec2(5,0));

	//auto collision = map->getLayer("Collision");

	

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

	LevelSelectCol = Sprite::create("blue.jpg");
	this->addChild(LevelSelectCol, 1);
	LevelSelectCol->addComponent(CollisionComponent::createBox(LevelSelectCol->getContentSize().width, LevelSelectCol->getContentSize().height));
	LevelSelectCol->setPosition(LevelOffset + Vec2(Director::getInstance()->getVisibleSize().width/2 , Director::getInstance()->getVisibleSize().height * 3));
	LevelSelectCol->setName("LevelSelect");

	StartInit(this);
	keyboard->initInput();

	

	sceneState = levelOne;
	SpaceShip->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, 500);

	SpaceShip->addComponent(VelocityComponent::create(Vec2(0, 20), 20));
	scheduleUpdate();
	return true;
}





void LevelOneFinal::update(float dt)
{
	SpaceShip::getInstance()->LevelOneTime += (1 * dt);

	MovementAndHud(dt, this);

	CollisionAndDebug(this);

	PlayerPosition = SpaceShip->getPosition();
	this->_defaultCamera->setPosition(Director::getInstance()->getVisibleSize().width * 1.5, PlayerPosition.y);				
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


