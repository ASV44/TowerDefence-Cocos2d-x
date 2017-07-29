//
//  Weapon.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/28/17.
//
//

#include "Weapon.h"

Weapon::Weapon(Grid *grid, Point gridPosition)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->grid = grid;
    this->initWithFile("tower_weapon.png");
    auto location = grid->getCell(gridPosition)->getCenterLocation() + origin;
    this->setPosition(location);
    this->setContentSize(Size(0.022 * visibleSize.width,
                              0.0765 * visibleSize.height));
    this->gridPosition = gridPosition;
    //this->setGlobalZOrder(25);
    
    this->angle = 0;
    
    this->base = Sprite::create("tower_base.png");
    this->base->setPosition(this->getPosition());
    this->base->setContentSize(Size(0.0299 * visibleSize.width,
                                    0.0531 * visibleSize.height));
    
    this->activeRadius = grid->getCellSize().width * 2;
    
//    CCLOG("Weapon Position x:%f y:%f", this->getPosition().x, this->getPosition().y);
//    CCLOG("Base Position x:%f y:%f", base->getPosition().x, base->getPosition().y);
//    CCLOG("Base Anchor x:%f y:%f", base->getAnchorPoint().x, base->getAnchorPoint().y);
}

Sprite* Weapon::getBase()
{
    return base;
}

void Weapon::rotate()
{
    this->setRotation(this->getRotation() + 1);
}

Point Weapon::findTarget()
{
    Point target = Point(-1,-1);
    
    auto gridSize = grid->getGridSize();
    auto width = int(gridSize.width);
    auto height = int(gridSize.height);
    float minDistance = -1;
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            auto cell = grid->getCell(Point(i,j));
            auto distance = distanceTo(cell->getCenterLocation());
            if(cell->getTankState() &&
                distance <= activeRadius) {
                if(distance < minDistance || minDistance == -1) {
                    minDistance = distance;
                    target = cell->getCenterLocation();
                }
            }
        }
    }
    
    return target;
}

float Weapon::distanceTo(Point target)
{
    auto selfPosition = this->getPosition();
    
    return sqrt(pow(target.x - selfPosition.x, 2) +
                pow(target.y - selfPosition.y, 2));
}


void Weapon::update(float delta)
{
    static float time = 0;
    rotate();
    auto target = findTarget();
    CCLOG("Weapon row:%f column:%f Target row:%f column:%f",gridPosition.x,gridPosition.y,target.x,target.y);
    time += delta;
    if(target != Point(-1,-1) && time > 5) {
        fire(target);
        time = 0;
    }
    for(int i = 0; i < bullets.size(); i++) {
        bullets[i]->update();
    }
}

void Weapon::fire(Point target)
{
    auto path = Vec2();
    auto selfPosition = this->getPosition();
    
    path.x = (target.y - selfPosition.y) / (target.x - selfPosition.y);
    path.y = (target.x * selfPosition.y - selfPosition.x * target.y) / (target.x - selfPosition.x);
    
    auto bullet = new Bullet(selfPosition, path);
    bullets.push_back(bullet);
    this->getParent()->addChild(bullet);
}

























