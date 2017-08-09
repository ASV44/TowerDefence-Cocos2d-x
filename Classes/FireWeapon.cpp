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
    
    this->delay = 2.5;
    target = NULL;
    time = 0.0001;
}

void FireWeapon::fire(Point target)
{
    auto path = Vec2();
    auto selfPosition = this->getPosition();
    auto deltaPosition = target - selfPosition;
    
    path.x = (target.y - selfPosition.y) / (target.x - selfPosition.x);
    path.y = (target.x * selfPosition.y - selfPosition.x * target.y) / (target.x - selfPosition.x);
    
    auto bullet = new Bullet(selfPosition, path, deltaPosition, Bullet::FIRE_BULLET);
    bullet->setRotation(angle);
    bullets.push_back(bullet);
    this->getParent()->addChild(bullet,2);
}

Point FireWeapon::findTarget()
{
    Point targetPosition = Point(-1,-1);
    float minDistance = -1;
    if(this->target == NULL) {
        auto tanksPositions = *grid->getTanksGridPositions();
        for(int i = 0; i < tanksPositions.size(); i++) {
            auto cell = grid->getCell(tanksPositions[i]);
            auto distance = distanceTo(cell->getCellObject()->getPosition() - origin);
            if(distance <= activeRadius &&
               (distance < minDistance || minDistance == -1)){
                minDistance = distance;
                targetPosition = cell->getCellObject()->getPosition();
                target = cell->getCellObject();
                time = 0.0001;
            }
        }
    }
    else if(distanceTo(target->getPosition() - origin) <= activeRadius) {
        targetPosition = this->target->getPosition();
        minDistance = distanceTo(target->getPosition() - origin);
    }
    else {
        target = NULL;
    }
    
    if(targetPosition != Point(-1,-1)) {
        angle = getAngle(targetPosition - origin, minDistance);
        setRotation(angle);
        //rotate(angle);
    }
    
    return targetPosition;
}
