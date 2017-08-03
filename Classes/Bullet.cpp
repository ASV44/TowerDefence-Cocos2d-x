//
//  Bullet.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/29/17.
//
//

#include "Bullet.h"

Bullet::Bullet(Point startPoint, Vec2 path, Point deltaPosition)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("bullet.png");
    this->setPosition(startPoint);
    this->setContentSize(Size(0.00704 * visibleSize.width,
                              0.0125 * visibleSize.height));
    this->setGlobalZOrder(24);
    this->path = path;
    this->deltaPosition = deltaPosition;
    this->damage = 34;
    this->speed = 2.5;
}

void Bullet::update()
{
    auto currentPosition = this->getPosition();
    
    if(deltaPosition.x != 0) {
        if(deltaPosition.x < 0) {
            currentPosition.x -= speed;
        }
        else {
            currentPosition.x += speed;
        }
        currentPosition.y = path.x * currentPosition.x + path.y;
    } else {
        if(deltaPosition.y < 0) {
            currentPosition.y -= speed;
        }
        else {
            currentPosition.y += speed;
        }
    }
    
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
