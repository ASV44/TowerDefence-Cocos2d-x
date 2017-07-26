#include "MainScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // add "MainScene" splash screen"
    gameField = Sprite::create("background.png");

    // position the sprite on the center of the screen
    gameField->setAnchorPoint(Vec2(0,0));
    gameField->setPosition(Vec2(origin.x, origin.y));
    gameField->setContentSize(visibleSize);

    // add the sprite as a child to this layer
    this->addChild(gameField, 0);
    
    return true;
}
