//
//  TopLayer.cpp
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#include "TopLayer.h"
void TopLayer::loadUI(){
    Size winSize = Director::getInstance()->getWinSize();
    UInode = CSLoader::createNode("topLayer.csb");
    UInode->setAnchorPoint(Vec2(0.5, 0.5));
    UInode->setPosition(Vec2(UInode->getContentSize().width/2,UInode->getContentSize().height/2));
    this->addChild(UInode);
    this->setContentSize(UInode->getContentSize());
    

    scoreTxt = Label::create();
    scoreTxt->setSystemFontSize(20);
    scoreTxt->setPosition(Vec2(this->getContentSize().width/2,this->getContentSize().height/2));
    scoreTxt->setString("0");
    this->addChild(scoreTxt);
    //scorePos = Vec2(temp->getPositionX(),temp->getPositionY());

    m_score = 0;
}
bool TopLayer::init(){
    Layer::init();
    loadUI();
    _registerEvent();
    return true;
}

void TopLayer::_registerEvent(){
    _eventDispatcher->addCustomEventListener(CHANGE_FOLLOW, std::bind(&TopLayer::chargeScore, this, std::placeholders::_1));
}
void TopLayer::chargeScore(EventCustom* event){
    m_score+=1;
//   int *tag = (int *)event->getUserData();
//    if(scoreTxt){
//        scoreTxt->removeFromParentAndCleanup(true);
//       // scoreTxt = NULL;
//    }
//    scoreTxt = Text::create();
//    scoreTxt->setPosition(scorePos);
//    this->addChild(scoreTxt);
//    CallFunc cc=CallFunc::create(<#const std::function<void ()> &func#>)
//    scoreTxt->runAction(DelayTime::create(1));
//    scoreTxt->setString("text");
    char temp[50];
    sprintf(temp, "%d",m_score);
   scoreTxt->setString(temp);
    
//    scoreTxt->setString(temp);
   // String scoreStr=String.createWithFormat("%d",score);
   // scoreTxt->setString(temp);
//    _followStone =(Stone *)event->getUserData();
};