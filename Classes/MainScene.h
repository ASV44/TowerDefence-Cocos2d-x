#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameFIeld.h"
#include "Tank.h"
#include "Weapon.h"
//#include "Explosion.h"
#include "IceWeapon.h"

using namespace std;

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    void update(float delta);
    virtual bool init();
    void checkColision(vector<Bullet*> bullets);
    void createWeapons(Grid *grid);
    bool weaponExist(Point gridPosition); // returns true if on scene exist weapons with suxh coordinates in grid
    void filterWeapons(vector<Point> newGridWeapons);
    void addNewWeapons(vector<Point> newGridWeapons);
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
private:
    GameField *gameField;
    vector<Tank*> tanks;
    int tanksAmount;
    enum weaponsType {DEFAULT_WEAPON = 2, ICE_WEAPON = 3};
    vector<Weapon*> weapons;
    vector<IceWeapon*> iceWeapons;
    bool updateSceneWeapons;
    void updateWeaponsOnScene();
};

#endif // __HELLOWORLD_SCENE_H__
