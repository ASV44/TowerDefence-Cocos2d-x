//
//  GameObject.h
//  TowerDefence
//
//  Created by Hackintosh on 8/9/17.
//
//

#ifndef GameObject_h
#define GameObject_h

#include "cocos2d.h"

using namespace std;

USING_NS_CC;

class GameObject : public Sprite {
    
public:
    GameObject(string fileName);
    GameObject(string fileName, int type);
    enum objectType {OBJECT, TANK, WEAPON};
    CC_SYNTHESIZE(int, type, Type);
    virtual void update(float delta) = 0;
    virtual void addNodes();
    template <typename T> T* castObject() {
        return static_cast<T*>(this);
    }
    
private:
    
};

#endif /* GameObject_h */
