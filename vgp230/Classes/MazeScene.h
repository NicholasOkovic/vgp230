#pragma once

#include "cocos2d.h"

USING_NS_CC;

class MazeScene : public Scene
{
public:
  static Scene* createScene();

  virtual bool init();

  virtual void update(float dt);

  void initialize(Sprite* spr, TMXLayer* layer, std::pair<int, int>& position);

  void setPosition(Sprite* spr, std::pair<int, int> playerPosition, std::pair<int, int>& oldPosition);

  bool canSetPosition(std::pair<int, int> playerPosition);

  void changeActiveSprite(Sprite* newActive);

  CREATE_FUNC(MazeScene)

protected:
  const Size* mapSize;
  const Size* tileSize;

  std::pair<int, int> playerPosition;
  std::pair<int, int> endPosition;

  TMXLayer* path = NULL;
  DrawNode* drawNode = NULL;
private:
  std::pair<float, float> toScreenSpace(std::pair<int, int>const& position)
  {
    return toScreenSpaceT<std::pair<float, float>>(position);
  }
  template<typename T>
  T toScreenSpaceT(std::pair<int, int>const& position)
  {
    return
    {
      tileSize->width * (float)position.first,
      tileSize->height * (float)((int)mapSize->height - position.second - 1)
    };
  }

  enum GameState
  {
    Start,
    Running,
    FoundCheese,
    Victory
  } gameState = Start;

  TMXLayer* collision;

  Sprite* active = NULL;
  Sprite* ratDown = NULL;
  Sprite* ratLeft = NULL;
  Sprite* ratUp = NULL;
  Sprite* ratRight = NULL;
  Sprite* cheese = NULL;

  float cheeseAnimationTimer = 0;

  void ResetInput();

  bool down = false;
  bool left = false;
  bool up = false;
  bool right = false;
};