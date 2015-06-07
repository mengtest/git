//
//  GameScene.cpp
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#include "GameScene.h"
bool GameScene::init(){
    Scene::init();
    loadUI();
    _registerEvent();
    return true;
}
void GameScene::loadUI(){
    startLayer = StartLayer::create();
    this->addChild(startLayer);
    startLayer->setVisible(true);
    gameLayer = GameLayer::create();
    this->addChild(gameLayer);
    gameLayer->setVisible(false);
    
    
    gameOverLayer = GameOverLayer::create();
    this->addChild(gameOverLayer);
    gameOverLayer->setVisible(false);
    
};
void GameScene::_showEvent(EventCustom* event){//userData 1=startLayer   2=gameLayer
    log("_showEvent");
   int *showTag = (int *)event->getUserData();
//    startLayer->setVisible(false);
//    gameLayer->setVisible(false);
//     gameLayer->setTouchEnabled(false);
    gameOverLayer->setVisible(false);
    if (*showTag==1) {
        
        startLayer->setVisible(true);
    }else if(*showTag==2){
//        gameLayer->setVisible(true);
//        gameLayer->setTouchEnabled(true);
    }else{
//        gameOverLayer->setVisible(true);
    }
    

};
void GameScene::_registerEvent(){
    _eventDispatcher->addCustomEventListener(SHOW_EVENT, std::bind(&GameScene::_showEvent, this, std::placeholders::_1));
}