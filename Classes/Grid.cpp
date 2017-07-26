//
//  Grid.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#include <stdio.h>
#include "Grid.h"

Grid::Grid(Point startPoint, Point endPoint)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->create();
    this->setContentSize(Size(endPoint.x - startPoint.x,
                              endPoint.y - startPoint.y));
    
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    
    cellSize = Size(0.044 * visibleSize.width,
                    0.0781 * visibleSize.height);
    
    size.width = round((endPoint.y - startPoint.y) / cellSize.height);
    size.height = round((endPoint.x - startPoint.x) / cellSize.width);
    
    CCLOG("Grid width:%f height:%f", size.width, size.height);
    
    auto correction = 0.0132 * visibleSize.width;
    
    auto width = int(size.width);
    auto height = int(size.height);
    
    cellSize = Size(0.044 * visibleSize.width,
                    0.0781 * visibleSize.height);
    
    cells = new FieldCell**[width];
    
    for(int i = 0; i < width; i++) {
        cells[i] = new FieldCell*[height];
        for(int j = 0; j < height; j++) {
            cells[i][j] = new FieldCell(Point(correction + j * cellSize.width,
                                             startPoint.y + i * cellSize.height), cellSize);
            this->addChild(cells[i][j]);
        }
    }
}
