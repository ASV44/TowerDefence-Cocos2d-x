//
//  GameField.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/26/17.
//
//

#include <stdio.h>
#include "GameFIeld.h"

GameField::GameField()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("background.png");
    this->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height / 2));
    this->setContentSize(visibleSize);

    auto startPoint = Point(0, 0.1375 * visibleSize.height);
    auto endPoint = Point(visibleSize.width, 0.835 * visibleSize.height);
    
    grid = new Grid(startPoint, endPoint);
    this->addChild(grid);

    debugMode = false;
    
    listener = EventListenerTouchOneByOne::create();
    
    
    listener->onTouchBegan = [&](Touch* touch, Event* event){
        // your code
        log("Game Field Touch Began");
        time = clock();
        return true; // if you are consuming it
    };

    listener->onTouchMoved = [&](Touch* touch, Event* event){

        return true;
    };
    
    listener->onTouchEnded = [&](Touch* touch, Event* event){
        log("Game Field Touch End");
        time  = (clock() - time) / CLOCKS_PER_SEC;
        CCLOG("Time %f", time);
        if(time >= 0.8) {
            longPress();
        }
        return true;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameField::longPress()
{
    if(debugMode) {
        debugMode = false;
        grid->setVisible(false);
    }
    else {
        debugMode = true;
        grid->setVisible(true);
    }
}
