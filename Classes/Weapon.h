//
//  Weapon.h
//  TowerDefence
//
//  Created by Hackintosh on 7/28/17.
//
//

#ifndef Weapon_h
#define Weapon_h

#include "Grid.h"
#include "Bullet.h"

USING_NS_CC;

class Weapon : public Sprite
{
public:
    Weapon(Grid *grid ,Point griPosition);
    Sprite *getBase();
    void rotate();
    Point findTarget();
    float distanceTo(Point target);
    void update(float delta);
    void fire(Point target);
    Vec2 origin;
    float time;
    float getAngle(Point target, float distance);
    vector<Bullet*> getBullets();
    void dropBullets(vector<int> deleteBullets);
    
private:
    Grid *grid;
    Point gridPosition;
    Sprite *base;
    float angle;
    float activeRadius;
    vector<Bullet*> bullets;
    float delay;
};

#endif /* Weapon_h */
