//
//  Weapon.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/28/17.
//
//

#include <stdio.h>
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
    this->setGlobalZOrder(25);
    
    this->angle = 0;
    
    this->base = Sprite::create("tower_base.png");
    this->base->setPosition(this->getPosition());
    this->base->setContentSize(Size(0.0299 * visibleSize.width,
                                    0.0531 * visibleSize.height));
    this->base->setGlobalZOrder(24);
    //this->addChild(base);
    
    this->activeRadius = grid->getCellSize().width * 2;
    //CCLOG("Weapon Position x:%f y:%f", this->getPosition().x, this->getPosition().y);
}

Sprite* Weapon::getBase()
{
    return base;
}

void Weapon::rotate()
{
    this->setRotation(this->getRotation() + 1);
}
