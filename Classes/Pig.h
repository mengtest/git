//
//  Pig.h
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#ifndef __PigRun__Pig__
#define __PigRun__Pig__
#include "Stone.h"
#include "MHeader.h"
#include <stdio.h>
class Pig:public Sprite{
    CREATE_FUNC(Pig);
    ~Pig();
public:
    
    virtual bool init();
    void loadUI();
    void update(float delay);
    void beginFollow();
    void changeFollowStone(EventCustom* event);
    void _registerEvent();
    static Pig * _pig;
    static Pig *getInstance();
//    Stone * stone;
    CC_SYNTHESIZE(Stone *, _followStone, FollowStone);
};
#endif /* defined(__PigRun__Pig__) */
