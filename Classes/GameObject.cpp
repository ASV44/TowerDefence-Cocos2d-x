//
//  GameObject.cpp
//  TowerDefence
//
//  Created by Hackintosh on 8/9/17.
//
//

#include "GameObject.h"

GameObject::GameObject(string filename)
{
    initWithFile(filename);
    this->type = OBJECT;
}

GameObject::GameObject(string filename, int type)
{
    initWithFile(filename);
    this->type = type;
}

void GameObject::addNodes()
{
    log("This Object doesn't have additional nodes");
}

//template <typename T> inline T* GameObject::castObject()
//{
//    return static_cast<T*>(this);
//}
