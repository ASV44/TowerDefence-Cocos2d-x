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

USING_NS_CC;

class GameField : public Sprite
{
public:
    GameField(Point startPoint, Point endPoint);
    
private:
    Size _fieldSize;
    //Sprite *field;
    int **grid;
    Size cellSize;
    DrawNode *foreground;
    bool debugMode;
    EventListenerTouchOneByOne *listener;
    float time;
    void longPress();
};


#endif /* GameFIeld_h */
