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
    FieldCell(Vec2 position, Point location, Size cellSize);
    CC_SYNTHESIZE(int, state, State);
    CC_SYNTHESIZE(Vec2, gridPosition, CellPosition);
    CC_SYNTHESIZE(Point, location, Location);
    CC_SYNTHESIZE(Size, cellSize, CellSize);
    CC_SYNTHESIZE(Point, centerLocation, CenterLocation);
    void changeState();
    bool inCell(Point touchPoint);

private:
    EventListenerTouchOneByOne *listener;
};

#endif /* FieldCell_h */
