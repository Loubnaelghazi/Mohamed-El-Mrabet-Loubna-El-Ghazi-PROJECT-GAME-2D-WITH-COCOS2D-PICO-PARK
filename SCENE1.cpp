#include "SCENE1.h"
#include "AudioEngine.h"
#include "Gameover.h"
#include "HelloWorldScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsJoint.h"

USING_NS_CC;

Scene* SCENE1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));
    scene->getPhysicsWorld()->setDebugDrawMask(0);

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

    auto player = Sprite::create("Player.png");
    player->setAnchorPoint(Vec2(0.5, 0.5));
    player->setPosition(Vec2(50, 60));
    player->setScale(0.3); //scale dyal player
    player->setName("player");
    this->addChild(player, 2);

    ////////////////////  creating physique for player

    auto physicsBody1 = PhysicsBody::createBox(player->getContentSize(), PhysicsMaterial(1000.0f, 0.5f, 0.5f));
    physicsBody1->setDynamic(true);
    physicsBody1->setContactTestBitmask(1);
    physicsBody1->setRotationEnable(false);
    physicsBody1->setCollisionBitmask(1);
    player->setPhysicsBody(physicsBody1);
    Vec2 force = Vec2(0, -physicsBody1->getMass() * 9.8f);
    physicsBody1->applyForce(force);


    //////////////////////create the background that iclude PICO PARK

    auto background = Sprite::create("background.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Vec2(0, 0));
    background->setScale(0.125);
    this->addChild(background, 0);
    ///////////////////////////////////// creating the floors and the obstacles

    auto* floor = Sprite::create("land-15.png");
    floor->setAnchorPoint(Vec2(0, 0));
    floor->setPosition(Vec2(0, 0));
    floor->setScale(0.125);
    this->addChild(floor, 1);

    auto physicsBody_floor = PhysicsBody::createBox(floor->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
    physicsBody_floor->setDynamic(false);
    physicsBody_floor->setCollisionBitmask(1);
    physicsBody_floor->setCategoryBitmask(1);


    floor->setPhysicsBody(physicsBody_floor);


    ///////////////////////////////////// 

    auto* floor2 = Sprite::create("ground-02.png");
    floor2->setAnchorPoint(Vec2(0, 0));
    floor2->setPosition(Vec2(374, 0));
    floor2->setScale(0.125);
    this->addChild(floor2, 1);


    auto physicsBody_floor2 = PhysicsBody::createBox(floor2->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
    physicsBody_floor2->setDynamic(false);
    physicsBody_floor2->setCollisionBitmask(1);
    physicsBody_floor2->setCategoryBitmask(1);


    floor2->setPhysicsBody(physicsBody_floor2);



    /////////////////////////////////////////////////



    auto* floor3 = Sprite::create("ground-03.png");
    floor3->setAnchorPoint(Vec2(0, 0));
    floor3->setPosition(Vec2(853, 0));
    floor3->setScale(0.125);
    this->addChild(floor3, 3);

    auto physicsBody_floor3 = PhysicsBody::createBox(floor3->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
    physicsBody_floor3->setDynamic(false);
    physicsBody_floor3->setCollisionBitmask(1);
    physicsBody_floor3->setCategoryBitmask(1);


    floor3->setPhysicsBody(physicsBody_floor3);

    ////////////////////////////////////////////////////////////////////


    auto* floor4 = Sprite::create("ground-13.png");
    floor4->setAnchorPoint(Vec2(0, 0));
    floor4->setPosition(Vec2(729, 75));
    floor4->setScale(0.125);
    this->addChild(floor4, 3);


    auto physicsBody_floor4 = PhysicsBody::createBox(floor4->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
    physicsBody_floor4->setDynamic(false);
    physicsBody_floor4->setCollisionBitmask(1);
    physicsBody_floor4->setCategoryBitmask(1);


    floor4->setPhysicsBody(physicsBody_floor4);


    //////////////////////////////////////////////////////////////////////////


    auto* floor5 = Sprite::create("ground-04.png");
    floor5->setAnchorPoint(Vec2(0, 0));
    floor5->setPosition(Vec2(480, 40));
    floor5->setScale(0.125);
    this->addChild(floor5, 3);


    auto physicsBody_floor5 = PhysicsBody::createBox(floor5->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor5->setDynamic(false);
    physicsBody_floor5->setCollisionBitmask(1);
    physicsBody_floor5->setCategoryBitmask(1);


    floor5->setPhysicsBody(physicsBody_floor5);


/////////////////////////////////////////////////////////////


    auto* floor6 = Sprite::create("ground-05.png");
    floor6->setAnchorPoint(Vec2(0, 0));
    floor6->setPosition(Vec2(513,40));
    floor6->setScale(0.125);
    this->addChild(floor6, 3);


    auto physicsBody_floor6 = PhysicsBody::createBox(floor6->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor6->setDynamic(false);
    physicsBody_floor6->setCollisionBitmask(1);
    physicsBody_floor6->setCategoryBitmask(1);


    floor6->setPhysicsBody(physicsBody_floor6);


///////////////////////////////////////////////////////////////////


    auto* floor7 = Sprite::create("ground-06.png");
    floor7->setAnchorPoint(Vec2(0, 0));
    floor7->setPosition(Vec2(546,40));
    floor7->setScale(0.125);
    this->addChild(floor7, 3);


    auto physicsBody_floor7 = PhysicsBody::createBox(floor7->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor7->setDynamic(false);
    physicsBody_floor7->setCollisionBitmask(1);
    physicsBody_floor7->setCategoryBitmask(1);


    floor7->setPhysicsBody(physicsBody_floor7);


    ///////////////////////////////////////////////////////////////////


    auto* floor8 = Sprite::create("ground-07.png");
    floor8->setAnchorPoint(Vec2(0, 0));
    floor8->setPosition(Vec2(977, 47));
    floor8->setScale(0.125);
    this->addChild(floor8, 3);



    auto physicsBody_floor8 = PhysicsBody::createBox(floor8->getContentSize(), PhysicsMaterial(1000.0f, 0.5f, 0.5f));
    physicsBody_floor8->setDynamic(false);
    physicsBody_floor8->setCollisionBitmask(3);
    physicsBody_floor8->setCategoryBitmask(1);
    physicsBody_floor8->setContactTestBitmask(1);

    floor8->setPhysicsBody(physicsBody_floor8);


    ///////////////////////////////////////////////////////////////////


    auto* floor9 = Sprite::create("ground-08.png");
    floor9->setAnchorPoint(Vec2(0, 0));
    floor9->setPosition(Vec2(1063, 40));
    floor9->setScale(0.125);
    this->addChild(floor9, 3);


    auto physicsBody_floor9 = PhysicsBody::createBox(floor9->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor9->setDynamic(false);
    physicsBody_floor9->setCollisionBitmask(1);
    physicsBody_floor9->setCategoryBitmask(1);


    floor9->setPhysicsBody(physicsBody_floor9);


    ///////////////////////////////////////////////////////////////////


    auto* floor10 = Sprite::create("ground-09.png");
    floor10->setAnchorPoint(Vec2(0, 0));
    floor10->setPosition(Vec2(1099, 40));
    floor10->setScale(0.125);
    this->addChild(floor10, 3);


    auto physicsBody_floor10 = PhysicsBody::createBox(floor10->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor10->setDynamic(false);
    physicsBody_floor10->setCollisionBitmask(1);
    physicsBody_floor10->setCategoryBitmask(1);


    floor10->setPhysicsBody(physicsBody_floor10);


    ///////////////////////////////////////////////////////////////////


    auto* floor11 = Sprite::create("ground-10.png");
    floor11->setAnchorPoint(Vec2(0, 0));
    floor11->setPosition(Vec2(1135 , 40));
    floor11->setScale(0.125);
    this->addChild(floor11, 3);


    auto physicsBody_floor11 = PhysicsBody::createBox(floor11->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor11->setDynamic(false);
    physicsBody_floor11->setCollisionBitmask(1);
    physicsBody_floor11->setCategoryBitmask(1);


    floor11->setPhysicsBody(physicsBody_floor11);


    ///////////////The door Sprite


    auto* door = Sprite::create("door.png");
    door->setAnchorPoint(Vec2(0, 0));
    door->setPosition(Vec2(1500, 40));
    door->setScale(0.25);
    this->addChild(door, 3);


    auto physicsBody_door = PhysicsBody::createCircle((door->getContentSize().width/2)-120, PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_door->setDynamic(false);
    physicsBody_door->setCollisionBitmask(2);
    physicsBody_door->setCategoryBitmask(1);
    physicsBody_door->setContactTestBitmask(1);


    door->setPhysicsBody(physicsBody_door);


    //////////////////////////////////////  create obstacle1

    auto* obstacle1 = Sprite::create("obstacle1-10.png");
    obstacle1->setAnchorPoint(Vec2(0, 0));
    obstacle1->setPosition(Vec2(150, 40));
    obstacle1->setScale(0.125);
    this->addChild(obstacle1, 1);

    auto physicsBody_obstacle1 = PhysicsBody::createBox(obstacle1->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_obstacle1->setDynamic(false);
    obstacle1->setPhysicsBody(physicsBody_obstacle1);



    //////////////////////////// 



    auto* pit_1 = Sprite::create("floor.png");
    pit_1->setAnchorPoint(Vec2(0, 0));
    pit_1->setPosition(Vec2(0, -150));
    pit_1->setScale(0.125);
    this->addChild(pit_1, 1);

    auto physicsBody_pit_1 = PhysicsBody::createBox(pit_1->getContentSize(), PhysicsMaterial(1.0f, 1.0f, 1.0f));
    physicsBody_pit_1->setContactTestBitmask(1);
    physicsBody_pit_1->setDynamic(false);
    physicsBody_pit_1->setCollisionBitmask(4);
    pit_1->setPhysicsBody(physicsBody_pit_1);



    //////////////////////////////////action for the Groun objetcts


    auto* acc = MoveBy::create(0.07 * winSize.width, Point(-winSize.width * 4, 0));


    obstacle1->runAction(acc->clone());
    floor->runAction(acc->clone());
    floor2->runAction(acc->clone());
    floor3->runAction(acc->clone());
    floor4->runAction(acc->clone());
    floor5->runAction(acc->clone());
    floor6->runAction(acc->clone());
    floor7->runAction(acc->clone());
    floor8->runAction(acc->clone());
    floor9->runAction(acc->clone());
    floor10->runAction(acc->clone());
   floor11->runAction(acc->clone());
   door->runAction(acc->clone());







    ///////////////////////////////Events for the player

   // Create a keyboard event listener
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(SCENE1::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(SCENE1::onKeyPressed, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    keyboardListener->onKeyPressed = [player](EventKeyboard::KeyCode KeyCode, Event* event)
    {

        if (KeyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
            auto action1 = JumpBy::create(0.57f, Vec2(50, 100), 15.0f, 1);
            auto easeAction = EaseOut::create(action1, 2.0f);
            player->runAction(action1);
            cocos2d::AudioEngine::preload("jump.mp3"); //upload de notre music mp3 en v4 de cocos
            cocos2d::AudioEngine::play2d("jump.mp3");

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 20.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(70, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player->runAction(repeatAction);

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 50.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(-70, 0));
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



    
     ////////////////////////////// contact Event


    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [floor8](PhysicsContact& contact) {


        PhysicsBody* x = contact.getShapeA()->getBody();
        PhysicsBody* y = contact.getShapeB()->getBody();
        if (1 == x->getCollisionBitmask() && 3 == y->getCollisionBitmask() || 3 == x->getCollisionBitmask() && 1 == y->getCollisionBitmask()) {
            MoveBy* moveact = MoveBy::create(1.2, Vec2(0, 90));
            floor8->runAction(moveact);

        }

        if (1 == x->getCollisionBitmask() && 4 == y->getCollisionBitmask() || 4 == x->getCollisionBitmask() && 1 == y->getCollisionBitmask()) {

            auto scene = Gameover::createScene();
            Director::getInstance()->pushScene(TransitionFade::create(0.5, scene));
            cocos2d::AudioEngine::preload("gameover.mp3"); //upload de notre music mp3 en v4 de cocos
            cocos2d::AudioEngine::play2d("gameover.mp3");
        }

        if (1 == x->getCollisionBitmask() && 2 == y->getCollisionBitmask() || 2 == x->getCollisionBitmask() && 1 == y->getCollisionBitmask()) {
            auto scene2 = SCENE2::createScene();
            Director::getInstance()->pushScene(TransitionSplitCols::create(0.4, scene2));
            cocos2d::AudioEngine::preload("win.mp3"); //upload de notre music mp3 en v4 de cocos
            cocos2d::AudioEngine::play2d("win.mp3");
        }


        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
  

    return true;
}




bool SCENE1::onContactBegin(cocos2d::PhysicsContact& contact) {
   
    return true;
}



///////////////////////////////////////////////////////////////////






