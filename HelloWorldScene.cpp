#include "cocos2d.h"
#include "SCENE1.h" //pour pouvoir switcher vers
#include "AudioEngine.h" //biblio pour importer les audioa
#include "HelloWorldScene.h"
#include "SCENE3.h"
#include <iostream>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init()) {
        return false;
    }

    auto  origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();

    //////////////////menu background

    auto menuback = Sprite::create("menu_background.png");
    menuback->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    menuback->setScale(0.125);

    ////////////////Pico Park LOGO

    this->addChild(menuback);
    auto* menu = Menu::create();
    menu->setPosition(Point(0, 0));
    this->addChild(menu);
    auto start_button = Sprite::create("start_button.png");
    auto start_button_selected = Sprite::create("start_button_selected.png");

    //////////////Play button

    MenuItemImage* menu_play = MenuItemImage::create();
    menu_play->setNormalImage(start_button);
    menu_play->setSelectedImage(start_button_selected);
    menu_play->setCallback(CC_CALLBACK_1(HelloWorld::play, this));
    menu->addChild(menu_play, 4);
    menu_play->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 2)));

    /////////////upload music

    cocos2d::AudioEngine::preload("music.mp3"); //upload de notre music mp3 en v4 de cocos
    auto a=cocos2d::AudioEngine::play2d("music.mp3", true);    //PLAY MUSIC //true whwnever t7lat hello world
    return true;
}



  ///Fonction pour aller au niveau 1 quand on click sur PLAY

void HelloWorld::play(cocos2d::Ref* PSender) {
    auto scene1 = SCENE1::createScene();
    Director::getInstance()->pushScene(TransitionSplitCols::create(1, scene1)); //la scene qu on veut y switch vers
    cocos2d::AudioEngine::stopAll(); //stoper la music quand on clique sur play
}


            
