#pragma once
#ifndef HelloWorldSCENE_H
#define HelloWorld_SCENE_H
#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;


class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    //a selector one
    void menuCloseCallback(cocos2d::Ref* pSender);


    CREATE_FUNC(HelloWorld);
    cocos2d::Sprite* menuback;
    cocos2d::Menu* menu1;
    void play(cocos2d::Ref* PSender);
    void imgbutton(Ref* psender);

    static int restart;


};



#endif
