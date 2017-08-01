#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameFIeld.h"
#include "Tank.h"
#include "Weapon.h"
#include "Explosion.h"

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    void update(float delta);
    virtual bool init();
    void checkColision(vector<Bullet*> bullets);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
private:
    GameField *gameField;
    vector<Tank*> tanks;
    int tanksAmount;
    vector<Weapon*> weapons;
};

#endif // __HELLOWORLD_SCENE_H__
