//
//  ObjManager.cpp
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#include "ObjManager.h"
#include "MHeader.h"
ObjManager *ObjManager::_objManager = NULL;
ObjManager *ObjManager::getInstance(){
    if (!_objManager) {
        _objManager = new ObjManager();
    }
    return _objManager;
};
ObjManager::ObjManager(){


};
ObjManager::~ObjManager(){
    delete _objManager;
};
Stone *ObjManager::generateStone(){
    Stone *stone = Stone::create();
    stone->setTag(stoneIndex);
//    stoneIndex;
    stoneList.push_back(stone);
    stone->beginMove();
    return stone;
};
void  ObjManager::recycleStone(){
    
//    list<Stone *>::iterator i;
//    for (i = stoneList.begin(); i != stoneList.end();){
//        Stone *pStone = *i;
//        if (pStone->isRecycle) {
//            log("回收的：%d",pStone->getTag());
//        }
////        if (pStone->isRecycle) {
////            stoneList.erase(i);
////            log("recycle %d",pStone->getTag());
////        }else{
////            i++;
////        }
//    }
};
