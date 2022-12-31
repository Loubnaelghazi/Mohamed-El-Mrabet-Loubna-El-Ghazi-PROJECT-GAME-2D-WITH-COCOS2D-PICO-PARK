
#include "cocos2d.h"
#include "SCENE3 .h" 

USING_NS_CC;

Scene* SCENE3::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = SCENE3::create();

    scene->addChild(layer);

    return scene;
}

bool SCENE3::init()
{
    if (!Layer::init()) {
        return false;
    }
   
  
    auto origin3 = Director::getInstance()->getVisibleOrigin();
    auto winSize3 = Director::getInstance()->getVisibleSize();
/////////////////////////////////////////////////////////////////////////
// 
    auto background_rect3 = DrawNode::create();
    background_rect3->drawSolidRect(origin3, winSize3, Color4F(1.0, 0.94, 0.87, 1.0)); //bg orange
    this->addChild(background_rect3);

    ///////////////////  add Sprite

    auto player3 = Sprite::create("Player.png");
    player3->setAnchorPoint(Vec2(0.5, 0.5));
    player3->setPosition(Vec2(50, 60));
    player3->setScale(0.3); //scale dyal player
    player3->setName("player3");
    this->addChild(player3, 2);



   

















