#pragma once
#ifndef SCENE1SCENE_H
#define SCENE1_SCENE_H
#include "cocos2d.h"
#include "cocos2d.h"
#include "physics/CCPhysicsWorld.h"
#include "physics-nodes/CCPhysicsSprite.h"
#include "physics/CCPhysicsContact.h"
#include "Box2D/Box2D.h"
#include "Box2D/Dynamics/b2WorldCallbacks.h"
USING_NS_CC;
using namespace cocos2d;



class SCENE1 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(SCENE1);
    // void go(Ref* pSender);

    void reload1(Ref* pSender); //fct de replacement de scene lors d echec
    void play(Ref* pSender); //fct de passage vers scene lorsque le joueuer arrive a la porte


    bool onContactBegin(cocos2d::PhysicsContact& contact);


};


#endif
