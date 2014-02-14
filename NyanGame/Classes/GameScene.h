//
//  GameScene.h
//  NyanGame
//
//  Created by tbaba on 2014/02/05.
//
//

#ifndef __NyanGame__GameScene__
#define __NyanGame__GameScene__

#include "cocos2d.h"

#define PNG_BACKGROUND "background.png"

class GameScene : public cocos2d::Layer
{
protected:
    enum kTag
    {
        kTagBackground = 1,
    };
    enum kZOrder
    {
        kZOrderBackground,
    };
    
    cocos2d::Sprite* m_background;
    void showBackground();
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameScene);
};

#endif /* defined(__NyanGame__GameScene__) */
