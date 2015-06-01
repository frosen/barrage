//
//  MgrAutoBee.h
//  barrage
//  自动飞行器管理器，内部维护一个池，创建多个AutoBee，使用时拿走，不使用时归还，可以下次继续使用
//  加载飞行器的类型，并管理其纹理
//  Created by luleyan on 15/5/23.
//
//

#ifndef __barrage__MgrAutoBee__
#define __barrage__MgrAutoBee__

#include "cocos2d.h"
#include "AutoBee.h"

USING_NS_CC;

class AutoBeeInMgr : public AutoBee
{
public:
    AutoBeeInMgr();
    virtual ~AutoBeeInMgr();
    
    static AutoBeeInMgr* create();
    
    //重载死亡动作，归还核心到池中
    void die();
    
protected:
    int m_nIndex; //索引蜜蜂在管理器中数组的位置
};

class MgrAutoBee : public Ref
{
public:
    MgrAutoBee();
    virtual ~MgrAutoBee();
    
    static MgrAutoBee* getInstance();
    static void destroyInstance();
    
    AutoBee* getUnusedBee();
    AutoBee* getUnusedBeeAndChangeClothes(AutoBeeType type);
    
protected:
    AutoBee** m_arpAutoBee; //蜜蜂指针的数组
};

#endif /* defined(__barrage__MgrAutoBee__) */
