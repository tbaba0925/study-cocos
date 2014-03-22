//
//  BlockSprite.cpp
//  NyanGame
//
//  Created by 馬場 達也 on 2014/03/09.
//
//

#include "BlockSprite.h"

using namespace cocos2d;

BlockSprite::BlockSprite()
{
    initNextPos();
}

BlockSprite::~BlockSprite()
{
}

BlockSprite* BlockSprite::createWithBlockType(kBlock blockType)
{
    BlockSprite *pRet = new BlockSprite();
    if (pRet && pRet->initWithBlockType(blockType))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool BlockSprite::initWithBlockType(kBlock blockType)
{
    if (!Sprite::initWithFile(getBlockImageFileName(blockType))) {
        return false;
    }
    
    m_blockType = blockType;
    
    return true;
}

const char* BlockSprite::getBlockImageFileName(kBlock blockType)
{
    switch (blockType) {
        case kBlockRed:
            return "red.png";
            
        case kBlockBlue:
            return "blue.png";
            
        case kBlockYellow:
            return "yellow.png";
            
        case kBlockGreen:
            return "green.png";
            
        case kBlockGray:
            return "gray.png";
            
        default:
            CCASSERT(false, "invalid blockTyep");
            return "";
    }
}

// 移動先の初期化
void BlockSprite::initNextPos()
{
    m_nextPosX = -1;
    m_nextPosY = -1;
}

// 移動先インデックスをセット
void BlockSprite::setNextPos(int nextPosX, int nextPosY)
{
    m_nextPosX = nextPosX;
    m_nextPosY = nextPosY;
}