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
    Bullet(Point startPoint, Vec2 path, Point deltaPosition, int);
    void update();
    Vec2 getPath();
    bool isOnScreen();
    CC_SYNTHESIZE(float, damage, Damage);
    enum bulletType {DEFAULT_BULLET, ICE_BULLET, FIRE_BULLET};
    CC_SYNTHESIZE(int, type, Type);
    void initBullet(int type);
    CC_SYNTHESIZE(float, freeze, Freeze);

private:
    Vec2 path;
    Point deltaPosition;
    float speed;
};

#endif /* Bullet_h */
