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
  mario = Sprite::create("mario.png");
  mario->setScale(0.2);
  mario->setVisible(false);

  cheese = Sprite::create("Cheese.png");

  drawNode = DrawNode::create();

  map->addChild(ratUp, 5);
  map->addChild(ratRight, 5);
  map->addChild(ratDown, 5);
  map->addChild(ratLeft, 5);
  map->addChild(drawNode, 4);
  map->addChild(cheese, 4);
  map->addChild(mario, 5);

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
  initialize(cheese, playerEndLayer, endPosition, false);                      

  playerStartLayer->setVisible(false);
  playerEndLayer->setVisible(false);

  gameState = Running;

  return true;
}

void MazeScene::initialize(Sprite* spr, TMXLayer* layer, std::pair<int, int>& position, bool draw)
{
  /// TODONE: Loop over all layer tiles, 
    for (int i = 0; i < layer->getLayerSize().width; i++)
    {
        for (int j = 0; j < layer->getLayerSize().height; j++)
        {
            if (layer->getTileAt({(float)i, (float)j }) != NULL)
            {
                setPosition(spr, { i, j }, position, draw);
                return;
            }
        }
    }
    /// check if is starting tile
      /// Call setPosition(spr, std::make_pair(i, j), position, draw); 
    
}

void MazeScene::setPosition(Sprite* spr, std::pair<int, int> newPosition, std::pair<int, int>& oldPosition, bool draw)
{
  oldPosition = newPosition;

  /// TODO: Flip y
  auto v = Vec2
  {
      tileSize->width* (float)newPosition.first,
          tileSize->height* (float)((int)mapSize->height - newPosition.second - 1)
  };

  auto x = v.x;
  auto y = v.y;

  float xp = spr->getBoundingBox().size.width / 2.0f + x;
  float yp = spr->getBoundingBox().size.height / 2.0f + y;

  spr->setPosition(xp, yp);

  /// TODO: Calculate new x/y of sprite

  /// TODO: Add sprite bounding box offsets
  

  /// TODO: Set spr to that position

  if (draw)
  {
    /// TODO: Add drawing of rectangle around "spr"
      Vec2 destination = spr->getPosition() + (Vec2(spr->getContentSize().width, spr->getContentSize().height)/2);
      drawNode->drawRect(Vec2(xp - spr->getContentSize().width/2, yp - spr->getContentSize().width/2), destination, Color4F::RED);
  }
}

bool MazeScene::canSetPosition(std::pair<int, int> p)
{
  /// TODO: determine if location can be walked on

    if (path->getTileAt(Vec2(p.first, p.second)) == NULL)
    {
        return false;
    }

  return true;
}

void MazeScene::update(float dt)
{
  /// TODO: Check if game state is running
    if (gameState != Running)
    {
        return;
    }
  {
    if (down)
    {
      /// TODO: fix line below and determine correct new location
      auto p = std::make_pair(playerPosition.first, playerPosition.second + 1);

      if (canSetPosition(p))
      {
        /// TODO: call Change Active Sprite
        changeActiveSprite(ratDown);
        setPosition(active, p, playerPosition);
       
      }
    }
    else if (left)
    {
      /// TODO: fix line below and determine correct new location
      auto p = std::make_pair(playerPosition.first - 1, playerPosition.second);

      if (canSetPosition(p))
      {
        /// TODO: call Change Active Sprite
        changeActiveSprite(ratLeft);
        setPosition(active, p, playerPosition);
      }
    }
    else if (up)
    {
      /// TODO: fix line below and determine correct new location
      auto p = std::make_pair(playerPosition.first, playerPosition.second -1);

      if (canSetPosition(p))
      {
        /// TODO: call Change Active Sprite
        changeActiveSprite(ratUp);
        setPosition(active, p, playerPosition);
      }
    }
    else if (right)
    {
      /// TODO: fix line below and determine correct new location
      auto p = std::make_pair(playerPosition.first + 1, playerPosition.second);

      if (canSetPosition(p))
      {
        /// TODO: call Change Active Sprite
        changeActiveSprite(ratRight);
        setPosition(active, p, playerPosition);
      }
    }

    if (playerPosition == endPosition)
    {
        gameState = FoundCheese;
    }

    /// TODO: check if player has reached the end position, and change game state
  }
  if (gameState == FoundCheese)
  {
      gameState == Victory;
      changeActiveSprite(mario);
      setPosition(active, playerPosition, playerPosition);
      cheese->setVisible(false);
  }
  /// TODO: check if game state has found the cheese, and apply some victory effect

  ResetInput();
}

void MazeScene::changeActiveSprite(Sprite* newActive)
{
  /// hide "active", then assign active to newActive, then make visible!
    active->setVisible(false);
    active = newActive;
    newActive->setVisible(true);
}

void MazeScene::ResetInput()
{
  down = false;
  left = false;
  up = false;
  right = false;
}

