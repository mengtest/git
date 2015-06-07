//
//  Pig.cpp
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//
#include "GameOver.h"
#include "Pig.h"
Pig * Pig::_pig = NULL;
Pig *Pig::getInstance(){
    if(!_pig){
        _pig = Pig::create();
        return _pig;
    }
    return _pig;

};
Pig::~Pig(){
    this->release();
};
bool Pig::init(){
    Sprite::init();
    this->retain();
    loadUI();
//    _followStone = malloc(sizeof(int));
    _registerEvent();
    return true;
}
void Pig::loadUI(){
    Node* node = CSLoader::createNode("birdNode.csb");
    node->setAnchorPoint(Vec2(0.5, 0.5));
    node->setPosition(Vec2(0,0));
    this->addChild(node);
};
void Pig::_registerEvent(){
    _eventDispatcher->addCustomEventListener(CHANGE_FOLLOW, std::bind(&Pig::changeFollowStone, this, std::placeholders::_1));
}
void Pig::changeFollowStone(EventCustom* event){
    _followStone =(Stone *)event->getUserData();
};
void Pig::beginFollow(){
    this->scheduleUpdate();
}

void Pig::update(float delay){
    if(_followStone){
        this->setPosition(Vec2(_followStone->getPositionX(),_followStone->getPositionY()));

    }
    if(this->getPositionY()<0){
        this->unscheduleUpdate();
        Director::getInstance()->replaceScene(GameOverLayer::createScene());
    }
};