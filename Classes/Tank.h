//
//  Tank.h
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#ifndef Tank_h
#define Tank_h

#include "Grid.h"
#include <ctime>
#include "Explosion.h"

using namespace std;

USING_NS_CC;

class Tank: public Sprite
{
public:
    Tank(Grid *grid);
    void move();
    void moveTo(Point target);
    Point getTarget(Point previousPosition);
    float getActiveRadius();
    void reset();
    void setDamage(float damage);
    float getHealth();
    bool canMove();
    void showHealth();
    void expload();
    Explosion* getExplosion();
    void rotate();
    DrawNode *getHealthDesigner();
    
private:
    Grid *grid;
    Point gridPosition;
    float health;
    float speed;
    float angle;
    Point target;
    Point start;
    Point finish;
    Size tankSize;
    FieldCell *getNeighbour(int neighbourCase);
    Vec2 origin;
    float activeRadius;
    DrawNode *drawHealth;
    Explosion *explosion;
    
};

#endif /* Tank_h */
