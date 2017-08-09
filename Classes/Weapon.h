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
#include "GameObject.h"

USING_NS_CC;

class Weapon : public GameObject
{
public:
    Weapon(Grid *grid ,Point griPosition);
    Sprite *getBase();
    void rotate();
    virtual Point findTarget();
    float distanceTo(Point target);
    void update(float delta);
    virtual void fire(Point target);
    Vec2 origin;
    float time;
    float getAngle(Point target, float distance);
    vector<Bullet*> getBullets();
    void dropBullets(vector<int> deleteBullets);
    DrawNode* getDesigner();
    CC_SYNTHESIZE(Point, gridPosition, GridPosition);
    void dropBullets();
    void drawActiveRadius(Color4F color);
    void addNodes();
    void removeFromParent();
    
protected:
    Grid *grid;
    Sprite *base;
    float angle;
    float activeRadius;
    vector<Bullet*> bullets;
    float delay;
    DrawNode *designer;
};

#endif /* Weapon_h */
