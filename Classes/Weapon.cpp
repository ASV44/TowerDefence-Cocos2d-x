//
//  Weapon.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/28/17.
//
//

#include <stdio.h>
#include "Weapon.h"

Weapon::Weapon(Point location)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("tower_weapon.png");
    this->setPosition(location);
    this->setContentSize(Size(0.022 * visibleSize.width,
                              0.0765 * visibleSize.height));
    this->setGlobalZOrder(25);
    
    this->angle = 0;
    
    this->base = Sprite::create("tower_base.png");
    this->base->setPosition(this->getPosition());
    this->base->setContentSize(Size(0.0299 * visibleSize.width,
                                    0.0531 * visibleSize.height));
    this->base->setGlobalZOrder(25);
    this->addChild(base);
}
