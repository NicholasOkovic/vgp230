#include "MazeScene.h"

Scene* MazeScene::createScene()
{
  return MazeScene::create();
}

bool MazeScene::init()
{
  auto map = TMXTiledMap::create("tmx/desert.tmx");
  path = map->getLayer("Path");
  collision = map->getLayer("Collision");
  auto playerStartLayer = map->getLayer("Player");
  auto playerEndLayer = map->getLayer("Player End");

  mapSize = &path->getLayerSize();
  tileSize = &path->getMapTileSize();

  this->addChild(map);

  map->setScale(1.5f);

  ratUp = Sprite::create("mouse-0.png");     //0, 1, 2
  ratUp->setVisible(false);
  ratRight = Sprite::create("mouse-3.png");  //3, 4, 5
  ratDown = Sprite::create("mouse-6.png");   //6, 7, 8
  ratDown->setVisible(false);
  ratLeft = Sprite::create("mouse-9.png");   //9, 10, 11
  ratLeft->setVisible(false);

  cheese = Sprite::create("Cheese.png");

  drawNode = DrawNode::create();

  map->addChild(ratUp, 5);
  map->addChild(ratRight, 5);
  map->addChild(ratDown, 5);
  map->addChild(ratLeft, 5);
  map->addChild(drawNode, 4);
  map->addChild(cheese, 4);

  active = ratRight;

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
    };
  };

  _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

  this->scheduleUpdate();

  initialize(active, playerStartLayer, playerPosition);
  initialize(cheese, playerEndLayer, endPosition);

  playerStartLayer->setVisible(false);
  playerEndLayer->setVisible(false);

  gameState = Running;

  return true;
}

void MazeScene::initialize(Sprite* spr, TMXLayer* layer, std::pair<int, int>& position)
{
  for (int i = 0; i < layer->getLayerSize().width; ++i)
  {
    for (int j = 0; j < layer->getLayerSize().height; ++j)
    {
      if (layer->getTileAt({ (float)i, (float)j }) != NULL)
      {
        setPosition(spr, { i, j }, position);
        return;
      }
    }
  }
}

void MazeScene::setPosition(Sprite* spr, std::pair<int, int> newPosition, std::pair<int, int>& oldPosition)
{
  oldPosition = newPosition;

  auto [x, y] = toScreenSpace(newPosition);

  float xp = spr->getBoundingBox().size.width / 2.0f + x;
  float yp = spr->getBoundingBox().size.height / 2.0f + y;

  spr->setPosition(xp, yp);
}

bool MazeScene::canSetPosition(std::pair<int, int> p)
{
  auto [x, y] = p;

  return 
    x >= 0 && x < (int)mapSize->width && 
    y >= 0 && y < (int)mapSize->height && 
    path->getTileAt({ (float)x, (float)y }) != NULL;
}

void MazeScene::update(float dt)
{
  drawNode->clear();

  if (gameState == Running)
  {
    if (down)
    {
      auto p = std::make_pair(playerPosition.first, playerPosition.second + 1);

      if (canSetPosition(p))
      {
        changeActiveSprite(ratDown);
        setPosition(active, p, playerPosition);
      }
    }
    else if (left)
    {
      auto p = std::make_pair(playerPosition.first - 1, playerPosition.second);

      if (canSetPosition(p))
      {
        changeActiveSprite(ratLeft);
        setPosition(active, p, playerPosition);
      }
    }
    else if (up)
    {
      auto p = std::make_pair(playerPosition.first, playerPosition.second - 1);

      if (canSetPosition(p))
      {
        changeActiveSprite(ratUp);
        setPosition(active, p, playerPosition);
      }
    }
    else if (right)
    {
      auto p = std::make_pair(playerPosition.first + 1, playerPosition.second);

      if (canSetPosition(p))
      {
        changeActiveSprite(ratRight);
        setPosition(active, p, playerPosition);
      }
    }

    if (playerPosition == endPosition)
    {
      gameState = FoundCheese;
      cheeseAnimationTimer = 0;
    }
  }
  else if (gameState == FoundCheese)
  {
    cheeseAnimationTimer += dt;
    active->setRotation(active->getRotation() + 360 * dt);

    if (cheeseAnimationTimer > 2)
    {
      gameState = Victory;
    }
  }

  ResetInput();
}

void MazeScene::changeActiveSprite(Sprite* newActive)
{
  active->setVisible(false);
  active = newActive;
  active->setVisible(true);
}

void MazeScene::ResetInput()
{
  down = false;
  left = false;
  up = false;
  right = false;
}

