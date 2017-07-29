//
//  Bullet.h
//  TowerDefence
//
//  Created by Hackintosh on 7/29/17.
//
//

#ifndef Bullet_h
#define Bullet_h

USING_NS_CC;

class Bullet : public Sprite
{
public:
    Bullet(Point startPoint, Vec2 path);
    void update();
    
private:
    Vec2 path;
};

#endif /* Bullet_h */
