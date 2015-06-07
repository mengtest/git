//
//  GameOver.cpp
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#include "GameOver.h"
void GameOverLayer::loadUI(){
    Size winSize = Director::getInstance()->getWinSize();
    Node* node = CSLoader::createNode("GameOver.csb");
    node->setAnchorPoint(Vec2(0.5, 0.5));
    node->setPosition(Vec2(winSize.width/2,winSize.height/2));
    this->addChild(node);
    
    Button *restartBtn = (Button *)node->getChildByName("restart_btn");
    restartBtn->addTouchEventListener(CC_CALLBACK_2(GameOverLayer::touchEvent,this));
    
    Button *mainBtn = (Button *)node->getChildByName("main_btn");
    mainBtn->addTouchEventListener(CC_CALLBACK_2(GameOverLayer::touchEvent,this));
};
bool GameOverLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init())
    {
        return false;
    }
    loadUI();
    return  true;
}
    
Scene* GameOverLayer::createScene(){
    Scene * scene = Scene::create();
    Layer * layer = GameOverLayer::create();
    scene->addChild(layer);
    return scene;
};
void GameOverLayer::touchEvent(Ref *pSender, Widget::TouchEventType type){
    Button *btn =static_cast<Button *>(pSender);
    if (btn->getName()=="restart_btn") {
        Director::getInstance()->replaceScene(GameLayer::createScene());
    }else if (btn->getName()=="main_btn"){
        Director::getInstance()->replaceScene(StartLayer::createScene());
    }

};
