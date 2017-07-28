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
    origin = Director::getInstance()->getVisibleOrigin();
    //CCLOG("Origin x:%f y:%f", origin.x, origin.y);
    this->initWithFile("background.png");
    this->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height / 2));
    this->setContentSize(visibleSize);

    auto startPoint = Point(0, 0.1375 * visibleSize.height);
    auto endPoint = Point(visibleSize.width, 0.835 * visibleSize.height);
    
    debugMode = false;
    
    grid = new Grid(startPoint, endPoint);
    grid->setVisible(false);
    if(!grid->importGridFromJson()) {
        changeMode();
    }
    grid->showGridState();
    this->setGlobalZOrder(5);
    CCLOG("GameField globa Z %f",this->getGlobalZOrder());
    //grid->setGlobalZOrder();
    CCLOG("Grid globa Z %f",grid->getGlobalZOrder());
    this->addChild(grid,3);
    CCLOG("Grid globa Z %f",grid->getGlobalZOrder());
    
    stonesAmount = 3;
    stones = new Sprite*[stonesAmount];
    for(int i = 0; i < stonesAmount; ++i) {
        stones[i] = Sprite::create("stone_" + to_string(i + 1) + ".png");
        stones[i]->setAnchorPoint(Vec2(0,0));
        setStonesLocation(i);
        this->addChild(stones[i],2);
        stones[i]->setGlobalZOrder(50);
    }
    
    
    listener = EventListenerTouchOneByOne::create();
    //listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](Touch* touch, Event* event){
        // your code
        log("Game Field Touch Began");
        time = clock();
        return true; // if you are consuming it
    };

    listener->onTouchMoved = [&](Touch* touch, Event* event){
//        auto location = touch->getLocation() - origin;
//        stones[2]->setPosition(location);
//        CCLOG("X:%f Y:%f",location.x, location.y);
        return true;
    };
    
    listener->onTouchEnded = [&](Touch* touch, Event* event){
        log("Game Field Touch End");
        time  = (clock() - time) / CLOCKS_PER_SEC;
        CCLOG("Time %f", time);
        if(time >= 0.8) {
            changeMode();
        }
        return true;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameField::changeMode()
{
    if(debugMode) {
        debugMode = false;
        grid->exportGrid();
        grid->setVisible(false);
    }
    else {
        debugMode = true;
        grid->setVisible(true);
    }
}

void GameField::setStonesLocation(int stone)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    switch (stone) {
        case 0:
            stones[stone]->setContentSize(Size(0.0387 * visibleSize.width,
                                           0.0484 * visibleSize.height));
            stones[stone]->setPosition(Vec2(83.074928, 116.650040));
            break;
        case 1:
            stones[stone]->setContentSize(Size(0.0669 * visibleSize.width,
                                               0.1703 * visibleSize.height));
            stones[stone]->setPosition(Vec2(411.267273, 109.900589));
            break;
        case 2:
            stones[stone]->setContentSize(Size(0.0589 * visibleSize.width,
                                               0.142 * visibleSize.height));
            stones[stone]->setPosition(Vec2(40.890820, 99.776390));
            break;
            
        default:
            break;
    }
}

Grid* GameField::getGrid()
{
    return this->grid;
}
