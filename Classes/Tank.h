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

USING_NS_CC;

class Tank: public Sprite
{
public:
    Tank(Grid *grid);
    void move();
    
private:
    Grid *grid;
    Point gridPosition;
    int health;
    float speed;
    float angle;
    Point target;
};

#endif /* Tank_h */
