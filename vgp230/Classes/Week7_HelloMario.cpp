#include "Week7_HelloMario.h"


Scene* HelloMario::createScene()
{
  auto ret = new (std::nothrow) HelloMario();
  if (ret && ret->initWithPhysics() && ret->init())
  {
    ret->autorelease();
    return ret;
  }
  else
  {
    CC_SAFE_DELETE(ret);
    return nullptr;
  }

  return ret;
}

bool HelloMario::init()
{
  if (!cocos2d::Scene::init()) 
  {
    return false;
  }

  auto visibleSize = _director->getVisibleSize();
  auto origin = _director->getVisibleOrigin();

  /// TODO Design your own level(s)
  auto level = TMXTiledMap::create("Mario/tmx/MarioSampleLevel.tmx");

  this->addChild(level);

  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Mario/mario.plist");
  walkingFrames = getAnimation("mario_walk_%02d", 3);
  idleFrames = getAnimation("mario_idle_%02d", 2);
  fallingFrames = getAnimation("mario_fall_%02d", 1);
  jumpingFrames = getAnimation("mario_jump_%02d", 1);

  mario = Sprite::createWithSpriteFrame(idleFrames.front());
  addChild(mario);
  mario->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
  mario->setScale(2);

  auto animation = Animation::createWithSpriteFrames(idleFrames, 1.0f);
  mario->runAction(RepeatForever::create(Animate::create(animation)));
  

  controller = KeyboardControllerComponent::create(KeyboardControllerComponent::ARROWS);
  mario->addComponent(controller);
  controller->initInput();

  InitPhysics(level);

  scheduleUpdate();

  return true;
}

