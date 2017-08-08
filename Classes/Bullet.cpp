//
//  Bullet.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/29/17.
//
//

#include "Bullet.h"

Bullet::Bullet(Point startPoint, Vec2 path, Point deltaPosition, int type)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    initBullet(type);
    this->setPosition(startPoint);
    this->path = path;
    this->deltaPosition = deltaPosition;
    this->type = type;
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

void Bullet::initBullet(int type)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    switch (type) {
        case DEFAULT_BULLET:
            this->initWithFile("bullet.png");
            this->damage = 34;
            this->speed = 2.5;
            this->freeze = 0;
            this->setContentSize(Size(0.00704 * visibleSize.width,
                                      0.0125 * visibleSize.height));
            break;
        case ICE_BULLET:
            this->initWithFile("ice_bullet.png");
            this->damage = 0;
            this->speed = 2.5;
            this->freeze = 1.5;
            this->setContentSize(Size(0.00704 * visibleSize.width,
                                      0.0125 * visibleSize.height));
            break;
        case FIRE_BULLET:
            this->initWithFile("fire_bullet.png");
            this->damage = 100;
            this->speed = 3;
            this->freeze = 0;
            this->setContentSize(Size(0.0265 * visibleSize.height,
                                      0.0475 * visibleSize.width));
            break;
        default:
            break;
    }
}














































