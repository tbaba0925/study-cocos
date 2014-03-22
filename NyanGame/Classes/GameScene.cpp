//
//  GameScene.cpp
//  NyanGame
//
//  Created by tbaba on 2014/02/05.
//
//

#include "GameScene.h"
#include "BlockSprite.h"

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
    
    // タップイベントを取得する
//    setTouchEnabled(true);
//    setTouchMode(kCCTouchesOneByOne);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
//    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    
    // 変数初期化
    initForVariabales();
    
    // 背景表示
    showBackground();
    
    // コマ表示
    showBlock();

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

// 変数初期化
void GameScene::initForVariabales()
{
    // 乱数初期化
    srand((unsigned)time(NULL));
    
    // コマの一辺の長さを取得
    BlockSprite* pBlock = BlockSprite::createWithBlockType(kBlockRed);
    m_blockSize = pBlock->getContentSize().height;
    
}

// 位置取得
Point GameScene::getPosition(int posIndexX, int posIndexY)
{
    float offsetX = m_background->getContentSize().width * 0.168;
    float offsetY = m_background->getContentSize().height * 0.029;
    return Point((posIndexX + 0.5) * m_blockSize + offsetX, (posIndexY + 0.5) * m_blockSize + offsetY);
}

// コマの表示
void GameScene::showBlock()
{
    // 8 x 8 のコマを作成する
    for (int x = 0; x < MAX_BLOICK_X; x++) {
        for (int y = 0; y < MAX_BLOICK_Y; y++) {
            // ランダムでコマを作成
            kBlock blockType = (kBlock)(rand() % kBlockCount);
        
            // 対応するコマ配列にタグを追加
            int tag = getTag(x, y);
            m_blockTags[blockType].push_back(tag);
            
            // コマを作成
            BlockSprite* pBlock = BlockSprite::createWithBlockType(blockType);
            pBlock->setPosition(getPosition(x, y));
            m_background->addChild(pBlock, kZOrderBlock, tag);
            
        }
    }
}

// タッチ開始イベント
bool GameScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent)
{
    return true;
}

// タッチ終了イベント
void GameScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    // タップポイントの取得
    Point touchPoint = m_background->convertTouchToNodeSpace(pTouch);
    
    // タップコマのTagを取得
    int tag = 0;
    kBlock blockType;
    getTouchBlockTag(touchPoint, tag, blockType);
    
    if (tag != 0)
    {
        // コマを削除
        m_blockTags[blockType].remove(tag);
        
        Node* block = m_background->getChildByTag(tag);
        if (block)
        {
            block->removeFromParentAndCleanup(true);
        }
        
    }
}

// タップされたコマのタグを取得

void GameScene::getTouchBlockTag(Point touchPoint, int &tag, kBlock &blockType)
{
    for (int x = 0; x < MAX_BLOICK_X; x++) {
        for (int y = 0; y < MAX_BLOICK_Y; y++) {
            int currentTag = getTag(x, y);
            Node* node = m_background->getChildByTag(currentTag);
            if (node && node->boundingBox().containsPoint(touchPoint)) {
                tag = currentTag;
                blockType = ((BlockSprite*)node)->getBlockType();
                
                return;
            }

        }
    }
}

// タグ取得
int GameScene::getTag(int posIndexX, int posIndexY)
{
    return kTagBaseBlock + posIndexX * 100 + posIndexY;
}

