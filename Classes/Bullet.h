//
//  Bullet.h
//  TowerDefence
//
//  Created by Hackintosh on 7/29/17.
//
//

#ifndef Bullet_h
#define Bullet_h

#include "cocos2d.h"

USING_NS_CC;

class Bullet : public Sprite
{
public:
    Bullet(Point startPoint, Vec2 path, float angle);
    void update();
    Vec2 getPath();

private:
    Vec2 path;
    float angle;
};

#endif /* Bullet_h */
