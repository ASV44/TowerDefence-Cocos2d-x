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

USING_NS_CC;

class Weapon : public Sprite
{
public:
    Weapon(Grid *grid ,Point griPosition);
    Sprite *getBase();
    void rotate();
    
private:
    Grid *grid;
    Point gridPosition;
    Sprite *base;
    float angle;
    float activeRadius;
};

#endif /* Weapon_h */
