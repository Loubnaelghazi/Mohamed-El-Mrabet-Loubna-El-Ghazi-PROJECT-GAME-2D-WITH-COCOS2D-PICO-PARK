#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "SCENE1.h" //pour pouvoir switcher vers
#include "AudioEngine.h"
//biblio pour importer les audios
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
    // notre background/////////////////////////////////////////////////////////////
   // auto background = Sprite::create("background.png");
    //background->setAnchorPoint(Vec2(0, 0));
    //background->setPosition(Vec2(0,0));
    //this->addChild(background, 0);
/////////////////////////////////////////////////////////////////////////
// 
//elements du menu ////////////////
    //creation du menu 
    //background de menu :
    menuback = Sprite::create("background.png");
    menuback->setPosition(Point((visibleSize.width /2)+origin.x,(visibleSize.height/2)+origin.y));
  //  menuback->setAnchorPoint(Vec2(0, 0));
    //menuback->setPosition(Vec2(0, 0));
       this->addChild(menuback);
        auto  *menu=Menu ::create();
        menu->setPosition(Point(0, 0));
        this->addChild(menu);
///////////////////////////
///ajout des elements:
        auto menu_play = MenuItemFont::create("PLAY", CC_CALLBACK_1(HelloWorld::play,this)); //boutton play
      //  auto menu_highscore = MenuItemFont::create("HIGHSCORES", CC_CALLBACK_1(HelloWorld::highscores, this));
       // auto imgbutton = MenuItemFont::create("start3.jpg",CC_CALLBACK_1(HelloWorld::imgbutton,this));

       menu_play->setPosition(Point(visibleSize.width/2,(visibleSize.height/3) ));
       // imgbutton->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 3) * 1));
        //positionnement //2 au milieu
       // menu_highscore->setPosition(Point(visibleSize.width / 2 , (visibleSize.height / 4) * 1)); //3 la fin 
       // menu_highscore->setScale(0.5, 0.5);
        //pour 1  c le 
        //9smna 3la 4 cuz 3ndna 3 items, ila 3ndna 4 an9smu 3la 5 and so on...  

        //on peut utiliser tout simplement la fct alignitems qui fait le meme travail
        menu_play->setColor(Color3B::RED);
        auto *menu1 = Menu::create(menu_play,NULL);
        menu1->setPosition(Point(0,0));
        this->addChild(menu1);

        //upload music
        cocos2d::AudioEngine::preload("music.mp3"); //upload de notre music mp3 en v4 de cocos
        cocos2d::AudioEngine::play2d("music.mp3",true);    //PLAY MUSIC //true whwnever t7lat hello world
      
                                                                    
    return true;
}


        //implemetation des fcts crees :
        void HelloWorld::play(cocos2d::Ref * PSender) {
            CCLOG("PLAY"); //affichage de play 
            //fct en cliquant sur play, on switch vers scene 1    
            auto scene1 = SCENE1::createScene();
            Director::getInstance()->pushScene(scene1); //la scene qu on veut y switch vers
            cocos2d::AudioEngine::stopAll(); //stoper la music quand on clique sur play
        }
        //void HelloWorld::highscores(cocos2d::Ref* PSender) {
          //  CCLOG("HIGHSCORES"); //affichage de play 
        //}

        void HelloWorld::imgbutton(cocos2d::Ref* Psender) {
            CCLOG("IMAGE BUTTON");
        }

        

            