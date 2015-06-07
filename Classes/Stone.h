//
//  Pig.h
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#ifndef __PigRun__Stone__
#define __PigRun__Stone__
#include "MHeader.h"
#include <stdio.h>
class Stone:public Sprite{
public:
    CREATE_FUNC(Stone);
    virtual bool init();
    void loadUI();
    Size stoneSize;
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void beginMove();
    bool isRecycle=false;
    int speed=10;
    void setRecycleFlagCallBack(Node* node);
};
#endif /* defined(__PigRun__Stone__) */
