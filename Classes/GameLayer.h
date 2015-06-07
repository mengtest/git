#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "MHeader.h"
#include "Stone.h"
#include "Pig.h"
#include "GameOver.h"
#include "TopLayer.h"
#include "ObjManager.h"
class GameLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer

    virtual bool init();
    CREATE_FUNC(GameLayer);
    void loadUI();
    void test();
    void addTopLayer();
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    float speep = 1;
    void generateUpdate(float delay);
    void addPig();
    void addTouch();
//    virtual void onEnter();
    Pig *_pig ;
    bool isFirstFollow = true;
    int stoneIndex = 0;
    static Scene* createScene();
    virtual void onExit();
    TopLayer *toplayer ;
    ObjManager * objManager;
};

#endif // __HELLOWORLD_SCENE_H__
