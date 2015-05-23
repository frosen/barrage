//
//  AutoBee.h
//  barrage
//  可以根据脚本自动飞行的飞行器
//  有蜜蜂管理器对其进行管理
//  Created by luleyan on 15/5/23.
//
//

#ifndef __barrage__AutoBee__
#define __barrage__AutoBee__

#include "cocos2d.h"
#include "Bee.h"
#include "BeatNum.h"

USING_NS_CC;

struct AutoBeeType
{
    bool canFilpX; //是否会根据移动进行flip变换
    bool canTurn; //是否会根据移动方向转换角度
    bool isFileFromFrame;
    std::string name;
    std::string fileName;
};

class AutoBee : public Bee
{
public:
    //变速类型
    enum class TypeEase
    {
        NO_EASE,
        
    };
    
    //镜像类型
    enum class TypeMirror
    {
        NO_MIRROR,
        Y_AXIS, //Y轴对称镜像
        X_AXIS,
        CENTER,
    };
    
    AutoBee();
    virtual ~AutoBee();
    
    //创建一个AutoBee的核，可以事先生成出多个核心放入池中备用
    //使用时，通过换装（换UI和属性）变成不同的样式，使用结束后重新放回池子中
    static AutoBee* create();
    
    //根据类型进行换装
    void changeClothes(AutoBeeType type);
    
    //出生（起始位置，角度，使用的节拍数）
    void born(Vec2 vec, int angle, BeatNum useBeat = 0);
    
    //死亡
    void die();
    
    //移动（使用的节拍数，移动位置，变速类型，角度系数，镜像系数），返回最终速度
    float moveBy(BeatNum useBeat, Vec2 pos, TypeEase etype = TypeEase::NO_EASE, int angleFactor = 0, TypeMirror mType = TypeMirror::NO_MIRROR);
    
    float moveTo(BeatNum useBeat, Vec2 pos, TypeEase etype = TypeEase::NO_EASE, int angleFactor = 0, TypeMirror mType = TypeMirror::NO_MIRROR);
    
    //向前移动（使用的节拍数，移动速度<每一拍移动的距离>，角度，变速类型，角度系数，镜像系数），返回最终位置
    Vec2 goForward(BeatNum useBeat, float speed, int angle, TypeEase etype = TypeEase::NO_EASE, int angleFactor = 0, TypeMirror mType = TypeMirror::NO_MIRROR);
    
    //跟踪
    void moveAndTrack(BeatNum ustBeat, float speed, Bee* target, int maxTurn = 360, TypeEase etype = TypeEase::NO_EASE);
    
    
protected:
    
};

#endif /* defined(__barrage__AutoBee__) */




