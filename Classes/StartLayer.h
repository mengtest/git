//
//  StartLayer.h
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#ifndef __PigRun__StartLayer__
#define __PigRun__StartLayer__
#include "MHeader.h"
#include "GameLayer.h"
#include <stdio.h>
class StartLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    
    virtual bool init();
    CREATE_FUNC(StartLayer);
    void loadUI();
    void loadRes();
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void addSearchPath();
    static Scene* createScene();
};

#endif /* defined(__PigRun__StartLayer__) */
