//
//  GameScene.cpp
//  NyanGame
//
//  Created by tbaba on 2014/02/05.
//
//

#include "GameScene.h"

using namespace cocos2d;
using namespace std;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    GameScene* layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

// initialize
bool GameScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    // 背景表示
    showBackground();
    
    return true;
}

void GameScene::showBackground()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    // 背景を生成
    m_background = Sprite::create(PNG_BACKGROUND);
    m_background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    addChild(m_background, kZOrderBackground, kTagBackground);
}