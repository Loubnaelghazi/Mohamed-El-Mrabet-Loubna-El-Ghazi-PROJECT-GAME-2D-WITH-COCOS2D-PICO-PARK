#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "AudioEngine.h"
#include "SCENE1.h"
#include "Gameover.h"

USING_NS_CC;

Scene* Gameover::createScene()
{
    auto scene = Scene::create();
    auto layer = Gameover::create();

    scene->addChild(layer);

    return scene;
}

bool Gameover::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto  origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();


    auto* gameover = Sprite::create("gameover.png");
    gameover->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
    gameover->setScale(0.125);
    this->addChild(gameover);

    auto* menu2 = Menu::create();
    menu2->setPosition(Point(0, 0));
    this->addChild(menu2);


    ///ajout des elements:

    auto* restart = Sprite::create("restart.png");
    auto* restart_bu = Sprite::create("restartS.png");
    MenuItemImage* menu_restart = MenuItemImage::create();
    menu_restart->setNormalImage(restart);
    menu_restart->setSelectedImage(restart_bu);
    menu_restart->setCallback(CC_CALLBACK_1(Gameover::reload, this)); //reload du game on click
    menu_restart->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2) + 30));
    menu2->addChild(menu_restart, 3);


    auto main_menu = Sprite::create("mainmenu.png");
    auto main_menu_bu = Sprite::create("mainmenuS.png");
    MenuItemImage* menu_main = MenuItemImage::create();
    menu_main->setNormalImage(main_menu);
    menu_main->setSelectedImage(main_menu_bu);
    menu_main->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2) - 30));
    menu_main->setCallback(CC_CALLBACK_1(Gameover::reload2, this)); // du game on click
    menu2->addChild(menu_main, 4);





    //   menu_restart->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 3) * 2));
     //  menu_main->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 3) * 3));


    return true;
}

void Gameover::reload(cocos2d::Ref* pSender) {
    auto scene = SCENE1::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.4, scene)); //game over et refaire la scene
}

void Gameover::reload2(cocos2d::Ref* pSender) {
    auto scene2 = HelloWorld::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.4, scene2)); //game over et refaire la scene
}