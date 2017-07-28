//
//  FieldCell.h
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#ifndef FieldCell_h
#define FieldCell_h

#include <time.h>

USING_NS_CC;

class FieldCell : public DrawNode
{
public:
    FieldCell(Vec2 position, Point location, Size cellSize);
    //CC_SYNTHESIZE(int, state, State);
    CC_SYNTHESIZE(Vec2, gridPosition, CellPosition);
    CC_SYNTHESIZE(Point, location, Location);
    CC_SYNTHESIZE(Size, cellSize, CellSize);
    CC_SYNTHESIZE(Point, centerLocation, CenterLocation);
    CC_SYNTHESIZE(int, editMode, EditMode);
    void changeState();
    bool inCell(Point touchPoint);
    void putWeapon();
    enum editMode {EDIT_ROAD, EDIT_WEAPON};
    void setState(int state);
    int getState();

private:
    int state;
    EventListenerTouchOneByOne *listener;
    float time;
};

#endif /* FieldCell_h */
