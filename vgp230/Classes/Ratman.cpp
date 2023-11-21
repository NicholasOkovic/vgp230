#include "Ratman.h"


Scene* Ratman::createScene()
{
	return Ratman::create();
}

bool Ratman::init()
{
	auto map = TMXTiledMap::create("tmx/Ratman_Map.tmx");
	this->addChild(map);

	walkable = map->getLayer("Walkable");
	collision = map->getLayer("Collision");
	auto playerStartLayer = map->getLayer("Player");
	auto enemyStartLayer = map->getLayer("Enemy");
	auto victoryLayer = map->getLayer("Victory");

	mapSize = &walkable->getLayerSize();
	tileSize = &walkable->getMapTileSize();

	ratUp = Sprite::create("mouse-0.png");     
	ratUp->setVisible(false);
	ratRight = Sprite::create("mouse-3.png"); 
	//no need to set true
	ratDown = Sprite::create("mouse-6.png");   
	ratDown->setVisible(false);
	ratLeft = Sprite::create("mouse-9.png");  
	ratLeft->setVisible(false);
	hummer1 = Sprite::create("hummer.png");		
	hummer1->setScale(0.25);
	mushroom = Sprite::create("mushroom.png");
	
	drawNode = DrawNode::create();

	map->addChild(ratUp, 5);
	map->addChild(ratRight, 5);
	map->addChild(ratDown, 5);
	map->addChild(ratLeft, 5);
	map->addChild(drawNode, 4);
	map->addChild(hummer1, 4);
	map->addChild(mushroom, 4);
	
	active = ratRight;

	victoryTxt = Label::create();
	victoryTxt->setScale(10);
	victoryTxt->setString("Victory");
	victoryTxt->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	this->addChild(victoryTxt, 6);
	victoryTxt->setVisible(false);

	defeatTxt = Label::create();
	defeatTxt->setScale(10);
	defeatTxt->setString("Defeat");
	this->addChild(defeatTxt, 6);
	defeatTxt->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	defeatTxt->setVisible(false);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
		{
			switch (keyCode)
			{
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
				left = true;
				break;
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
				right = true;
				break;
			case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
				down = true;
				break;
			case EventKeyboard::KeyCode::KEY_UP_ARROW:
				up = true;
				break;
			case EventKeyboard::KeyCode::KEY_L:
				if (debug) {
					drawNode->clear();
					debug = false;
				}
				else
				debug = true;
				break;
			};
		};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	scheduleUpdate();

	initialize(active, playerStartLayer, playerPosition, debug);
	initialize(hummer1, enemyStartLayer, enemyPosition, debug);
	initialize(mushroom, victoryLayer, victoryPosition, debug);

	setCheese(walkable, map);

	playerStartLayer->setVisible(false);

	//dfs test
	dfsVisited.resize((int)mapSize->width);
	for (int i = 0; i < (int)mapSize->width; ++i)
	{
		dfsVisited[i].resize((int)mapSize->height);
	}

	dfsPath.reserve((int)mapSize->width * (int)mapSize->height);

	size = { tileSize->width, tileSize->height };

	gameState = Running;

	return true;
}

void Ratman::initialize(Sprite* spr, TMXLayer* layer, std::pair<int, int>& position, bool draw)
{
	for (int i = 0; i < layer->getLayerSize().width; ++i)
	{
		for (int j = 0; j < layer->getLayerSize().height; ++j)
		{
			if (layer->getTileAt({ (float)i, (float)j }) != NULL && layer->getTileAt({ (float)i, (float)j })->isVisible())
			{
				layer->getTileAt({ (float)i, (float)j })->setVisible(false);
				setPosition(spr, { i, j }, position, draw);
				return;
			}
		}
	}
}
void Ratman::setCheese(TMXLayer* layer, TMXTiledMap* map)
{
	for (int i = 0; i < layer->getLayerSize().width; i++)
	{
		for (int j = 0; j < layer->getLayerSize().height; j++)
		{
			if (layer->getTileAt({ (float)i, (float)j }) != NULL)
			{
				Sprite* cheese = Sprite::create("Cheese.png");
				map->addChild(cheese, 1);
				setPosition(cheese, { i, j }, pair(0,0), debug);
			}
		}
	}
	return;
}