void HelloMario::InitPhysics(TMXTiledMap* level)
{
  auto physicsWorld = getPhysicsWorld();
  physicsWorld->setGravity(cocos2d::Vec2(0, -980));

  ///TODO: make code below toggleable (aka can turn on and off debug draw) 
  physicsWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

  marioPhysicsBody = cocos2d::PhysicsBody::createBox(mario->getContentSize(), PHYSICSSHAPE_MATERIAL_DEFAULT);

  
  marioPhysicsBody->setRotationEnable(false);
  ///TODO: Disallow mario's rotation to be effected by physics
  marioPhysicsBody->setDynamic(true);
  ///TODO: Set mario to be dynamic (physics is applied to it)

  marioPhysicsBody->setCategoryBitmask(1);
  marioPhysicsBody->setCollisionBitmask(2);
  marioPhysicsBody->setContactTestBitmask(2);
  ///TODONE: Set mario physics body's category bitmask
  ///TODONE: Set mario physics body's collision bitmask
  ///TODONE: Set mario physics body's contact test bitmask
  mario->setPhysicsBody(marioPhysicsBody);

  contacts.reserve(5);

  auto collisionLayer = level->getLayer("Collision");
  for (int row = 0; row < level->getMapSize().height; ++row)
  {
    for (int col = 0; col < level->getMapSize().width; ++col)
    {
      auto tile = collisionLayer->getTileAt(cocos2d::Vec2(col, row));
      if (tile)
      {
        auto physicsBody = cocos2d::PhysicsBody::createBox(tile->getContentSize(), PHYSICSSHAPE_MATERIAL_DEFAULT);
        physicsBody->setDynamic(false);

        physicsBody->setCategoryBitmask(2);
        ///TODONE: set tile category bitmask 
        physicsBody->setCollisionBitmask(1);
        ///TODONE: set tile collision bitmask 
        physicsBody->setContactTestBitmask(1);
        ///TODONE: set tile contact test bitmask 
        tile->setPhysicsBody(physicsBody);
      }
    }
  }

  auto contactListener = EventListenerPhysicsContact::create();
  contactListener->onContactBegin = [=](PhysicsContact& contact) -> bool
  {
    auto a = contact.getShapeA()->getBody();
    auto b = contact.getShapeB()->getBody();

    auto other = marioPhysicsBody == a ? b : a;

    if (marioPhysicsBody->getPosition().y > other->getPosition().y && abs(contact.getContactData()->normal.y) > 0.9f)
    {
      contacts.push_back(other);
    }

    return true;
  };
  contactListener->onContactSeparate = [=](PhysicsContact& contact)
  {
    auto a = contact.getShapeA()->getBody();
    auto b = contact.getShapeB()->getBody();

    auto separate = marioPhysicsBody == a ? b : a;

    for (int i = 0; i < contacts.size(); ++i)
    {
      if (contacts[i] == separate)
      {
        contacts[i] = contacts[contacts.size() - 1];
        contacts.pop_back();
        break;
      }
    }
  };
  _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void HelloMario::update(float dt)
{
  auto contact = contacts.size() > 0;

  if (contact) /// mario is on the ground
  {
    if (controller->IsLeftPressed())
    {

      mario->setPosition(Vec2(mario->getPosition().x - 200 * dt, mario->getPosition().y));
      mario->setScaleX(-2);
      /// TODO:
      /// Move mario left with some velocity
      /// Set Position, and Flip X scale to negative
      if (animationState != Walking)
      {
          animationState = Walking;
          mario->stopAllActions();
          auto animation = Animation::createWithSpriteFrames(walkingFrames, 1.0f);
          mario->runAction(RepeatForever::create(Animate::create(animation)));

      }
      /// Check if not in walking state + switch to walking animation
    }
    else if (controller->IsRightPressed())
    {
       mario->setPosition(Vec2(mario->getPosition().x + 200 * dt, mario->getPosition().y));
       mario->setScaleX(2);
      /// TODO:
      /// Move mario right with some velocity
      /// Set Position, and Flip X scale to positive
       if (animationState != Walking)
       {
           animationState = Walking;
           mario->stopAllActions();
           auto animation = Animation::createWithSpriteFrames(walkingFrames, 1.0f);
           mario->runAction(RepeatForever::create(Animate::create(animation)));

       }
      /// check if not walking + switch to walking
    }
    
    if (controller->IsDownPressed())
    {
      /// TODO (optional):
      /// Make mario crouch
    }
    
    if (controller->IsUpPressed())
    {
      /// TODO:

        //marioPhysicsBody->applyImpulse(Vec2(0, 50));

        if (animationState != Jumping)
        {
            marioPhysicsBody->applyImpulse(Vec2(0, 750));
            animationState = Jumping;
            mario->stopAllActions();
            auto animation = Animation::createWithSpriteFrames(jumpingFrames, 1.0f);
            mario->runAction(RepeatForever::create(Animate::create(animation)));

        }
      ///Check if not in jumping state
        /// Apply an impulse force to mario to make him jump
        /// switch to jumping animation / sprite
    }

    if (!controller->IsLeftPressed() && !controller->IsRightPressed() && !controller->IsDownPressed() && !controller->IsUpPressed())
    {
      /// TODO:
      animationState = Idle;
      mario->stopAllActions();
      auto animation = Animation::createWithSpriteFrames(idleFrames, 1.0f);
      mario->runAction(Animate::create(animation));
      /// switch to idle animation
    }
  }
  else
  {
    if (controller->IsLeftPressed())
    {
      /// TODO:
      mario->setPosition(Vec2(mario->getPosition().x - 200 * dt, mario->getPosition().y));
      mario->setScaleX(-2);
      /// Move mario left with some velocity
      /// Set Position, and Flip X scale to negative
    }
    else if (controller->IsRightPressed())
    {
      /// TODO:
        mario->setPosition(Vec2(mario->getPosition().x + 200 * dt, mario->getPosition().y));
        mario->setScaleX(2);
      /// Move mario right with some velocity
      /// Set Position, and Flip X scale to positive
    }

    if (animationState != Falling && mario->getPhysicsBody()->getVelocity().y < 0)
    {
      /// TODO:
        animationState = Falling;
        mario->stopAllActions();
        auto animation = Animation::createWithSpriteFrames(fallingFrames, 1.0f);
        mario->runAction(RepeatForever::create(Animate::create(animation)));
      /// change animation to falling animation
    }
  }

  /// TODO:
    
  /// Set camera to follow mario
}