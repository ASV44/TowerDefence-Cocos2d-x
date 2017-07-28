//
//  Weapon.h
//  TowerDefence
//
//  Created by Hackintosh on 7/28/17.
//
//

#ifndef Weapon_h
#define Weapon_h


USING_NS_CC;

class Weapon : public Sprite
{
public:
    Weapon(Point location);
    
private:
    Sprite *base;
    float angle;
};

#endif /* Weapon_h */
