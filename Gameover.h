#pragma once
#ifndef Gameover_H
#define Gameover_SCENE_H
#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;


class Gameover : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    //a selector one
    void menuCloseCallback(cocos2d::Ref* pSender);


    CREATE_FUNC(Gameover);
    cocos2d::Sprite* gameover;
    cocos2d::Menu* menu2;
    //menu items
    void play(Ref* pSender);
    void reload(cocos2d::Ref* pSender);
    void reload2(cocos2d::Ref* pSender);




};



#endif