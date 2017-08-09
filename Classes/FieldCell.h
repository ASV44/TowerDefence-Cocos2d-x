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
#include "GameObject.h"

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
    void setCellObject(GameObject *gameObject);
    GameObject* getCellObject();
    void dropCellObject();
    

private:
    int state;
    EventListenerTouchOneByOne *listener;
    bool changed;
    bool tankState;
    GameObject* cellObject;
};

#endif /* FieldCell_h */
