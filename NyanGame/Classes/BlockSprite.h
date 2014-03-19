//
//  BlockSprite.h
//  NyanGame
//
//  Created by 馬場 達也 on 2014/03/09.
//
//

#ifndef __NyanGame__BlockSprite__
#define __NyanGame__BlockSprite__

#include <iostream>
#include "cocos2d.h"
#include "Config.h"

class BlockSprite : public cocos2d::Sprite
{
protected:
    const char* getBlockImageFileName(kBlock blockType);
    
public:
    CC_SYNTHESIZE_READONLY(kBlock, m_blockType, BlockType);
    
    BlockSprite();
    virtual ~BlockSprite();
    virtual bool initWithBlockType(kBlock blockType);
    static BlockSprite* createWithBlockType(kBlock blockType);
};



#endif /* defined(__NyanGame__BlockSprite__) */
