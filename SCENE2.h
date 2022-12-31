#pragma once
#ifndef SCENE2_H
#define SCENE2_SCENE_H
#include "cocos2d.h"
using namespace cocos2d;


USING_NS_CC;


class SCENE2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();


    CREATE_FUNC(SCENE2);


};



#endif