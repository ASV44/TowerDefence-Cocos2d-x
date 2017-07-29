//
//  Bullet.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/29/17.
//
//

#include "Bullet.h"

Bullet::Bullet(Point startPoint, Vec2 path, float angle)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("bullet.png");
    this->setPosition(startPoint);
    this->setContentSize(Size(0.00704 * visibleSize.width,
                              0.0125 * visibleSize.height));
    this->setGlobalZOrder(24);
    this->path = path;
    this->angle = angle;
}

void Bullet::update()
{
    auto currentPosition = this->getPosition();
    
    if(angle < 0) {
        currentPosition.x -= 1;
    }
    else {
        currentPosition.x += 1;
    }
    currentPosition.y = path.x * currentPosition.x + path.y;
    
    this->setPosition(currentPosition);
}

Vec2 Bullet::getPath()
{
    return path;
}
