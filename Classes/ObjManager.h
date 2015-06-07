//
//  ObjManager.h
//  PigRun
//
//  Created by Eavawu on 5/24/15.
//
//

#ifndef __PigRun__ObjManager__
#define __PigRun__ObjManager__
#include "MHeader.h"
#include "Stone.h"
#include <stdio.h>
class ObjManager:public Ref{
public:
    ObjManager();
    list<Stone *> stoneList;
    ~ObjManager();
    static ObjManager *_objManager;
    static ObjManager *getInstance();
    Stone *generateStone();
    void  recycleStone();
    int stoneIndex=1;
    void changeSpeed(int speed);

};
#endif /* defined(__PigRun__ObjManager__) */
