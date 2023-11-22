#include "Week8_HelloMario2.h"

#pragma warning(push)
#pragma warning(disable: 4996)
#include "json/document.h"
#include "json/prettywriter.h"
#include "json/stringbuffer.h"
#pragma warning(pop)


Scene* HelloMario2::createScene()
{
  auto ret = new (std::nothrow) HelloMario2();
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

bool HelloMario2::init()
{
    load();

  /// TODONE: call load() which loads the save file

  if (!HelloMarioSolution::init())
  {
    return false;
  }

  initPauseMenu();

  auto keyboardListener = EventListenerKeyboard::create();
  keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
  {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        if (menu->isVisible())
        {
             hidePauseMenu();
        }
        else
        {
            showPauseMenu();
        }
      /// TODO: call showPauseMenu / hidePauseMenu depending on if menu is visible
    }
  };

  auto dispatcher = Director::getInstance()->getEventDispatcher();

  dispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

  return true;
}

void HelloMario2::initPauseMenu()
{
  // Create "New Game" button
  auto newGameButton = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("New Game", "fonts/Marker Felt.ttf", 24), [](cocos2d::Ref* sender) 
  {
    /// Bonus: Reset the game
  });
  auto saveGameButton = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Save Game", "fonts/Marker Felt.ttf", 24), [](cocos2d::Ref* sender)
      {
         
      });
  /// TODO: Create save button which calls the "save()" function

  /// TODO: Create load button which calls the "load()" button

  /// TODO: Create Quit button

  /// TODO: add buttons to menu

  // TODO: add buttons into menu below
  menu = cocos2d::Menu::create(newGameButton, nullptr);
  menu = cocos2d::Menu::create(saveGameButton, nullptr);
  menu->alignItemsVerticallyWithPadding(20);

  // Add the menu to the scene
  this->addChild(menu);

  hidePauseMenu();
}

void HelloMario2::showPauseMenu() 
{
  auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();
  auto pos = Vec2{ cocos2d::Director::getInstance()->getVisibleSize() * 0.5f } + origin;

  Vec2 screenCenter = Director::getInstance()->getVisibleSize() * 0.5f;

  // Get the camera's position
  Vec2 cameraPosition = _defaultCamera->getPosition();

  // Calculate the offset for the menu's position
  Vec2 menuOffset = cameraPosition - screenCenter;

  /// TODO: Pause Physics from updating

  menu->setPosition(pos + menuOffset);
  menu->setVisible(true);
}

void HelloMario2::hidePauseMenu()
{
    
  /// TODO: Resume Physics from updating
    menu->setVisible(false);
  /// TODO: Hide menu
}

void HelloMario2::update(float dt)
{
  ///TODO: If menu is open, don't call below
  HelloMarioSolution::update(dt);
}

void HelloMario2::load()
{
  std::string jsonString = cocos2d::FileUtils::getInstance()->getStringFromFile("Mario.json");

  if (jsonString != "")
  {
    rapidjson::Document document;
    document.Parse(jsonString.c_str());
    
    if (document.HasParseError()) 
    {
      std::stringstream ss;
      ss << "Error parsing JSON: ErrorCode " << document.GetParseError();
      std::string s = ss.str();
      return;
    }
    
    if (document.HasMember("WalkSpeed") && document["WalkSpeed"].IsFloat()) 
    {
      document.AddMember("WalkSpeed", walkSpeed, document.GetAllocator());
      ///TODO: Add variable walkSpeed to base class, then uncomment line below ///
      walkSpeed = document["WalkSpeed"].GetFloat();
    }
    document.AddMember("JumpSpeed", jumpSpeed, document.GetAllocator());
    jumpSpeed = document["JumpSpeed"].GetFloat();
    ///TODONE: load JumpSpeed into jumpSpeed -- Add variable to base class
    document.AddMember("Scale", scale, document.GetAllocator());
    scale = document["Scale"].GetFloat();
    ///TODONE: load Scale into scale -- Add variable to base class

    if (document.HasMember("StartPosition") && document["StartPosition"].IsObject())
    {
      auto obj = document["StartPosition"].GetObjectW();
      float x = obj.HasMember("X") && obj["X"].IsFloat() ? obj["X"].GetFloat() : 0.0f;
      float y = obj.HasMember("Y") && obj["Y"].IsFloat() ? obj["Y"].GetFloat() : 0.0f;
      ///TODONE: load "Y" parameter
      document.AddMember("StartPosition", obj, document.GetAllocator());
      ///TODONE: Add variable startPosition to base class, then uncomment line below
      startPosition = { x, y };
    }
  }
}

void HelloMario2::save()
{
  rapidjson::Document document;
  document.SetObject();


  ///TODO: add walkSpeed to base class then uncomment line below
  document.AddMember("WalkSpeed", walkSpeed, document.GetAllocator());
  document.AddMember("JumpSpeed", jumpSpeed, document.GetAllocator());
  ///TODO: save JumpSpeed
  document.AddMember("Scale", scale, document.GetAllocator());
  ///TODO: save Scale (mario size)

  rapidjson::Value start(rapidjson::kObjectType);
  /// TODO: add marios position into "X", and "Y" members inside of start 
  document.AddMember("StartPosition", start, document.GetAllocator());
  
  rapidjson::StringBuffer buffer;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
  document.Accept(writer);

  std::string jsonStr = buffer.GetString();

  auto fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename("Mario.json");
  cocos2d::FileUtils::getInstance()->writeStringToFile(jsonStr, fullPath);

  /// TODO: Write json string to fullPath using FileUtils (writeStringToFile)
}