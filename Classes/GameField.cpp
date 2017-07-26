//
//  GameField.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/26/17.
//
//

#include <stdio.h>
#include "GameFIeld.h"

GameField::GameField(Point startPoint, Point endPoint)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithFile("background.png");
    this->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height / 2));
    this->setContentSize(visibleSize);
    
    cellSize = Size(0.044 * visibleSize.width,
                    0.0781 * visibleSize.height);
    
    _fieldSize.width = round((endPoint.y - startPoint.y) / cellSize.height);
    _fieldSize.height = round((endPoint.x - startPoint.x) / cellSize.width);
    
    CCLOG("Field width:%f height:%f",_fieldSize.width, _fieldSize.height);
    
    foreground = DrawNode::create();
    
    auto width = int(_fieldSize.width);
    auto height = int(_fieldSize.height);
    
    grid = new int*[width];
    
    auto correction = 0.0132 * visibleSize.width;
    
    for(int i = 0; i < width; i++) {
        grid[i] = new int[height];
        for(int j = 0; j < height; j++) {
            auto cellLeftPoint = Vec2(correction + j * cellSize.width,
                                      startPoint.y + i * cellSize.height);
            
            foreground->drawRect(cellLeftPoint,
                                 cellLeftPoint + Vec2(cellSize),
                                 Color4F(1,0,0,0.6f));
        }
    }

    debugMode = false;
    foreground->setVisible(false);
    this->addChild(foreground);
    
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
        foreground->setVisible(false);
    }
    else {
        debugMode = true;
        foreground->setVisible(true);
    }
}
