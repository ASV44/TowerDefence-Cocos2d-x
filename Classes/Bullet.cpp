//
//  Bullet.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/29/17.
//
//

#include "Bullet.h"

Bullet::Bullet(Point startPoint, Vec2 path, float delta_x)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("bullet.png");
    this->setPosition(startPoint);
    this->setContentSize(Size(0.00704 * visibleSize.width,
                              0.0125 * visibleSize.height));
    this->setGlobalZOrder(24);
    this->path = path;
    this->delta_x = delta_x;
    this->damage = 34;
}

void Bullet::update()
{
    auto currentPosition = this->getPosition();
    
    if(delta_x < 0) {
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

bool Bullet::isOnScreen() {
    bool onScreen = false;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    auto bound = origin + Vec2(visibleSize);
    auto selfPosition = this->getPosition();
    
    if(selfPosition.x >= origin.x && selfPosition.y >= origin.y &&
       selfPosition.x <= bound.x && selfPosition.y <= bound.y) {
        onScreen = true;
    }
    
    return onScreen;
}
