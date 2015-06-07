//
//  GameOver.h
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#ifndef __PigRun__GameOver__
#define __PigRun__GameOver__
#include "MHeader.h"
#include "GameLayer.h"
#include "StartLayer.h"
#include <stdio.h>
class GameOverLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    
    virtual bool init();
    CREATE_FUNC(GameOverLayer);
    void loadUI();
     static Scene* createScene();
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
};

#endif /* defined(__PigRun__GameOver__) */
