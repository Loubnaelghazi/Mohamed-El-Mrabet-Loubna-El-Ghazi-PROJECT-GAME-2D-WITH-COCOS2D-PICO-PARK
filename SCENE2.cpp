
#include "cocos2d.h"
#include "SCENE2.h"
#include "SCENE1.h"

USING_NS_CC;

Scene* SCENE2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = SCENE2::create();

    scene->addChild(layer);

    return scene;
}

bool SCENE2::init()
{
    if (!Layer::init()) {
        return false;
    }


    auto origin1 = Director::getInstance()->getVisibleOrigin();
    auto winSize1 = Director::getInstance()->getVisibleSize();
    /////////////////////////////////////////////////////////////////////////
    // 
    auto background_rect1 = DrawNode::create();
    background_rect1->drawSolidRect(origin1, winSize1, Color4F(1.0, 0.94, 0.87, 1.0)); //bg orange
    this->addChild(background_rect1);


    auto player1 = Sprite::create("Player.png");
    player1->setPosition(Vec2(50, 60));
    player1->setScale(0.3); //scale dyal playe
    this->addChild(player1, 2);
    //  creating physique for player

   





















   

return true;
}


//void SCENE2::switch2(cocos2d::Ref* pSender) {
  //  auto scene = SCENE3::createScene();
   // Director::getInstance()->pushScene(TransitionFade::create(0.4, scene)); //SWITCHER VERS SCENE 3
//}