void Ratman::setPosition(Sprite* spr, std::pair<int, int> newPosition, std::pair<int, int>& oldPosition, bool draw)
{ 
	oldPosition = newPosition;

	auto [x, y] = toScreenSpace(newPosition);

	float xp = spr->getBoundingBox().size.width / 2.0f + x;
	float yp = spr->getBoundingBox().size.height / 2.0f + y;

	spr->setPosition(xp, yp);
	
	if (draw)
	{
		Vec2 destination = spr->getPosition() + (Vec2(spr->getContentSize().width, spr->getContentSize().height) / 2);
		drawNode->drawRect(Vec2(xp - spr->getContentSize().width / 2, yp - spr->getContentSize().width / 2), destination, Color4F::RED);
	}
}

bool Ratman::canSetPosition(std::pair<int, int> p)
{
	auto [x, y] = p;

	return
		x >= 0 && x < (int)mapSize->width &&
		y >= 0 && y < (int)mapSize->height &&
		walkable->getTileAt({ (float)x, (float)y }) != NULL;
}

void Ratman::update(float dt)
{
	//movement
	if (gameState == Running)
	{
		if (playerPosition == enemyPosition)
		{
			gameState = Defeat;
			defeatTxt->setVisible(true);
		}
		if (playerPosition == victoryPosition)
		{
			gameState = Victory;
		}

		if (down)
		{
			auto p = make_pair(playerPosition.first, playerPosition.second + 1);

			if (canSetPosition(p))
			{
				changeActiveSprite(ratDown);
				setPosition(active, p, playerPosition, debug);
			}
		}
		else if (left)
		{
			auto p = make_pair(playerPosition.first - 1, playerPosition.second);

			if (canSetPosition(p))
			{
				changeActiveSprite(ratLeft);
				setPosition(active, p, playerPosition, debug);
			}
		}
		else if (up)
		{
			auto p = make_pair(playerPosition.first, playerPosition.second - 1);

			if (canSetPosition(p))
			{
				changeActiveSprite(ratUp);
				setPosition(active, p, playerPosition, debug);
			}
		}
		else if (right)
		{
			auto p = make_pair(playerPosition.first + 1, playerPosition.second);

			if (canSetPosition(p))
			{
				changeActiveSprite(ratRight);
				setPosition(active, p, playerPosition, debug);
			}
		}

		if (EnemyTimer == 0)
		{
			setPosition(hummer1, dfsPath[1], enemyPosition, debug);
			EnemyTimer = 25;
		}
		EnemyTimer--;

		//debug && dfs
		reset(dfsVisited, dfsPath, false);
		if (int l = dfs(playerPosition, enemyPosition, 0); l != -1)
		{
			if (debug)
			{
				drawNode->clear();
				setPosition(active, playerPosition, playerPosition, debug);
				drawVisited(dfsVisited, Color4F::ORANGE, { 0.0f,0.0f }, size, false);
				drawPath(dfsPath, { 0.0f, 0.0f }, Color4F::RED);
			}		
		}
	}
	else if (gameState == Victory)
	{
		victoryTxt->setVisible(true);
		active->setRotation(active->getRotation() + 360 * dt);
	}
	ResetInput();
}

void Ratman::changeActiveSprite(Sprite* newActive)
{
	active->setVisible(false);
	active = newActive;
	active->setVisible(true);
}

void Ratman::ResetInput()
{
	down = false;
	left = false;
	up = false;
	right = false;
}

int Ratman::dfs(std::pair<int, int> current, std::pair<int, int>const& target, int depth)
{
	if (dfsVisited[current.first][current.second] || walkable->getTileAt(Vec2(current.first, current.second)) == NULL)
	{
		return -1;
	}
	dfsVisited[current.first][current.second] = true;
	++depth;

	if (current == target)
	{
		dfsPath.push_back(current);			
		return depth;
	}

	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			if (x != y && !(x == -1 && y == 1) && !(x == 1 && y == -1))
			{
				if (depth = dfs(pair(current.first + x, current.second + y), target, depth) != -1)
				{
					dfsPath.push_back(current);
					return depth;
				}
			}
		}
	}
	return -1;
}

