//
//  GameFIeld.h
//  TowerDefence
//
//  Created by Hackintosh on 7/26/17.
//
//

#ifndef GameFIeld_h
#define GameFIeld_h

#include <time.h>
#include "Grid.h"

USING_NS_CC;

class GameField : public Sprite
{
public:
    GameField();
    Grid *getGrid();
    bool isOnDebug();
    void addFieldStones();
    
private:
    Size _fieldSize;
    //Sprite *field;
    Grid *grid;
    bool debugMode;
    EventListenerTouchOneByOne *listener;
    float time;
    void changeMode();
    int stonesAmount;
    Sprite **stones;
    void setStonesLocation(int stone);
    Vec2 origin;
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    const float TOUCH_TIME_FOR_DEBUG = 0.11;
    #else
    const float TOUCH_TIME_FOR_DEBUG = 0.8;
    #endif
};


#endif /* GameFIeld_h */
