#pragma once
#ifndef win_H
#define win_SCENE_H
#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;


class win: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(win);


    cocos2d::Menu* menu5;
    cocos2d::Sprite* win1;
  
  
    void winer(Ref* pSender);
  


};


#endif