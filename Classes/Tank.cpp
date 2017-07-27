//
//  Tank.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#include <stdio.h>
#include "Tank.h"

Tank::Tank(Grid *grid)
{
    this->grid = grid;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("tank.png");
    this->setContentSize(Size(0.03785 * visibleSize.width,
                              0.06406 * visibleSize.height));
    this->gridPosition = Point(4,0);
    this->setPosition(Point(origin.x,
                            origin.y + grid->getCell(gridPosition)->getCenterLocation().y));
    
    this->health = 100;
    this->angle = 0;
    this->target = Point(4,22);
    this->setGlobalZOrder(25);
};

void Tank::move()
{
    this->setPositionX(getPositionX() + 1);
}
