//
//  FireWeapon.h
//  TowerDefence
//
//  Created by Hackintosh on 8/8/17.
//
//

#ifndef FireWeapon_h
#define FireWeapon_h

#include "Weapon.h"

class FireWeapon : public Weapon {
    
public:
    FireWeapon(Grid *grid, Point gridPosition);
    void fire(Point target);
    Point findTarget();

private:
    
};

#endif /* FireWeapon_h */
