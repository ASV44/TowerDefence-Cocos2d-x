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
//    this->base->setPosition(this->getContentSize().width / 2,
//                            this->getContentSize().height / 2);
    drawActiveRadius(Color4F(0.349f,0.784f,0.811f,0.45f));
    //this->base->setContentSize(Size());
}
