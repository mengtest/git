#include "GameLayer.h"
#include "TopLayer.h"
USING_NS_CC;


// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init())
    {
        return false;
    }
    addTouch();
    loadUI();
    addPig();
    objManager = ObjManager::getInstance();
    test();
    addTopLayer();
    this->schedule( schedule_selector(GameLayer::generateUpdate), speep );
    return true;
}
Scene* GameLayer::createScene(){
    Scene * scene = Scene::create();
    Layer * layer = GameLayer::create();
    scene->addChild(layer);
    return scene;

};
void GameLayer::addTouch(){
    auto _eventListener = EventListenerTouchOneByOne::create();
    _eventListener->setSwallowTouches(false);
    
    _eventListener->onTouchBegan = [this](Touch* touch, Event* event) -> bool
    {
        Director::getInstance()->replaceScene(GameOverLayer::createScene());

        log("touch begin游戏结束");
        return false;           // Don't claim the touch so it can propagate
    };
    
    _eventListener->onTouchEnded = [](Touch* touch, Event* event)
    {
        // Do nothing
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_eventListener, this);

};
void GameLayer::addPig(){
    if (_pig) {
       
    }
    _pig = Pig::getInstance();
    _pig->removeFromParent();
    _pig->setPosition(100,100);
    this->addChild(_pig,1);
};
void GameLayer::loadUI(){
    Size winSize = Director::getInstance()->getWinSize();
    Node* node = CSLoader::createNode("GameLayer.csb");
    node->setAnchorPoint(Vec2(0.5, 0.5));
    node->setPosition(Vec2(winSize.width/2,winSize.height/2));
    this->addChild(node);

};
void GameLayer::touchEvent(Ref *pSender, Widget::TouchEventType type){

};
void GameLayer::test(){
   Stone *stone = objManager->generateStone();
    if (isFirstFollow) {
        isFirstFollow = false;
        _pig->setFollowStone(stone);
        _pig->beginFollow();
    }
    this->addChild(stone);
//    objManager->recycleStone();
}
void GameLayer::onExit(){
    Layer::onExit();
    _pig->removeFromParentAndCleanup(true);
    toplayer->removeFromParentAndCleanup(true);
};
void GameLayer::generateUpdate(float delay){
    test();
};
void GameLayer::addTopLayer(){
    Size winSize = Director::getInstance()->getWinSize();
    toplayer = TopLayer::create();
    this->addChild(toplayer);
    toplayer->setPosition(Vec2(100,winSize.height-toplayer->getContentSize().height));
    toplayer->retain();

};


