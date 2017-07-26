//
//  FieldCell.h
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#ifndef FieldCell_h
#define FieldCell_h

USING_NS_CC;

class FieldCell : public DrawNode
{
public:
    FieldCell(Point location, Size cellSize);
    CC_SYNTHESIZE(int, state, State);
    CC_SYNTHESIZE(Point, location, Location);
    CC_SYNTHESIZE(Size, cellSize, CellSize);

private:

};

#endif /* FieldCell_h */
