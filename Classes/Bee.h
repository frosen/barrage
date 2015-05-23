//
//  Bee.h
//  barrage
//
//  Created by luleyan on 15/5/23.
//
//

#ifndef __barrage__Bee__
#define __barrage__Bee__

#include "cocos2d.h"
USING_NS_CC;

class Bee : public cocos2d::Sprite
{
public:
    enum class TypeBee{
        AutoBee, //自动飞行器
        ManualBee, //手动操作的飞行器
    };
    
    Bee();
    virtual ~Bee();
    
    //不能建立Bee的实例
    static Bee* create() { CCASSERT(false, "virtual class"); }
    
protected:
    std::string m_strName; //蜜蜂的名字
    TypeBee m_type; //类型
    
    //碰撞距离，蜜蜂之间靠横竖坐标差之和与碰撞距离比较，默认-1 永远不会被碰到
    int m_nCollisionDistance;
};


#endif /* defined(__barrage__Bee__) */
