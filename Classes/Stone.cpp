//
//  Pig.cpp
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//
#include "Pig.h"
#include "Stone.h"
bool Stone::init(){
    Sprite::init();
    loadUI();
    return true;
}

void Stone::loadUI(){
    Node* node = CSLoader::createNode("Stone.csb");
    stoneSize = node->getChildByName("stone_btn")->getContentSize();
    Button* startBtn =(Button *)node->getChildByName("stone_btn");
    startBtn->addTouchEventListener(CC_CALLBACK_2(Stone::touchEvent,this));
    node->setAnchorPoint(Vec2(0.5, 0.5));
    node->setPosition(Vec2(0,0));
    this->addChild(node);
}

void Stone::touchEvent(Ref *pSender, Widget::TouchEventType type){
    
    int followStoneTag = Pig::getInstance()->getFollowStone()->getTag();
    log("followtag=%d====this->gettag=%d",followStoneTag,this->getTag());
    if (followStoneTag+1==this->getTag()) {
        EventCustom customEvent(CHANGE_FOLLOW);
        customEvent.setUserData(this);
        Director::getInstance()->getEventDispatcher()->dispatchEvent(&customEvent);
        
        EventCustom pointcustomEvent(POINT_EVENT);
        Director::getInstance()->getEventDispatcher()->dispatchEvent(&pointcustomEvent);
        
        
    }

};
void Stone::beginMove(){
    Size winSize = Director::getInstance()->getWinSize();
    this->setAnchorPoint(Vec2(0.5, 0.5));

    float random = (std::rand())%4+1;
    log("random=%f",random);
    float beginX =winSize.width*(random/4)-this->stoneSize.width/2;
    this->setPosition(Vec2(beginX,winSize.height+this->stoneSize.height));
    MoveTo *mTo = MoveTo::create(speed, Vec2(beginX,-this->stoneSize.height));
//    this->runAction(mTo);
    
    this->runAction( Sequence::create(mTo,CallFuncN::create(CC_CALLBACK_1(Stone::setRecycleFlagCallBack,this)), NULL));
                    
};
void Stone::setRecycleFlagCallBack(Node* node){
    this->isRecycle = false;
};