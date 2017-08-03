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
    this->tankSize = Size(0.03785 * visibleSize.width,
                         0.06406 * visibleSize.height);
    this->setContentSize(tankSize);
    this->start = Point(4,0);
    this->gridPosition = start;
    this->target = Point(4,1);
    this->setPosition(Point(origin.x,
                            origin.y + grid->getCell(gridPosition)->getCenterLocation().y));
    //grid->getCell(gridPosition)->setTankState(true);
    this->health = 100;
    this->angle = 0;
    this->speed = 2;
    this->finish = Point(4,22);
    this->activeRadius = 0.75 * tankSize.width;
    this->setVisible(false);
    this->drawHealth = DrawNode::create();
    //this->addChild(drawHealth);
    explosion = new Explosion("explosion.png", Size(5,5), 0.05f);
    
    //CCLOG("Target x:%f y:%f",grid->getCell(target)->getCenterLocation().x,grid->getCell(target)->getCenterLocation().y);
};

void Tank::move()
{
    auto position = this->getPosition() - origin;
    //CCLOG("Current Position x:%f y:%f", position.x, position.y);
    auto cell = grid->getCell(this->gridPosition); //cell in which tank is at the moment
    auto cellPosition = cell->getLocation(); //Coordinates of Left lower vorner of cell
    auto bound = cellPosition + Point(cell->getCellSize());
    //log("Delta x:%f y:%f", deltaPosition.x, deltaPosition.y);
    if((position.x < bound.x && position.x >= cellPosition.x &&
       position.y < bound.y && position.y >= cellPosition.y) ||
       position.x < cellPosition.x ) {
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
        else {
            this->reset();
        }
    }
    
}

void Tank::moveTo(Point target)
{
    auto deltaPosition = gridPosition - target;
    auto angleVelocity = 10;
    switch (int(deltaPosition.x)) {
        case 0:
            if(deltaPosition.y == -1 && angle != 0) {
                if(angle < 0) {
                    angle += angleVelocity;
                }
                else {
                    angle -= angleVelocity;
                }
                rotate();
                
            }
            else if(deltaPosition.y == 1 &&
                angle != 180 && angle != -180) {
                if(angle < 0) {
                    angle -= angleVelocity;
                }
                else {
                    angle += angleVelocity;
                }
                rotate();
            }
            break;
        case -1:
            if(angle != -90) {
                angle -= angleVelocity;
                rotate();
            }
            
            break;
        case 1:
            if(angle != 90) {
                angle += angleVelocity;
                rotate();
            }
            break;
        default:
            break;
    }
    
    this->setPositionX(getPositionX() + speed * cos(angle * M_PI / 180));
    this->setPositionY(getPositionY() + speed * sin(-angle * M_PI / 180));
    showHealth();
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

float Tank::getActiveRadius()
{
    return this->activeRadius;
}

void Tank::reset()
{
    grid->getCell(gridPosition)->setTankState(false);
    this->gridPosition = Point(4,0);
    this->target = Point(4,1);
    this->setPosition(Point(origin.x,
                            origin.y + grid->getCell(gridPosition)->getCenterLocation().y));
    //grid->getCell(gridPosition)->setTankState(true);
    this->health = 100;
    this->angle = 0;
    this->setRotation(angle);
    this->setVisible(false);
    drawHealth->setVisible(false);
}

void Tank::setDamage(float damage)
{
    this->health -= damage;
    showHealth();
}

float Tank::getHealth()
{
    return this->health;
}

bool Tank::canMove()
{
    bool canMove = true;
    
    if((!this->isVisible() &&
       grid->getCell(gridPosition)->getTankState()) ||
       grid->getCell(target)->getTankState())
    {
        canMove = false;
        
    }
    
    if(canMove && !this->isVisible()) {
        this->setVisible(true);
        grid->getCell(gridPosition)->setTankState(true);
        drawHealth->setVisible(true);
    }
    
    return canMove;
}

void Tank::showHealth()
{
    Point startHealth, startDamage;
    auto healthLine = Vec2(tankSize.width * health / 100, 5);
    auto damageLine = Vec2(tankSize.width - healthLine.x, 5);
    
    startHealth = Point(this->getPosition().x  - tankSize.width / 2,
                        this->getPosition().y + tankSize.height * 0.75);
    startDamage = Point(startHealth.x + healthLine.x,
                        startHealth.y);
    drawHealth->clear();
    
    drawHealth->drawSolidRect(startHealth,
                              startHealth + healthLine,
                              Color4F(0,0,1,1));
    drawHealth->drawSolidRect(startDamage,
                              startDamage + damageLine,
                              Color4F(1,0,0,1));
}

void Tank::expload()
{
    this->explosion->expload(this->getPosition());
}

Explosion* Tank::getExplosion()
{
    return this->explosion;
}

void Tank::rotate()
{
    this->setRotation(angle);
}

DrawNode* Tank::getHealthDesigner()
{
    return drawHealth;
}






















