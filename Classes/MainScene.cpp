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
    
    this->createWeapons(gameField->getGrid());
    
    tanksAmount = 10;
    for(int i = 0; i < tanksAmount; ++i) {
        gameObjects.push_back(new Tank(gameField->getGrid()));
        this->addChild(gameObjects.back(),3);
        this->gameObjects.back()->addNodes();
    }
    
    this->gameField->addFieldStones();
    
    this->addChild(gameField->getGrid());
    
    this->scheduleUpdate();
    
    this->updateSceneWeapons = false;
    
    this->castSceneObjects();
    
    auto listener = EventListenerTouchOneByOne::create();
    //listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](Touch* touch, Event* event){
        // your code
        log("Main Scene Touch Began");
        return true; // if you are consuming it
    };
    
    listener->onTouchMoved = [&](Touch* touch, Event* event){
        //        auto location = touch->getLocation() - origin;
        //        stones[2]->setPosition(location);
        //        CCLOG("X:%f Y:%f",location.x, location.y);
        return true;
    };
    
    listener->onTouchEnded = [&](Touch* touch, Event* event){
        log("Main Scene Touch End");
        if(gameField->isOnDebug() && !updateSceneWeapons) {
            updateSceneWeapons = true;
        }
        else if (!gameField->isOnDebug() && updateSceneWeapons){
            this->updateWeaponsOnScene();
            updateSceneWeapons = false;
        }
        return true;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    //explosion->check();
    
    
   // CCLOG("Scene globa Z %f",this->getGlobalZOrder());
    return true;
}

void MainScene::update(float delta) {
    if(!gameField->isOnDebug()) {
        for(int i = 0; i < gameObjects.size(); i++)
        {
            if(gameObjects[i]->getType() == GameObject::WEAPON) {
                checkColision(gameObjects[i]->castObject<Weapon>()->getBullets());
            }
            gameObjects[i]->update(delta);
        }
    }
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
               bulletPosition.y <= tankPosition.y + tankActiveRadius)
            {
                affectTank(tanks[j], bullets[i]);
                if(tanks[j]->getHealth() <= 0) {
                    tanks[j]->expload();
                    tanks[j]->reset();
                }
            }
        }
    }
}

void MainScene::createWeapons(Grid *grid)
{
    auto gridSize = grid->getGridSize();
    auto width = int(gridSize.width);
    auto height = int(gridSize.height);
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            auto cell = gameField->getGrid()->getCell(Point(i,j));
            if(cell->getState() >= 2) {
                createWeapon(cell->getState(), Point(i,j));
            }
        }
    }
}

void MainScene::updateWeaponsOnScene()
{
    vector<Point> gridWeapons;
    vector<FieldCell*> gridWeaponsCells;
    auto gridSize = gameField->getGrid()->getGridSize();
    auto width = int(gridSize.width);
    auto height = int(gridSize.height);
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            auto cell = gameField->getGrid()->getCell(Point(i,j));
            if(cell->getState() >= 2) {
                gridWeapons.push_back(cell->getCellPosition());
                gridWeaponsCells.push_back(cell);
            }
        }
    }
    
    filterWeapons(gridWeapons);
    addNewWeapons(gridWeaponsCells);
}


bool MainScene::weaponExist(Point gridPosition)
{
    bool weaponExist = false;
    for(int k = 0; k < weapons.size(); k++) {
        if(weapons[k]->getGridPosition() == gridPosition)
        {
            weaponExist = true;
            break;
        }
    }
    
    return weaponExist;
}

void MainScene::filterWeapons(vector<Point> newGridWeapons)
{
    int deletedWeapons = 0;
    
    for(int i = 0; i < gameObjects.size(); i++) {
        if(gameObjects[i]->getType() == GameObject::WEAPON &&
           find(newGridWeapons.begin(), newGridWeapons.end(), gameObjects[i]->castObject<Weapon>()->getGridPosition()) == newGridWeapons.end()) {
            auto weapon = gameObjects[i - deletedWeapons]->castObject<Weapon>();
            gameObjects.erase(gameObjects.begin() + i - deletedWeapons);
            weapon->removeFromParent();
            weapon->dropBullets();
            weapon->release();
            deletedWeapons++;
        }
    }
}

void MainScene::addNewWeapons(vector<FieldCell*> newGridWeapons)
{
    for(int i = 0; i < newGridWeapons.size(); ++i) {
        if(!weaponExist(newGridWeapons[i]->getCellPosition())) {
            createWeapon(newGridWeapons[i]->getState(),
                         newGridWeapons[i]->getCellPosition());
        }
    }
}

void MainScene::createWeapon(float type, Point gridPosition)
{
    int weaponType = int(type);
    switch (weaponType) {
        case DEFAULT_WEAPON:
            gameObjects.push_back(new Weapon(gameField->getGrid(), gridPosition));

            break;
        case ICE_WEAPON:
           gameObjects.push_back(new IceWeapon(gameField->getGrid(), gridPosition));
            break;
        case FIRE_WEAPON:
            gameObjects.push_back(new FireWeapon(gameField->getGrid(), gridPosition));
            break;
        default:
            break;
    }
    this->addChild(gameObjects.back(),3);
    gameObjects.back()->addNodes();
}

void MainScene::affectTank(Tank *tank, Bullet *bullet)
{
    switch (bullet->getType()) {
        case Bullet::DEFAULT_BULLET:
        case Bullet::FIRE_BULLET:
            tank->setDamage(bullet->getDamage());
            break;
        case Bullet::ICE_BULLET:
            if(!tank->isFrozen()) {
                tank->freeze(bullet->getFreeze());
            }
            
        default:
            break;
    }
    bullet->setVisible(false);
}

void MainScene::castSceneObjects()
{
    for(int i = 0; i < gameObjects.size(); ++i) {
        switch (gameObjects[i]->getType()) {
//            case GameObject::WEAPON:
//                weapons.push_back(gameObjects[i]->castObject<Weapon>());
//                break;
            case GameObject::TANK:
                tanks.push_back(gameObjects[i]->castObject<Tank>());
                break;
            default:
                break;
        }
    }
}













