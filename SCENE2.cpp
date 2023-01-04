


#include "cocos2d.h"
#include "SCENE2.h"
#include "SCENE1.h"
#include "SCENE3.h"
#include "AudioEngine.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* SCENE2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    auto layer = SCENE2::create();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setDebugDrawMask(0);
    scene->addChild(layer);

    return scene;
}

bool SCENE2::init()
{
    if (!Layer::init()) {
        return false;
    }


    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getVisibleSize();
    /////////////////////////////////////////////////////////////////////////
    // 



    auto background_rect1 = DrawNode::create();
    background_rect1->drawSolidRect(origin, winSize, Color4F(1.0, 0.94, 0.87, 1.0)); //bg orange
    this->addChild(background_rect1);


    auto player1 = Sprite::create("Player_fly.png");
    player1->setPosition(Vec2(50, 150));
    player1->setScale(0.26); //scale dyal player
    this->addChild(player1, 2);
    //  creating physique for player


    auto player2 = Sprite::create("physic-33.png");
    player2->setScale(0.12); 


    auto physicsBody_player = PhysicsBody::createBox(player2->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));

    physicsBody_player->setDynamic(false);
    physicsBody_player->setCollisionBitmask(2);
    physicsBody_player->setCategoryBitmask(1);
    physicsBody_player->setContactTestBitmask(1);
    player1->setPhysicsBody(physicsBody_player);


    /////////////////////////////////////////



    auto* wall = Sprite::create("wall2.png");
    
    wall->setAnchorPoint(Vec2(0, 0));
    wall->setPosition(Vec2(420, 200));
    wall->setScale(0.125);
    this->addChild(wall, 3);

    //creating physique for THE FLOOR

    auto physicsBody_wall = PhysicsBody::createBox(wall->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall->setDynamic(false);
    physicsBody_wall->setCollisionBitmask(1);
    physicsBody_wall->setCategoryBitmask(1);
    physicsBody_wall->setContactTestBitmask(1);

    wall->setPhysicsBody(physicsBody_wall);

    /////////////////////////////////////////



    auto* wall2 = Sprite::create("wall2.png");

    wall2->setAnchorPoint(Vec2(0, 0));
    wall2->setPosition(Vec2(420, -200));
    wall2->setScale(0.125);
    this->addChild(wall2, 3);

    //creating physique for THE FLOOR

    auto physicsBody_wall2 = PhysicsBody::createBox(wall2->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall2->setDynamic(false);
    physicsBody_wall2->setCollisionBitmask(1);
    physicsBody_wall2->setCategoryBitmask(1);
    physicsBody_wall2->setContactTestBitmask(1);

    wall2->setPhysicsBody(physicsBody_wall2);



    /////////////////////////////////////////



    auto* wall3 = Sprite::create("wall2.png");

    wall3->setAnchorPoint(Vec2(0, 0));
    wall3->setPosition(Vec2(880, 240));
    wall3->setScale(0.125);
    this->addChild(wall3, 3);
    auto physicsBody_wall3 = PhysicsBody::createBox(wall3->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall3->setDynamic(false);
    physicsBody_wall3->setCollisionBitmask(1);
    physicsBody_wall3->setCategoryBitmask(1);
    physicsBody_wall3->setContactTestBitmask(1);

    wall3->setPhysicsBody(physicsBody_wall3);

    /////////////////////////////////////////



    auto* wall4 = Sprite::create("wall2.png");

    wall4->setAnchorPoint(Vec2(0, 0));
    wall4->setPosition(Vec2(880, -160));
    wall4->setScale(0.125);
    this->addChild(wall4, 3);
    auto physicsBody_wall4 = PhysicsBody::createBox(wall4->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall4->setDynamic(false);
    physicsBody_wall4->setCollisionBitmask(1);
    physicsBody_wall4->setCategoryBitmask(1);
    physicsBody_wall4->setContactTestBitmask(1);

    wall4->setPhysicsBody(physicsBody_wall4);


    /////////////////////////////////////////

    auto* wall5 = Sprite::create("wall2.png");

    wall5->setAnchorPoint(Vec2(0, 0));
    wall5->setPosition(Vec2(1340, 160));
    wall5->setScale(0.125);
    this->addChild(wall5, 5);
    auto physicsBody_wall5 = PhysicsBody::createBox(wall5->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall5->setDynamic(false);
    physicsBody_wall5->setCollisionBitmask(1);
    physicsBody_wall5->setCategoryBitmask(1);
    physicsBody_wall5->setContactTestBitmask(1);
    wall5->setPhysicsBody(physicsBody_wall5);

    /////////////////////////////////////////



    auto* wall6 = Sprite::create("wall2.png");

    wall6->setAnchorPoint(Vec2(0, 0));
    wall6->setPosition(Vec2(1340, -240));
    wall6->setScale(0.125);
    this->addChild(wall6,3);
    auto physicsBody_wall6 = PhysicsBody::createBox(wall6->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall6->setDynamic(false);
    physicsBody_wall6->setCollisionBitmask(1);
    physicsBody_wall6->setCategoryBitmask(1);
    physicsBody_wall6->setContactTestBitmask(1);

    wall6->setPhysicsBody(physicsBody_wall6);




    /////////////////////////////////////////
        /////////////////////////////////////////



    auto* wall7 = Sprite::create("wall3.png");

    wall7->setAnchorPoint(Vec2(0, 0));
    wall7->setPosition(Vec2(1800, 290));
    wall7->setScale(0.125);
    this->addChild(wall7, 3);
    auto physicsBody_wall7 = PhysicsBody::createBox(wall7->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall7->setDynamic(false);
    physicsBody_wall7->setCollisionBitmask(1);
    physicsBody_wall7->setCategoryBitmask(1);
    physicsBody_wall7->setContactTestBitmask(1);

    wall7->setPhysicsBody(physicsBody_wall7);
///////////////////////////////////////////////////////

    auto* wall8 = Sprite::create("wall3.png");

    wall8->setAnchorPoint(Vec2(0, 0));
    wall8->setPosition(Vec2(1800, -110));
    wall8->setScale(0.125);
    this->addChild(wall8, 3);
    auto physicsBody_wall8 = PhysicsBody::createBox(wall8->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall8->setDynamic(false);
    physicsBody_wall8->setCollisionBitmask(1);
    physicsBody_wall8->setCategoryBitmask(1);
    physicsBody_wall8->setContactTestBitmask(1);
    wall8->setPhysicsBody(physicsBody_wall8);

    //////////////////////////////////////////////////////////////////


    auto* wall9 = Sprite::create("wall3.png");

    wall9->setAnchorPoint(Vec2(0, 0));
    wall9->setPosition(Vec2(2100, 130));
    wall9->setScale(0.125);
    this->addChild(wall9, 3);
    auto physicsBody_wall9 = PhysicsBody::createBox(wall9->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall9->setDynamic(false);
    physicsBody_wall9->setCollisionBitmask(1);
    physicsBody_wall9->setCategoryBitmask(1);
    physicsBody_wall9->setContactTestBitmask(1);

    wall9->setPhysicsBody(physicsBody_wall9);
    ///////////////////////////////////////////////////////

    auto* wall10 = Sprite::create("wall3.png");

    wall10->setAnchorPoint(Vec2(0, 0));
    wall10->setPosition(Vec2(2100, -280));
    wall10->setScale(0.125);
    this->addChild(wall10, 3);
    auto physicsBody_wall10 = PhysicsBody::createBox(wall10->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall10->setDynamic(false);
    physicsBody_wall10->setCollisionBitmask(1);
    physicsBody_wall10->setCategoryBitmask(1);
    physicsBody_wall10->setContactTestBitmask(1);
    wall10->setPhysicsBody(physicsBody_wall10);

    ///////////////////////////////////////////


    auto* wall11 = Sprite::create("wall3.png");

    wall11->setAnchorPoint(Vec2(0, 0));
    wall11->setPosition(Vec2(2600, 100));
    wall11->setScale(0.125);
    this->addChild(wall11, 3);
    auto physicsBody_wall11 = PhysicsBody::createBox(wall11->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall11->setDynamic(false);
    physicsBody_wall11->setCollisionBitmask(1);
    physicsBody_wall11->setCategoryBitmask(1);
    physicsBody_wall11->setContactTestBitmask(1);

    wall11->setPhysicsBody(physicsBody_wall11);
    ///////////////////////////////////////////////////////

    auto* wall12 = Sprite::create("wall3.png");

    wall12->setAnchorPoint(Vec2(0, 0));
    wall12->setPosition(Vec2(2600, -300));
    wall12->setScale(0.125);
    this->addChild(wall12, 3);
    auto physicsBody_wall12 = PhysicsBody::createBox(wall12->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall12->setDynamic(false);
    physicsBody_wall12->setCollisionBitmask(1);
    physicsBody_wall12->setCategoryBitmask(1);
    physicsBody_wall12->setContactTestBitmask(1);
    wall12->setPhysicsBody(physicsBody_wall12);


    //////////////////////////////////////////////////




    auto* wall13 = Sprite::create("wall3.png");

    wall13->setAnchorPoint(Vec2(0, 0));
    wall13->setPosition(Vec2(2663, 120));
    wall13->setScale(0.125);
    this->addChild(wall13, 3);
    auto physicsBody_wall13 = PhysicsBody::createBox(wall13->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall13->setDynamic(false);
    physicsBody_wall13->setCollisionBitmask(1);
    physicsBody_wall13->setCategoryBitmask(1);
    physicsBody_wall13->setContactTestBitmask(1);

    wall13->setPhysicsBody(physicsBody_wall13);


    ///////////////////////////////////////////////////////

    auto* wall14 = Sprite::create("wall3.png");

    wall14->setAnchorPoint(Vec2(0, 0));
    wall14->setPosition(Vec2(2663, -280));
    wall14->setScale(0.125);
    this->addChild(wall14, 3);
    auto physicsBody_wall14 = PhysicsBody::createBox(wall14->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall14->setDynamic(false);
    physicsBody_wall14->setCollisionBitmask(1);
    physicsBody_wall14->setCategoryBitmask(1);
    physicsBody_wall14->setContactTestBitmask(1);
    wall14->setPhysicsBody(physicsBody_wall14);

    ///////////////////////////////////////////////////////////


    auto* wall15 = Sprite::create("wall3.png");

    wall15->setAnchorPoint(Vec2(0, 0));
    wall15->setPosition(Vec2(2726, 140));
    wall15->setScale(0.125);
    this->addChild(wall15, 3);
    auto physicsBody_wall15 = PhysicsBody::createBox(wall15->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall15->setDynamic(false);
    physicsBody_wall15->setCollisionBitmask(1);
    physicsBody_wall15->setCategoryBitmask(1);
    physicsBody_wall15->setContactTestBitmask(1);

    wall15->setPhysicsBody(physicsBody_wall15);




    /////////////////////////////////////////
        /////////////////////////////////////////



    auto* wall16 = Sprite::create("wall3.png");

    wall16->setAnchorPoint(Vec2(0, 0));
    wall16->setPosition(Vec2(2726, -260));
    wall16->setScale(0.125);
    this->addChild(wall16, 3);
    auto physicsBody_wall16 = PhysicsBody::createBox(wall16->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall16->setDynamic(false);
    physicsBody_wall16->setCollisionBitmask(1);
    physicsBody_wall16->setCategoryBitmask(1);
    physicsBody_wall16->setContactTestBitmask(1);

    wall16->setPhysicsBody(physicsBody_wall16);
    ///////////////////////////////////////////////////////

    auto* wall17 = Sprite::create("wall3.png");

    wall17->setAnchorPoint(Vec2(0, 0));
    wall17->setPosition(Vec2(2789, 160));
    wall17->setScale(0.125);
    this->addChild(wall17, 3);
    auto physicsBody_wall17 = PhysicsBody::createBox(wall17->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall17->setDynamic(false);
    physicsBody_wall17->setCollisionBitmask(1);
    physicsBody_wall17->setCategoryBitmask(1);
    physicsBody_wall17->setContactTestBitmask(1);
    wall17->setPhysicsBody(physicsBody_wall17);

    //////////////////////////////////////////////////////////////////


    auto* wall18 = Sprite::create("wall3.png");

    wall18->setAnchorPoint(Vec2(0, 0));
    wall18->setPosition(Vec2(2789, -240));
    wall18->setScale(0.125);
    this->addChild(wall18, 3);
    auto physicsBody_wall18 = PhysicsBody::createBox(wall18->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall18->setDynamic(false);
    physicsBody_wall18->setCollisionBitmask(1);
    physicsBody_wall18->setCategoryBitmask(1);
    physicsBody_wall18->setContactTestBitmask(1);

    wall18->setPhysicsBody(physicsBody_wall18);
    ///////////////////////////////////////////////////////

    auto* wall19 = Sprite::create("wall3.png");

    wall19->setAnchorPoint(Vec2(0, 0));
    wall19->setPosition(Vec2(2852, 180));
    wall19->setScale(0.125);
    this->addChild(wall19, 3);
    auto physicsBody_wall19 = PhysicsBody::createBox(wall19->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall19->setDynamic(false);
    physicsBody_wall19->setCollisionBitmask(1);
    physicsBody_wall19->setCategoryBitmask(1);
    physicsBody_wall19->setContactTestBitmask(1);
    wall19->setPhysicsBody(physicsBody_wall19);

    ///////////////////////////////////////////


    auto* wall20 = Sprite::create("wall3.png");

    wall20->setAnchorPoint(Vec2(0, 0));
    wall20->setPosition(Vec2(2852, -220));
    wall20->setScale(0.125);
    this->addChild(wall20, 3);
    auto physicsBody_wall20 = PhysicsBody::createBox(wall20->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall20->setDynamic(false);
    physicsBody_wall20->setCollisionBitmask(1);
    physicsBody_wall20->setCategoryBitmask(1);
    physicsBody_wall20->setContactTestBitmask(1);

    wall20->setPhysicsBody(physicsBody_wall20);
    ///////////////////////////////////////////////////////

    auto* wall21 = Sprite::create("wall3.png");

    wall21->setAnchorPoint(Vec2(0, 0));
    wall21->setPosition(Vec2(2915 , 200));
    wall21->setScale(0.125);
    this->addChild(wall21, 3);
    auto physicsBody_wall21 = PhysicsBody::createBox(wall21->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall21->setDynamic(false);
    physicsBody_wall21->setCollisionBitmask(1);
    physicsBody_wall21->setCategoryBitmask(1);
    physicsBody_wall21->setContactTestBitmask(1);
    wall21->setPhysicsBody(physicsBody_wall21);


    //////////////////////////////////////////////////




    auto* wall22 = Sprite::create("wall3.png");

    wall22->setAnchorPoint(Vec2(0, 0));
    wall22->setPosition(Vec2(2915 , -200));
    wall22->setScale(0.125);
    this->addChild(wall22, 3);
    auto physicsBody_wall22 = PhysicsBody::createBox(wall22->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall22->setDynamic(false);
    physicsBody_wall22->setCollisionBitmask(1);
    physicsBody_wall22->setCategoryBitmask(1);
    physicsBody_wall22->setContactTestBitmask(1);

    wall22->setPhysicsBody(physicsBody_wall22);


    //////////////////////////////////////////////////////////KEY



    auto* key = Sprite::create("key.png");

    key->setAnchorPoint(Vec2(0, 0));
    key->setPosition(Vec2(3150, 50));
    key->setScale(0.125);
    this->addChild(key, 3);
    auto physicsBody_key = PhysicsBody::createBox(key->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_key->setDynamic(false);
    physicsBody_key->setCollisionBitmask(4);
    physicsBody_key->setCategoryBitmask(1);
    physicsBody_key->setContactTestBitmask(1);

    key->setPhysicsBody(physicsBody_key);



    ////////////////////////////////////////////////////



    auto* door = Sprite::create("door.png");
    door->setAnchorPoint(Vec2(0, 0));
    door->setPosition(Vec2(3300, 160));
    door->setScale(0.25);
    this->addChild(door, 3);


    auto physicsBody_door = PhysicsBody::createCircle((door->getContentSize().width / 2) - 120, PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_door->setDynamic(false);
    physicsBody_door->setCollisionBitmask(5);
    physicsBody_door->setCategoryBitmask(1);
    physicsBody_door->setContactTestBitmask(1);


    door->setPhysicsBody(physicsBody_door);







    ///////////////////////////////Keyboard events

    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(SCENE1::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(SCENE1::onKeyPressed, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    keyboardListener->onKeyPressed = [player1](EventKeyboard::KeyCode KeyCode, Event* event)
    {

        if (KeyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 20.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(0, 150));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player1->runAction(repeatAction);
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 20.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(120, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player1->runAction(repeatAction);

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 50.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(-120, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player1->runAction(repeatAction);

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 20.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(0, -150));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player1->runAction(repeatAction);
        }

    };

    /////////////////stoper mouvement de player 

    keyboardListener->onKeyReleased = [player1](EventKeyboard::KeyCode KeyCode, Event* event)
    {
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            player1->stopAllActions();
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            player1->stopAllActions();
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
            player1->stopAllActions();
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
            player1->stopAllActions();
        }


    };





    




    auto* acc = MoveBy::create(0.045 * winSize.width, Point(-winSize.width * 6, 0));
    
    auto* acc1 = MoveBy::create(1.0, Vec2(0,-130));
    auto* acc2 = MoveBy::create(1.0, Vec2(0, 130));

    auto seq = Sequence::create(acc1,acc2 ,nullptr);
    auto Spawn1 = Spawn::createWithTwoActions(acc, seq);
    auto seq1 = Sequence::create(Spawn1, nullptr);


    wall->runAction(acc->clone());
    wall2->runAction(acc->clone());
    wall3->runAction(acc->clone());
    wall4->runAction(acc->clone());
    wall5->runAction(acc->clone());
    wall6->runAction(acc->clone());
    wall7->runAction(acc->clone());
    wall8->runAction(acc->clone());
    wall9->runAction(acc->clone());
    wall10->runAction(acc->clone());
    wall11->runAction(acc->clone());
    wall12->runAction(acc->clone());
    wall13->runAction(acc->clone());
    wall14->runAction(acc->clone());
    wall15->runAction(acc->clone());
    wall16->runAction(acc->clone());
    wall17->runAction(acc->clone());
    wall18->runAction(acc->clone());
    wall19->runAction(acc->clone());
    wall20->runAction(acc->clone());
    wall21->runAction(acc->clone());
    wall22->runAction(acc->clone());
    key->runAction(acc->clone());
    door->runAction(acc->clone());


    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [key](PhysicsContact& contact) {

        PhysicsBody* x = contact.getShapeA()->getBody();
        PhysicsBody* y = contact.getShapeB()->getBody();

        if (1 == x->getCollisionBitmask() && 2 == y->getCollisionBitmask() || 2 == x->getCollisionBitmask() && 1 == y->getCollisionBitmask()) {

            auto scene = Gameover::createScene();
            Director::getInstance()->pushScene(TransitionFade::create(0.5, scene));
            cocos2d::AudioEngine::preload("gameover.mp3"); //upload de notre music mp3 en v4 de cocos
            cocos2d::AudioEngine::play2d("gameover.mp3");
        }


        if (2 == x->getCollisionBitmask() && 3 == y->getCollisionBitmask() || 3 == x->getCollisionBitmask() && 2 == y->getCollisionBitmask()) {
            auto scene2 = SCENE3::createScene();
            Director::getInstance()->pushScene(TransitionSplitCols::create(0.4, scene2));
            cocos2d::AudioEngine::preload("win.mp3"); //upload de notre music mp3 en v4 de cocos
            cocos2d::AudioEngine::play2d("win.mp3");
        }
        ////////keycntact
        if (2 == x->getCollisionBitmask() && 4 == y->getCollisionBitmask() || 4 == x->getCollisionBitmask() && 2 == y->getCollisionBitmask()) {
            key->setOpacity(0);
        }
        //////door contact
        if (2 == x->getCollisionBitmask() && 5 == y->getCollisionBitmask() || 5 == x->getCollisionBitmask() && 2 == y->getCollisionBitmask()) {
            if (key->getOpacity()==0)
            {
                auto scene2 = SCENE3::createScene();
                Director::getInstance()->pushScene(TransitionSplitCols::create(0.4, scene2));
                cocos2d::AudioEngine::preload("win.mp3"); //upload de notre music mp3 en v4 de cocos
                cocos2d::AudioEngine::play2d("win.mp3");
            }
            else
            {
                auto scene = Gameover::createScene();
                Director::getInstance()->pushScene(TransitionFade::create(0.5, scene));
                cocos2d::AudioEngine::preload("gameover.mp3"); //upload de notre music mp3 en v4 de cocos
                cocos2d::AudioEngine::play2d("gameover.mp3");
            }
        }

        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


    cocos2d::AudioEngine::preload("SCENE2.mp3"); //upload de notre music mp3 en v4 de cocos
    cocos2d::AudioEngine::play2d("SCENE2.mp3", true);    //PLAY MUSIC //true whwnever t7lat hello world


    return true;
}

