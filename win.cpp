#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "SCENE3 .h"
#include "win.h"
#include "AudioEngine.h"
USING_NS_CC;

Scene* win::createScene()
{

    auto scene4 = Scene::create();
    auto layer = win::create();

    scene4->addChild(layer);

    return scene4;
}

bool win::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto  origin6 = Director::getInstance()->getVisibleOrigin();
    auto visibleSize6 = Director::getInstance()->getVisibleSize();
   
  ////////////////////////////////background
    auto win1 = Sprite::create("youwin.png");
    win1->setPosition(Point((visibleSize6.width / 2) + origin6.x, (visibleSize6.height / 2) + origin6.y));
    win1->setScale(0.125);
    this->addChild(win1);
////////////////////////////////////////////
    auto* menu5 = Menu::create();
    menu5->setPosition(Point(0, 0));
    this->addChild(menu5);
    ///////////////////////////


    ///ajout des elements:

    auto main_button = Sprite::create("mainmenu.png");
    auto  main_button_selected = Sprite::create("mainmenus.png");
    MenuItemImage* main_button1 = MenuItemImage::create();
    main_button1->setNormalImage(main_button);
    main_button1->setSelectedImage(main_button_selected);
    main_button1->setPosition(Point((visibleSize6.width / 2), (visibleSize6.height / 2) +38));
    main_button1->setCallback(CC_CALLBACK_1(win::winer, this));

    ////////////
    menu5->addChild (main_button1, 4);
    cocos2d::AudioEngine::preload("youwin.mp3"); //upload de notre music mp3 en v4 de cocos
    cocos2d::AudioEngine::play2d("youwin.mp3");    //PLAY MUSIC //

    return true;
}




//implemetation des fcts crees :
void  win::winer (cocos2d::Ref* PSender) {
       
    auto scene1 = HelloWorld::createScene();
    Director::getInstance()->pushScene(TransitionSplitCols::create(1, scene1)); //la scene qu on veut y switch vers
}
