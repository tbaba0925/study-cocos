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
#include "Config.h"

#define MAX_BLOICK_X 8
#define MAX_BLOICK_Y 8
#define FADEOUT_TIME 0.3f
#define MOVING_TIME 0.3f

#define PNG_BACKGROUND "background.png"

class GameScene : public cocos2d::Layer
{
protected:
    enum kTag
    {
        kTagBackground = 1,
        kTagBaseBlock = 10000,
    };
    enum kZOrder
    {
        kZOrderBackground,
        kZOrderBlock,
    };
    struct PositionIndex
    {
        PositionIndex(int x1, int y1)
        {
            x = x1;
            y = y1;
        }
        int x;
        int y;
    };
    
    // 2-2-3
    cocos2d::Sprite* m_background;
    void showBackground();
    
    // 2-2-4
    float m_blockSize;
    std::map<kBlock, std::list<int> > m_blockTags;
    void initForVariabales();
    void showBlock();
    cocos2d::Point getPosition(int posIndexX, int posIndexY);
    int getTag(int posIndexX, int posIndexY);
    
    // 2-2-5
    void getTouchBlockTag(cocos2d::Point touchPoint, int &tag, kBlock &blockType);
    std::list<int> getSameColorBlockTags(int baseTag, kBlock blockType);
    void removeBlock(std::list<int> blockTags, kBlock blockType);
    bool hasSameColorBlock(std::list<int> blockTagList, int searchBlockTag);
    
    // 2-3-1
    void removingBlock(cocos2d::Node* block);
    
    // 2-3-2
    std::vector<kBlock> blockTypes;
    PositionIndex getPositionIndex(int tag);
    void setNewPosition(int tag, PositionIndex posIndex);
    void searchNewPosition(std::list<int> blocks);
    void moveBlock();
    void movingBlocksAnimation(std::list<int> blocks);
    bool isJustAbove(PositionIndex delPoosIndex, PositionIndex targetPosIndex);
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    
     CREATE_FUNC(GameScene);
    
};

#endif /* defined(__NyanGame__GameScene__) */
