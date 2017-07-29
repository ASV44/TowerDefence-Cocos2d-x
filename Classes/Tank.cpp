//
//  Tank.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#include <stdio.h>
#include "Tank.h"

Tank::Tank(Grid *grid)
{
    this->grid = grid;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("tank.png");
    this->setContentSize(Size(0.03785 * visibleSize.width,
                              0.06406 * visibleSize.height));
    this->gridPosition = Point(4,0);
    this->target = Point(4,1);
    this->setPosition(Point(origin.x,
                            origin.y + grid->getCell(gridPosition)->getCenterLocation().y));
    grid->getCell(gridPosition)->setTankState(true);
    this->health = 100;
    this->angle = 0;
    this->finish = Point(4,22);
    this->setGlobalZOrder(24);
    
    //CCLOG("Target x:%f y:%f",grid->getCell(target)->getCenterLocation().x,grid->getCell(target)->getCenterLocation().y);
};

void Tank::move()
{
    auto position = this->getPosition() - origin;
    //CCLOG("Current Position x:%f y:%f", position.x, position.y);
    auto targetLocation = grid->getCell(this->target)->getCenterLocation();
    if(round(position.x) != round(targetLocation.x) ||
       round(position.y) != round(targetLocation.y)) {
        moveTo(this->target);
    }
    else {
        if(target != finish) {
            auto previousPosition = gridPosition;
            gridPosition = target;
            target = getTarget(previousPosition);
            grid->getCell(previousPosition)->setTankState(false);
            grid->getCell(gridPosition)->setTankState(true);
        }
    }
    
}

void Tank::moveTo(Point target)
{
    auto deltaPosition = gridPosition - target;
    
    switch (int(deltaPosition.x)) {
        case 0:
            if(deltaPosition.y == -1) {
                if(angle != 0) {
                    angle = 0;
                    this->setRotation(angle);
                }
                this->setPositionX(getPositionX() + 1);
            }
            else if(deltaPosition.y == 1) {
                if(angle != 180) {
                    angle = 180;
                    this->setRotation(angle);
                }
                this->setPositionX(getPositionX() - 1);
            }
            break;
        case -1:
            if(angle != 90) {
                angle = 90;
                this->setRotation(angle);
            }
            this->setPositionY(getPositionY() + 1);
            break;
        case 1:
            if(angle != -90) {
                angle = -90;
                this->setRotation(angle);
            }
            this->setPositionY(getPositionY() - 1);
            break;
        default:
            break;
    }
}

Point Tank::getTarget(Point previousPosition)
{
    vector<Point> newTargets = {};
    Point newTarget = gridPosition;
    auto minRelativeDistance = grid->getGridSize().width + grid->getGridSize().height;
    
    for(int i = 0; i < 4; i++) {
        auto nextTarget = getNeighbour(i);
        if(nextTarget->getState() == 1 &&
           nextTarget->getCellPosition() != previousPosition) {
            auto deltaPosition = finish - nextTarget->getCellPosition();
            auto relativeDistance = abs(deltaPosition.x) + abs(deltaPosition.y);
            if(relativeDistance < minRelativeDistance) {
                minRelativeDistance = relativeDistance;
                newTarget = nextTarget->getCellPosition();
                newTargets.clear();
                newTargets.push_back(newTarget);
            }
            else if(relativeDistance == minRelativeDistance) {
                newTargets.push_back(nextTarget->getCellPosition());
            }
            
        }
    }
    srand(time( 0 ));
    newTarget = newTargets[rand() % newTargets.size()];
    //CCLOG("Target x:%f y:%f", newTarget.x, newTarget.y);
    return newTarget;
}

FieldCell* Tank::getNeighbour(int neighbourCase)
{
    switch (neighbourCase) {
        case 0:
            return grid->getCell(Point(gridPosition.x,
                                       gridPosition.y + 1));
            break;
        case 1:
            return grid->getCell(Point(gridPosition.x,
                                       gridPosition.y - 1));
            break;
        case 2:
            return grid->getCell(Point(gridPosition.x + 1,
                                       gridPosition.y));
            break;
        case 3:
            return grid->getCell(Point(gridPosition.x - 1,
                                       gridPosition.y));
            break;
        default:
            return NULL;
    }
}



























