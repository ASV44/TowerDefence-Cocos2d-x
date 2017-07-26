//
//  FieldCell.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#include <stdio.h>
#include "FieldCell.h"

FieldCell::FieldCell(Point location, Size cellSize)
{
    this->init();
    
    this->location = location;
    this->cellSize = cellSize;
    
    this->state = 0;
    this->drawRect(location,
                   location + Vec2(cellSize),
                   Color4F(1,0,0,0.6f));
}
