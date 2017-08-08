//
//  FieldCell.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#include <stdio.h>
#include "FieldCell.h"

FieldCell::FieldCell(Vec2 position, Point location, Size cellSize)
{
    this->init();
    
    this->location = location;
    this->cellSize = cellSize;
    this->gridPosition = position;
    
    this->centerLocation = location + Point(cellSize) / 2;
    this->state = 0;
    this->drawRect(location,
                   location + Vec2(cellSize),
                   Color4F(1,0,0,0.6f));
    
    //this->setGlobalZOrder(100);
    
    editMode = EDIT_ROAD;
    tankState = false;
    this->changed = false;
    
    listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = [&](Touch* touch, Event* event){
        // your code
//        auto row = int(this->gridPosition.x);
//        auto column = int(this->gridPosition.y);
//        CCLOG("Cell Field row:%d column:%d Touch Began",row,column);
        return true; // if you are consuming it
    };
    
    listener->onTouchMoved = [&](Touch* touch, Event* event){
        
        return true;
    };
    
    listener->onTouchEnded = [&](Touch* touch, Event* event){
        auto parent = this->getParent();
        if(inCell(touch->getStartLocation()) &&
           parent->isVisible()) {
            this->changeState(editMode);
        }
        changed = true;
        auto row = int(this->gridPosition.x);
        auto column = int(this->gridPosition.y);
//        CCLOG("Cell Field row:%d column:%d Touch Ended",row,column);
        return true;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool FieldCell::inCell(Point touchPoint)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    touchPoint = touchPoint - origin;
    
    auto locatioBound = location + Point(cellSize);
    if(touchPoint.x >= location.x && touchPoint.y >= location.y &&
       touchPoint.x <= locatioBound.x && touchPoint.y <= locatioBound.y) {
//        CCLOG("Touch Point x:%f y:%f", touchPoint.x, touchPoint.y);
//        CCLOG("Cell location x:%f y:%f", location.x, location.y);
//        CCLOG("Cell Size x:%f y:%f", cellSize.width, cellSize.height);
        return true;
    }
    
    return false;
}

void FieldCell::changeState(int newState)
{
    newState += 1;
    if(this->state == 0) {
        setState(newState);
    }
    else if(this->state == newState) {
        setState(0);
    }
}

void FieldCell::putWeapon()
{
    switch (state) {
        case 0:
            state = 2;
            this->clear();
            this->drawSolidRect(location,
                                location + Vec2(cellSize),
                                Color4F(0,0,1,0.6f));
            break;
        case 2:
            state = 0;
            this->clear();
            this->drawRect(location,
                           location + Vec2(cellSize),
                           Color4F(1,0,0,0.6f));
        default:
            break;
    }
}

int FieldCell::getState() { return this->state; }

void FieldCell::setState(int state)
{
    this->clear();
    switch (state) {
        case 1:
            this->drawSolidRect(location,
                                location + Vec2(cellSize),
                                Color4F(1,0,0,0.6f));
            break;
        case 2:
            this->drawSolidRect(location,
                                location + Vec2(cellSize),
                                Color4F(0,0,1,0.6f));
            break;
        case 3:
            this->drawSolidRect(location,
                                location + Vec2(cellSize),
                                Color4F(0.349f,0.784f,0.811f,0.6f));
            break;
        default:
            break;
    }
    this->state = state;
}

bool FieldCell::hasChanged()
{
    return changed;
}

void FieldCell::setChanged(bool changed)
{
    this->changed = changed;
}
