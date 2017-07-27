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
    
    this->setGlobalZOrder(100);
    
    listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = [&](Touch* touch, Event* event){
        // your code
//        auto row = int(this->position.x);
//        auto column = int(this->position.y);
//        CCLOG("Cell Field row:%d column:%d Touch Began",row,column);
        return true; // if you are consuming it
    };
    
    listener->onTouchMoved = [&](Touch* touch, Event* event){
        
        return true;
    };
    
    listener->onTouchEnded = [&](Touch* touch, Event* event){
        if(inCell(touch->getStartLocation())) {
            auto row = int(this->gridPosition.x);
            auto column = int(this->gridPosition.y);
            CCLOG("Cell Field row:%d column:%d Touch Ended",row,column);
            changeState();
        }
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

void FieldCell::changeState()
{
    if(state == 0) {
        state = 1;
        this->clear();
        this->drawSolidRect(location,
                            location + Vec2(cellSize),
                            Color4F(1,0,0,0.6f));
    }
    else {
        state = 0;
        this->clear();
        this->drawRect(location,
                       location + Vec2(cellSize),
                       Color4F(1,0,0,0.6f));
    }
}
