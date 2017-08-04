//
//  IceWeapon.h
//  TowerDefence
//
//  Created by Hackintosh on 8/4/17.
//
//

#ifndef IceWeapon_h
#define IceWeapon_h

#include "Weapon.h"

class IceWeapon : public Weapon {
    
public:
    IceWeapon(Grid *grid, Point gridPosition);
    void fire(Point target);

private:
    
    
};

#endif /* IceWeapon_h */
