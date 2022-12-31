#pragma once
#ifndef SCENE3_H
#define SCENE3_SCENE_H
#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;


class SCENE3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
   


    CREATE_FUNC(SCENE3);
   

};



#endif