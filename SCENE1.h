#pragma once
#ifndef __SCENE1__SCENE_H__
#define __SCENE1_SCENE_H__
#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;


class SCENE1: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    cocos2d::Sprite* mysprite;
    cocos2d::Menu* menu2;
    CREATE_FUNC(SCENE1);
    void go(Ref* pSender);
    
};
#endif
