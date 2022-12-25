
#include "SCENE1.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* SCENE1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = SCENE1::create();

    scene->addChild(layer);

    return scene;
}

bool SCENE1::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto  origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    // notre background/////////////////////////////////////////////////////////////
   // auto background = Sprite::create("background.png");
    //background->setAnchorPoint(Vec2(0, 0));
    //background->setPosition(Vec2(0,0));
    //this->addChild(background, 0);
/////////////////////////////////////////////////////////////////////////
// 
    auto  origin1 = Director::getInstance()->getVisibleOrigin();
    auto visibleSize1 = Director::getInstance()->getVisibleSize();



    auto go = MenuItemFont::create("IT S JUST A TEST ", CC_CALLBACK_1(SCENE1::go, this));
    go->setPosition(Point(visibleSize1.width / 2, (visibleSize1.height / 2) ));
    auto* menu3 = Menu::create();
    menu3->setPosition(Point(0, 0));
    this->addChild(menu3);
    auto* menu2 = Menu::create(go,  NULL);

    menu2->setPosition(Point(0, 0));
    this->addChild(menu2);
    return true;
}
    void SCENE1::go(cocos2d::Ref * PSender) {
        Director::getInstance()->popScene(); //revenier a la scene hello world
    }


       




            