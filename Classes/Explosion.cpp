//
//  Explosion.cpp
//  TowerDefence
//
//  Created by Hackintosh on 7/31/17.
//
//

#include "Explosion.h"

Explosion::Explosion(string fileName, Size frames, float speed)
{
    this->init();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->fileName = fileName;
    this->frames = frames;
    
    spriteFrames = createSpriteSheetAnimation(fileName, frames);
    //this->initWithSpriteFrame(spriteFrames.front());

    this->setContentSize(Size(0.0963 * visibleSize.width,
                         0.2 * visibleSize.height));
    
    this->speed = speed;
    
//    animation = Animation::createWithSpriteFrames(spriteFrames,0.2f);
//    animation->retain();
}

Vector<SpriteFrame*> Explosion::createSpriteSheetAnimation(string fileName, Size frames)
{
    int rowFrames, columnFrames;
    Vector<SpriteFrame*> spriteFrames;
    
    rowFrames = int(frames.width);
    columnFrames = int(frames.height);
    
    auto spriteTexture = Sprite::create(fileName);
    auto frameSize = Size(spriteTexture->getContentSize().width / frames.width,
                          spriteTexture->getContentSize().height / frames.height);
    
    for(int i = 0; i < rowFrames; i++) {
        for(int j = 0; j < columnFrames; j++) {
            spriteFrames.pushBack(SpriteFrame::create(fileName,
                                                      Rect(j * frameSize.width, i * frameSize.height,
                                                      frameSize.width, frameSize.height)));
        }
    }
    
    return spriteFrames;
}


void Explosion::expload(Point point)
{
    this->setPosition(point);
    this->runAction(Animate::create(Animation::createWithSpriteFrames(spriteFrames, speed)));
}

//Animate* Explosion::getExplosion()
//{
//    return this->createSpriteSheetAnimation(fileName, frameSize, frames);
//}
