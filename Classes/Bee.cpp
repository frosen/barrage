//
//  Bee.cpp
//  barrage
//  所有飞行物的基类
//  Created by luleyan on 15/5/23.
//
//

#include "Bee.h"

Bee::Bee():
    Sprite(),
    m_strName("unnamed"),
    m_type(TypeBee::AutoBee),
    m_nCollisionDistance(-1)
{
    
}

Bee::~Bee()
{

}
