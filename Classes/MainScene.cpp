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
    
    auto gridSize = gameField->getGrid()->getGridSize();
    auto width = int(gridSize.width);
    auto height = int(gridSize.height);
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            auto cell = gameField->getGrid()->getCell(Point(i,j));
            if(cell->getState() == 2)
            {
                auto weapon = new Weapon(gameField->getGrid(), Point(i,j));
                weapons.push_back(weapon);
                this->addChild(weapon);
                this->addChild(weapon->getBase());
            }
        }
    }
    
    this->scheduleUpdate();
    CCLOG("Scene globa Z %f",this->getGlobalZOrder());
    return true;
}

void MainScene::update(float delta) {
    tank->move();
    for(int i = 0; i < weapons.size(); i++)
    {
        weapons[i]->rotate();
    }
}
