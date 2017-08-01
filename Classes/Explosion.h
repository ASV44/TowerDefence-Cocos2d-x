//
//  Header.h
//  TowerDefence
//
//  Created by Hackintosh on 7/31/17.
//
//

#ifndef Explosion_h
#define Explosion_h

//#include <string>

using namespace std;

USING_NS_CC;

class Explosion : public Sprite {
    
public:
    Explosion(string fileName, Size frames, float speed);
    void expload(Point point);
    Vector<SpriteFrame*> createSpriteSheetAnimation(string fileName, Size frames);
    Animate* getExplosion();
    
private:
    string fileName;
    Size frames;
    Animation *animation;
    Vector<SpriteFrame*> spriteFrames;
    float speed;
};

#endif /* Explosion_h */
