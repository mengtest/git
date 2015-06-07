//
//  StartLayer.cpp
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#include "StartLayer.h"
// on "init" you need to initialize your instance
bool StartLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init())
    {
        return false;
    }
    addSearchPath();
    loadRes();
    loadUI();
    
    return true;
}
Scene* StartLayer::createScene(){
    Scene * scene = Scene::create();
    Layer * layer = StartLayer::create();
    scene->addChild(layer);
    return scene;
};
void StartLayer::loadUI(){
    Size winSize = Director::getInstance()->getWinSize();
   // auto cbsUI = CSBL
    Node* node = CSLoader::createNode("StartScene.csb");
    node->setAnchorPoint(Vec2(0.5, 0.5));
    node->setPosition(Vec2(winSize.width/2,winSize.height/2));
    Widget *nodeWidget =  static_cast<Widget *>(node);
    Button *startBtn = static_cast<Button*>(Helper::seekWidgetByName(nodeWidget, "play_btn"));
    startBtn->setTag(1);
    startBtn->addTouchEventListener(CC_CALLBACK_2(StartLayer::touchEvent,this));
    this->addChild(node);
};
void StartLayer::loadRes(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Plist.plist");
    Director::getInstance()->getTextureCache()->addImage("Default/defaultBMFont.png");
};
void StartLayer::addSearchPath(){
    FileUtils::getInstance()->addSearchPath("res/");
};
void StartLayer::touchEvent(Ref *pSender, Widget::TouchEventType type){
    Director::getInstance()->replaceScene(GameLayer::createScene());
//    Button *btn = static_cast<Button *>(pSender);
//    EventCustom customEvent(SHOW_EVENT);
//    int num = 2;
//    customEvent.setUserData(&num);
//    Director::getInstance()->getEventDispatcher()->dispatchEvent(&customEvent);
//       log("%s",btn->getName().c_str());
};