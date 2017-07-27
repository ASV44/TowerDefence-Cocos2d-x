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

    gameField = new GameField();
    this->addChild(gameField);
    
    tank = new Tank(gameField->getGrid());
    this->addChild(tank);
    
    this->scheduleUpdate();
    CCLOG("Scene globa Z %f",this->getGlobalZOrder());
    return true;
}

void MainScene::update(float delta) {
    tank->move();
}
