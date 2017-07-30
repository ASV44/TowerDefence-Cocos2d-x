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
    
    tanksAmount = 1;
    for(int i = 0; i < tanksAmount; ++i) {
        tanks.push_back(new Tank(gameField->getGrid()));
        this->addChild(tanks[i]);
    }
    
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
                this->addChild(weapon->getBase());
                this->addChild(weapon);
            }
        }
    }
    
    this->gameField->addFieldStones();
    
    this->addChild(gameField->getGrid());
    
    this->scheduleUpdate();
    
    
    
    
   // CCLOG("Scene globa Z %f",this->getGlobalZOrder());
    return true;
}

void MainScene::update(float delta) {
    if(!gameField->isOnDebug()) {
        for(int i = 0; i < weapons.size(); i++)
        {
            checkColision(weapons[i]->getBullets());
            weapons[i]->update(delta);
        }
        for(int i = 0; i < tanks.size(); i++) {
            tanks[i]->move();
        }
    }
    log("");
}

void MainScene::checkColision(vector<Bullet*> bullets)
{
    for(int i = 0; i < bullets.size(); i++) {
        auto bulletPosition = bullets[i]->getPosition();
        for(int j = 0; j < tanks.size(); j++) {
            auto tankPosition = tanks[j]->getPosition();
            auto tankActiveRadius = tanks[j]->getActiveRadius();
            if(bulletPosition.x >= tankPosition.x - tankActiveRadius &&
               bulletPosition.x <= tankPosition.x + tankActiveRadius &&
               bulletPosition.y >= tankPosition.y - tankActiveRadius &&
               bulletPosition.y <= tankPosition.y + tankActiveRadius) {
                tanks[j]->setDamage(bullets[i]->getDamage());
                bullets[i]->setVisible(false);
                if(tanks[j]->getHealth() <= 0) {
                    tanks[j]->reset();
                }
            }
        }
    }
}


























