
#include "SCENE1.h"
#include "AudioEngine.h"




USING_NS_CC;

Scene* SCENE1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -250));

    // 'layer' is an autorelease object
    auto layer = SCENE1::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}



bool SCENE1::init()
{
    if (!Layer::init()) {
        return false;
    }



    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getVisibleSize();


    ////////////////   backround rectangle


    auto background_rect = DrawNode::create();
    background_rect->drawSolidRect(origin, winSize, Color4F(1.0, 0.94, 0.87, 1.0)); //bg orange
    this->addChild(background_rect);



    ///////////////////  add Sprite

    auto pinfo = AutoPolygon::generatePolygon("Player.png");
    auto player = Sprite::create(pinfo);
    player->setAnchorPoint(Vec2(0.5f, 0.5f));
    player->setPosition(Vec2(50, 60));
    player->setScale(0.3); //scale dyal player
    player->setName("player");
    this->addChild(player, 2);
    //  creating physique for player

   // auto physicsBody1 = PhysicsBody::createBox(player->getContentSize() , PhysicsMaterial(1000.0f, 0.5f, 0.5f));
    auto physicsBody1 = PhysicsBody::createBox(player->getContentSize(), PhysicsMaterial(1000.0f, 0.5f, 0.5f));
    // physicsBody1->setGravityEnable(true);
    // physicsBody1->setDynamic(true);
    physicsBody1->setContactTestBitmask(1);
    // physicsBody1->setCategoryBitmask(1);
    player->setPhysicsBody(physicsBody1);
    //physicsBody1->applyForce(Vec2(100, 100));
    //physicsBody1->setLinearDamping(0.2f);


  //////////////////////create the background that iclude PICO PARK

    auto background = Sprite::create("background.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Vec2(0, 0));
    background->setScale(0.125);
    this->addChild(background, 0);
    ///////////////////////////////////// creating the floor1(THe LAND)

    auto floor = Sprite::create("land-15.png");
    floor->setAnchorPoint(Vec2(0, 0));
    floor->setPosition(Vec2(0, 0));
    floor->setScale(0.125);
    this->addChild(floor, 1);

    //creating physique for THE FLOOR

    auto physicsBody_floor = PhysicsBody::createBox(floor->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));

    physicsBody_floor->setDynamic(false);
    physicsBody_floor->setCollisionBitmask(1);
    physicsBody_floor->setCategoryBitmask(1);


    floor->setPhysicsBody(physicsBody_floor);



    ///////////////////////////////////// creating the floor2(THe LAND)

    auto floor2 = Sprite::create("land-14.png");
    floor2->setAnchorPoint(Vec2(1, 0));
    floor2->setPosition(Vec2(480, 0));
    floor2->setScale(0.125);
    this->addChild(floor2, 1);

    //creating physique for THE FLOOR

    auto physicsBody_floor2 = PhysicsBody::createBox(floor2->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));

    physicsBody_floor2->setDynamic(false);
    physicsBody_floor2->setCollisionBitmask(1);
    physicsBody_floor2->setCategoryBitmask(1);


    floor2->setPhysicsBody(physicsBody_floor2);



    //////////////////////////////////////  create obstacle1

    auto obstacle1 = Sprite::create("obstacle1.png");
    obstacle1->setAnchorPoint(Vec2(0, 0));
    obstacle1->setPosition(Vec2(150, 40));
    obstacle1->setScale(0.125);
    this->addChild(obstacle1, 1);

    auto physicsBody_obstacle1 = PhysicsBody::createBox(obstacle1->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
    physicsBody_obstacle1->setDynamic(false);
    obstacle1->setPhysicsBody(physicsBody_obstacle1);

    //////////////////////////////

    auto pit_1 = Sprite::create("obstacle1.png");
    pit_1->setAnchorPoint(Vec2(0, 0));
    pit_1->setPosition(Vec2(330, -100));
    pit_1->setScale(0.125);
    this->addChild(pit_1, 1);

    auto physicsBody_pit_1 = PhysicsBody::createCircle(pit_1->getContentSize().width / 2, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    physicsBody_pit_1->setContactTestBitmask(1);
    physicsBody_pit_1->setDynamic(false);
    pit_1->setPhysicsBody(physicsBody_pit_1);

    /////////////////////////////


   // Create a keyboard event listener
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(SCENE1::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(SCENE1::onKeyPressed, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    keyboardListener->onKeyPressed = [player](EventKeyboard::KeyCode KeyCode, Event* event)
    {

        if (KeyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
            auto action1 = JumpBy::create(0.7f, Vec2(80, 50), 60.0f, 1);
            player->runAction(action1);
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 50.0f, 1);
            MoveBy* moveAction = MoveBy::create(2, Vec2(70, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player->runAction(repeatAction);
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 50.0f, 1);
            MoveBy* moveAction = MoveBy::create(2, Vec2(-70, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player->runAction(repeatAction);

        }

    };


    keyboardListener->onKeyReleased = [player](EventKeyboard::KeyCode KeyCode, Event* event)
    {
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            player->stopAllActions();
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            player->stopAllActions();
        }

    };

    ////////////////////////////////////


     //////////////////////////////
    auto spriteBody = PhysicsBody::createBox(player->getContentSize(), PhysicsMaterial(0, 1, 0));
    spriteBody->setCollisionBitmask(1);
    spriteBody->setCollisionBitmask(true);
    // void reload(cocos2d::Ref* pSender);

    auto contactlistener = EventListenerPhysicsContact::create();
    contactlistener->onContactBegin = CC_CALLBACK_1(SCENE1::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactlistener, this);

    ////////////////////////////
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [](PhysicsContact& contact) {
        auto scene = SCENE1::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(0.3, scene));
        cocos2d::AudioEngine::preload("gameover.mp3"); //upload de notre music mp3 en v4 de cocos
        cocos2d::AudioEngine::play2d("gameover.mp3");

        auto shapeA = contact.getShapeA();
        auto body1 = shapeA->getBody();
        auto shapeB = contact.getShapeB();
        auto body2 = shapeB->getBody();

        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    ////////////////////////
    return true;
}


void SCENE1::reload(cocos2d::Ref* pSender) {
    auto scene = SCENE1::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.2, scene));
}


bool SCENE1::onContactBegin(cocos2d::PhysicsContact& contact) {
    PhysicsBody* x = contact.getShapeA()->getBody();
    PhysicsBody* y = contact.getShapeB()->getBody();
    if (1 == x->getCollisionBitmask() && 2 == y->getCollisionBitmask() || 2 == x->getCollisionBitmask() && 1 == y->getCollisionBitmask()) {

        void reload(cocos2d::Ref * pSender);
    }
    return true;
}



    /////////////////////////////////////////////////////////////////////


 //   void SCENE1::reload(cocos2d::Ref* pSender) {
   //     auto scene = SCENE1::createScene();
     //   Director::getInstance()->replaceScene(TransitionFade::create(0.4, scene)); //game over et refaire la scene
    //}

//void SCENE1::go(cocos2d::Ref* PSender) {
  //  Director::getInstance()->popScene(); //revenier a la scene hello world
//}

   
//}
    
