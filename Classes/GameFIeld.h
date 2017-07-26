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
    
private:
    Size _fieldSize;
    //Sprite *field;
    Grid *grid;
    bool debugMode;
    EventListenerTouchOneByOne *listener;
    float time;
    void longPress();
};


#endif /* GameFIeld_h */
