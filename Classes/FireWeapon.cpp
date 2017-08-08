//
//  FireWeapon.cpp
//  TowerDefence
//
//  Created by Hackintosh on 8/8/17.
//
//

#include "FireWeapon.h"

FireWeapon::FireWeapon(Grid *grid, Point gridPosition) : Weapon(grid, gridPosition)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    this->setTexture("fire_weapon.png");
    this->setContentSize(Size(0.0246 * visibleSize.width,
                              0.1015 * visibleSize.height));
    
    this->base->setTexture("fire_weapon_base.png");
    this->base->setContentSize(Size(0.0352 * visibleSize.width,
                                    0.064 * visibleSize.height));
    drawActiveRadius(Color4F(0.945f,0.352f,0.149f,0.2f));
    
    this->delay = 1;
}

void FireWeapon::fire(Point target)
{
    auto path = Vec2();
    auto selfPosition = this->getPosition();
    target = target + origin;
    auto deltaPosition = target - selfPosition;
    
    path.x = (target.y - selfPosition.y) / (target.x - selfPosition.x);
    path.y = (target.x * selfPosition.y - selfPosition.x * target.y) / (target.x - selfPosition.x);
    
    auto bullet = new Bullet(selfPosition, path, deltaPosition, Bullet::FIRE_BULLET);
    bullet->setRotation(angle);
    bullets.push_back(bullet);
    this->getParent()->addChild(bullet,2);
}
