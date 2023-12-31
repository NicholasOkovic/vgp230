#pragma once

#include "cocos2d.h"
#include "CollisionComponent.h"

USING_NS_CC;

class CollisionTestScene : public Scene
{
public:
    /*static Scene* CollisionTestScene::createScene()
    {
        return CollisionTestScene::create();
    }*/
  static Scene* createScene();

  virtual bool init();

  virtual void update(float dt);

  CREATE_FUNC(CollisionTestScene)
private:
  Node* active;
  Sprite* stone;
  Sprite* mushroom;
  Sprite* bullet2;
  Sprite* hummer;
  Sprite* circle;

  DrawNode* debug;

  bool left;
  bool right;
  bool up;
  bool down;
  bool debugDrawEnabled = true;
};