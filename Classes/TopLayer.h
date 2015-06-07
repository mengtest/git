//
//  TopLayer.h
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#ifndef __PigRun__TopLayer__
#define __PigRun__TopLayer__
#include "MHeader.h"
#include <stdio.h>
class TopLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    
    virtual bool init();
    CREATE_FUNC(TopLayer);
    void loadUI();
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void _registerEvent();
    void chargeScore(EventCustom* event);
    int m_score = 0;
    Node* UInode;
    Label *scoreTxt;
    Vec2 scorePos;
};

#endif /* defined(__PigRun__TopLayer__) */
