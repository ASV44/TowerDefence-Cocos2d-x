//
//  IceWeapon.cpp
//  TowerDefence
//
//  Created by Hackintosh on 8/4/17.
//
//

#include "IceWeapon.h"

IceWeapon::IceWeapon(Grid *grid, Point gridPosition) : Weapon(grid, gridPosition)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    this->setTexture("ice_weapon.png");
    this->setContentSize(Size(0.027 * visibleSize.width,
                              0.0727 * visibleSize.height));
    
    this->base->setTexture("ice_weapon_base.png");
    this->base->setContentSize(Size(0.0378 * visibleSize.width,
                                    0.0613 * visibleSize.height));
    drawActiveRadius(Color4F(0.349f,0.784f,0.811f,0.45f));
    
    this->delay = 0;
}

void IceWeapon::fire(Point target)
{
    auto path = Vec2();
    auto selfPosition = this->getPosition();
    target = target + origin;
    auto deltaPosition = target - selfPosition;
    
    path.x = (target.y - selfPosition.y) / (target.x - selfPosition.x);
    path.y = (target.x * selfPosition.y - selfPosition.x * target.y) / (target.x - selfPosition.x);
    
    auto bullet = new Bullet(selfPosition, path, deltaPosition, Bullet::ICE_BULLET);
    bullets.push_back(bullet);
    this->getParent()->addChild(bullet);
}
