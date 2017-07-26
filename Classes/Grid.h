//
//  Grid.h
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#ifndef Grid_h
#define Grid_h

#include "FieldCell.h"

USING_NS_CC;

class Grid : public Node {
    
public:
    Grid(Point startPoint, Point endPoint);
    CC_SYNTHESIZE(Size, size, GridSize);
    CC_SYNTHESIZE(Size, cellSize, CellSize);
    CC_SYNTHESIZE(Point, startPoint, StartPoint);
    CC_SYNTHESIZE(Point, endPoint, EndPoint);
    
private:
    FieldCell ***cells;
};

#endif /* Grid_h */
