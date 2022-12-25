#pragma once
#ifndef __HelloWorld__SCENE_H__
#define __HelloWorld_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;


class HelloWorld: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    //a selector one
    void menuCloseCallback(cocos2d::Ref* pSender);


    CREATE_FUNC(HelloWorld);
    cocos2d::Sprite* menuback;
    cocos2d::Menu *menu1;
   //menu items
    void play(Ref * pSender);
    void highscores(Ref* psender);
    void imgbutton(Ref *psender);
   
    
};
#endif