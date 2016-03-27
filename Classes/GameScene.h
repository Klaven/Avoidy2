#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "AvoidyPawn.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* touchEvent);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
	AvoidyPawn _playerPawn;
	cocos2d::Size _screenSize;
};

#endif // __GAME_SCENE_H__
