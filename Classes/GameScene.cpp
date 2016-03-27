#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

	scene->getPhysicsWorld()->setGravity(Vec2(0, -500));

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    _screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 3. add your codes below...
	
    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
	
    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	_playerPawn.PlaceOnScreen(_screenSize.width / 2 + origin.x, _screenSize.height / 2 + origin.y);

	_playerPawn.AddAsChild(this);

	//this->addChild(&_playerPawn,1);

	

	// add the sprite as a child to this layer
    //this->addChild(sprite, 0);

	auto touchListner = EventListenerTouchOneByOne::create();
	touchListner->setSwallowTouches(true);
	touchListner->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);

	CCDirector::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListner, this);
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //auto rootNode = CSLoader::createNode("MainScene.csb");

    //addChild(rootNode);

    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * touchEvent)
{
	Vec2 location = touch->getLocation();

	if (location.x > _screenSize.width / 2)
	{
		_playerPawn.JumpRight();
	}
	else
	{
		_playerPawn.JumpLeft();
	}

	return false;
}
