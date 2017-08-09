//
//  FieldCell.h
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#ifndef FieldCell_h
#define FieldCell_h

#include "cocos2d.h"
//#include "Tank.h"
//#include "Weapon.h"

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
    void changeState(int newState);
    bool inCell(Point touchPoint);
    void putWeapon();
    enum editMode {EDIT_ROAD, EDIT_WEAPON, EDIT_ICE, EDIT_FIRE};
    void setState(int state);
    int getState();
    bool hasChanged();
    void setChanged(bool changed);
    void setTankState(bool tankState);
    bool getTankState();
//    CC_SYNTHESIZE(Tank*, tank, CellTank);
//    CC_SYNTHESIZE(Weapon*, weapon, CellWeapon);

private:
    int state;
    EventListenerTouchOneByOne *listener;
    bool changed;
    bool tankState;
};

#endif /* FieldCell_h */
