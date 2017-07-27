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

using namespace std;

USING_NS_CC;

class Tank: public Sprite
{
public:
    Tank(Grid *grid);
    void move();
    void moveTo(Point target);
    Point getTarget(Point previousPosition);
    
private:
    Grid *grid;
    Point gridPosition;
    int health;
    float speed;
    float angle;
    Point target;
    Point finish;
    FieldCell *getNeighbour(int neighbourCase);
    Vec2 origin;
};

#endif /* Tank_h */
