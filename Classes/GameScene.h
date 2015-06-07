//
//  GameScene.h
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#ifndef __PigRun__GameScene__
#define __PigRun__GameScene__
#include "MHeader.h"
#include "StartLayer.h"
#include "GameLayer.h"
#include "GameOver.h"
#include <stdio.h>
class GameScene:public Scene{
public:
    CREATE_FUNC(GameScene);
    virtual bool init();
    void loadUI();
    void _showEvent(EventCustom* event);
    void _registerEvent();
    StartLayer *startLayer;
    GameLayer * gameLayer;
    GameOverLayer *gameOverLayer;
};
#endif /* defined(__PigRun__GameScene__) */
