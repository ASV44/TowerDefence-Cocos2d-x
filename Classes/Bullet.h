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
    Bullet(Point startPoint, Vec2 path, float delta_x);
    void update();
    Vec2 getPath();
    bool isOnScreen();
    CC_SYNTHESIZE(float, damage, Damage);

private:
    Vec2 path;
    float delta_x;
    float speed;
};

#endif /* Bullet_h */
