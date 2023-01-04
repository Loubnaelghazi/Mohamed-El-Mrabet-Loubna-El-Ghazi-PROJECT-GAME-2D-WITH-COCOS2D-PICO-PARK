
#include "AudioEngine.h"
#include "cocos2d.h"
#include "SCENE3 .h" 
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsJoint.h"
#include "SCENE1.h"
#include "Gameover.h"
#include "win.h"
USING_NS_CC;

Scene* SCENE3::createScene()
{
    auto scene = Scene::create();
    auto layer = SCENE3::create();
    auto scene3 = Scene::createWithPhysics();
    scene3->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene3->getPhysicsWorld()->setGravity(Vec2(0, -500));
  scene3->getPhysicsWorld()->setDebugDrawMask(0);
    scene3->addChild(layer);

    return scene3;
}

bool SCENE3::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto origin3 = Director::getInstance()->getVisibleOrigin();
    auto winSize3 = Director::getInstance()->getVisibleSize();
    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


    //PHYSICS BODY FOR THE PLAYER
    auto physicsBody_player3 = PhysicsBody::createBox(player3->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
    physicsBody_player3->setDynamic(true);
    physicsBody_player3->setCollisionBitmask(1);
    physicsBody_player3->setCategoryBitmask(1);
    physicsBody_player3->setContactTestBitmask(1);
    physicsBody_player3->setRotationEnable(false);
    player3->setPhysicsBody(physicsBody_player3);



    //////////////////////create the background that iclude PICO PARK

    auto background3 = Sprite::create("background.png");
    background3->setAnchorPoint(Vec2(0, 0));
    background3->setPosition(Vec2(0, 0));
    background3->setScale(0.125);
    this->addChild(background3, 0);


    ////////FLOOR
    auto* floorA = Sprite::create("floor.png");
    floorA->setAnchorPoint(Vec2(0, 0));
    floorA->setPosition(Vec2(0, 0));
    floorA->setScale(0.125);
    this->addChild(floorA, 1);


    //creating physique for THE FLOOR

    auto physicsBody_floor = PhysicsBody::createBox(floorA->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));

    physicsBody_floor->setDynamic(false);
    physicsBody_floor->setCollisionBitmask(1);
    physicsBody_floor->setCategoryBitmask(1);
    floorA->setPhysicsBody(physicsBody_floor);

    ///// buttonS dont push 
    auto* dontpush2 = Sprite::create("button.png");
    dontpush2->setAnchorPoint(Vec2(0, 0));
    dontpush2->setPosition(Vec2(150, 40));
    dontpush2->setScale(0.30);
    this->addChild(dontpush2, 1);

    auto physicsBody_dontpush2 = PhysicsBody::createBox(dontpush2->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_dontpush2->setDynamic(false);
    physicsBody_dontpush2->setCollisionBitmask(1);
    physicsBody_dontpush2->setContactTestBitmask(1);
    dontpush2->setPhysicsBody(physicsBody_dontpush2);
    //////
    
    auto* dontpushs1 = Sprite::create("dont_push.png");
    dontpushs1->setAnchorPoint(Vec2(0, 0));
    dontpushs1->setPosition(Vec2(152, 60));
    dontpushs1->setScale(0.128);
    this->addChild(dontpushs1, 1);

    auto physicsBody_dontpushs1 = PhysicsBody::createBox(dontpushs1->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_dontpushs1->setDynamic(false);
    physicsBody_dontpushs1->setCollisionBitmask(0);
    physicsBody_dontpushs1->setContactTestBitmask(0);
    dontpushs1->setPhysicsBody(physicsBody_dontpushs1);
    ////////////

    auto* dontpush3 = Sprite::create("button.png");
    dontpush3->setAnchorPoint(Vec2(0, 0));
    dontpush3->setPosition(Vec2(257, 40));
    dontpush3->setScale(0.30);
    this->addChild(dontpush3, 1);

    auto physicsBody_dontpush3 = PhysicsBody::createBox(dontpush3->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_dontpush3->setDynamic(false);
    physicsBody_dontpush3->setCollisionBitmask(1);
    physicsBody_dontpush3->setContactTestBitmask(1);
    dontpush3->setPhysicsBody(physicsBody_dontpush3);

    ///////////
    auto* dontpushs = Sprite::create("dont_push.png");
    dontpushs->setAnchorPoint(Vec2(0, 0));
    dontpushs->setPosition(Vec2(259, 60));
    dontpushs->setScale(0.128);
    this->addChild(dontpushs, 1);

    auto physicsBody_dontpushs= PhysicsBody::createBox(dontpushs->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_dontpushs->setDynamic(false);
    physicsBody_dontpushs->setCollisionBitmask(0);
    physicsBody_dontpushs->setContactTestBitmask(0);
    dontpushs->setPhysicsBody(physicsBody_dontpushs);



    /////////ESCALIERS
    auto* floor3 = Sprite::create("ground-13.png");
    floor3->setAnchorPoint(Vec2(0, 0));
    floor3->setPosition(Vec2(850, 120));
    floor3->setScale(0.2);
    this->addChild(floor3, 3);

    //creating physique for THE FLOOR

    auto physicsBody_floor3 = PhysicsBody::createBox(floor3->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor3->setDynamic(false);
    physicsBody_floor3->setCollisionBitmask(1);
    physicsBody_floor3->setCategoryBitmask(1);
    floor3->setPhysicsBody(physicsBody_floor3);
    ////////
    auto* floor9 = Sprite::create("ground-08.png");
    floor9->setAnchorPoint(Vec2(0, 0));
    floor9->setPosition(Vec2(306, 40));
    floor9->setScale(0.125);
    this->addChild(floor9, 3);

    //creating physique for THE FLOOR
    auto physicsBody_floor9 = PhysicsBody::createBox(floor9->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor9->setDynamic(false);
    physicsBody_floor9->setCollisionBitmask(1);
    physicsBody_floor9->setCategoryBitmask(1);
    floor9->setPhysicsBody(physicsBody_floor9);


    ///////////////////////////////////////////////////////////////////
    auto* floor10 = Sprite::create("ground-09.png");
    floor10->setAnchorPoint(Vec2(0, 0));
    floor10->setPosition(Vec2(342, 40));
    floor10->setScale(0.125);
    this->addChild(floor10, 3);

    //creating physique for THE FLOOR

    auto physicsBody_floor10 = PhysicsBody::createBox(floor10->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor10->setDynamic(false);
    physicsBody_floor10->setCollisionBitmask(1);
    physicsBody_floor10->setCategoryBitmask(1);
    floor10->setPhysicsBody(physicsBody_floor10);

    ///////////////////////////////////////////////////////////////////
    auto* floor11 = Sprite::create("ground-10.png");
    floor11->setAnchorPoint(Vec2(0, 0));
    floor11->setPosition(Vec2(378, 40));
    floor11->setScale(0.125);
    this->addChild(floor11, 3);

    //creating physique for THE FLOOR

    auto physicsBody_floor11 = PhysicsBody::createBox(floor11->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_floor11->setDynamic(false);
    physicsBody_floor11->setCollisionBitmask(1);
    physicsBody_floor11->setCategoryBitmask(1);
    floor11->setPhysicsBody(physicsBody_floor11);


    //////white boxes //////

    auto* box2 = Sprite::create("box.png");
    box2->setAnchorPoint(Vec2(0, 0));
    box2->setPosition(Vec2(550, 38));
    box2->setScale(0.125);
    this->addChild(box2, 3);
    //creating physique for THE boxs

    auto physicsBody_box2 = PhysicsBody::createBox(box2->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box2->setDynamic(false);
    physicsBody_box2->setCollisionBitmask(5);
    physicsBody_box2->setCategoryBitmask(1);
    physicsBody_box2->setContactTestBitmask(1);
    box2->setPhysicsBody(physicsBody_box2);

    auto* box1 = Sprite::create("box.png");
    box1->setAnchorPoint(Vec2(0, 0));
    box1->setPosition(Vec2(575, 38));
    box1->setScale(0.125);
    this->addChild(box1, 3);
    auto physicsBody_box1 = PhysicsBody::createBox(box1->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box1->setDynamic(false);
    physicsBody_box1->setCollisionBitmask(5);
    physicsBody_box1->setCategoryBitmask(1);
    physicsBody_box1->setContactTestBitmask(1);
    box1->setPhysicsBody(physicsBody_box1);

    auto* box3 = Sprite::create("box.png");
    box3->setAnchorPoint(Vec2(0, 0));
    box3->setPosition(Vec2(600, 38));
    box3->setScale(0.125);
    this->addChild(box3, 3);
    auto physicsBody_box3 = PhysicsBody::createBox(box3->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box3->setDynamic(false);
    physicsBody_box3->setCollisionBitmask(5);
    physicsBody_box3->setCategoryBitmask(1);
    physicsBody_box3->setContactTestBitmask(1);
    box3->setPhysicsBody(physicsBody_box3);
    ////////////////////////////////////////////////////
    auto* box4 = Sprite::create("box.png");
    box4->setAnchorPoint(Vec2(0, 0));
    box4->setPosition(Vec2(625, 38));
    box4->setScale(0.125);
    this->addChild(box4, 3);
    auto physicsBody_box4 = PhysicsBody::createBox(box1->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box4->setDynamic(false);
    physicsBody_box4->setCollisionBitmask(5);
    physicsBody_box4->setCategoryBitmask(1);
    physicsBody_box4->setContactTestBitmask(1);
    box4->setPhysicsBody(physicsBody_box4);

    //////////////////////////////////////////////////////////
    auto* box5 = Sprite::create("box.png");
    box5->setAnchorPoint(Vec2(0, 0));
    box5->setPosition(Vec2(650, 38));
    box5->setScale(0.125);
    this->addChild(box5, 3);
    auto physicsBody_box5 = PhysicsBody::createBox(box5->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box5->setDynamic(false);
    physicsBody_box5->setCollisionBitmask(5);
    physicsBody_box5->setCategoryBitmask(1);
    physicsBody_box5->setContactTestBitmask(1);
    box5->setPhysicsBody(physicsBody_box5);

    ///////////////////////////////////////////////////////
    auto* box6 = Sprite::create("box.png");
    box6->setAnchorPoint(Vec2(0, 0));
    box6->setPosition(Vec2(675, 38));
    box6->setScale(0.125);
    this->addChild(box6, 3);
    auto physicsBody_box6 = PhysicsBody::createBox(box6->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box6->setDynamic(false);
    physicsBody_box6->setCollisionBitmask(5);
    physicsBody_box6->setCategoryBitmask(1);
    physicsBody_box6->setContactTestBitmask(1);
    box6->setPhysicsBody(physicsBody_box6);

    ///////////////////////////////////////////////////////
    auto* box7 = Sprite::create("box.png");
    box7->setAnchorPoint(Vec2(0, 0));
    box7->setPosition(Vec2(700, 38));
    box7->setScale(0.125);
    this->addChild(box7, 3);
    auto physicsBody_box7 = PhysicsBody::createBox(box7->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box7->setDynamic(false);
    physicsBody_box7->setCollisionBitmask(5);
    physicsBody_box7->setCategoryBitmask(1);
    physicsBody_box7->setContactTestBitmask(1);
    box7->setPhysicsBody(physicsBody_box7);
    ////////////////////////////////////////////////////////
    auto* box8 = Sprite::create("box.png");
    box8->setAnchorPoint(Vec2(0, 0));
    box8->setPosition(Vec2(725, 38));
    box8->setScale(0.125);
    this->addChild(box8, 3);
    auto physicsBody_box8 = PhysicsBody::createBox(box8->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box8->setDynamic(false);
    physicsBody_box8->setCollisionBitmask(5);
    physicsBody_box8->setCategoryBitmask(1);
    physicsBody_box8->setContactTestBitmask(1);
    box8->setPhysicsBody(physicsBody_box8);
    ///////////////////////////////////////////////////////////////
    auto* box9 = Sprite::create("box.png");
    box9->setAnchorPoint(Vec2(0, 0));
    box9->setPosition(Vec2(750, 38));
    box9->setScale(0.125);
    this->addChild(box9, 3);
    auto physicsBody_box9 = PhysicsBody::createBox(box9->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box9->setDynamic(false);
    physicsBody_box9->setCollisionBitmask(5);
    physicsBody_box9->setCategoryBitmask(1);
    physicsBody_box9->setContactTestBitmask(1);
    box9->setPhysicsBody(physicsBody_box9);
    /////////////////////////////////////////////////////////////////
    auto* box10 = Sprite::create("box.png");
    box10->setAnchorPoint(Vec2(0, 0));
    box10->setPosition(Vec2(775, 38));
    box10->setScale(0.125);
    this->addChild(box10, 3);
    auto physicsBody_box10 = PhysicsBody::createBox(box10->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box10->setDynamic(false);
    physicsBody_box10->setCollisionBitmask(5);
    physicsBody_box10->setCategoryBitmask(1);
    physicsBody_box10->setContactTestBitmask(1);
    box10->setPhysicsBody(physicsBody_box10);
    ////////////////////////////////////////////////////////////////////////
    auto* box11 = Sprite::create("box.png");
    box11->setAnchorPoint(Vec2(0, 0));
    box11->setPosition(Vec2(800, 38));
    box11->setScale(0.125);
    this->addChild(box11, 3);
    auto physicsBody_box11 = PhysicsBody::createBox(box11->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_box11->setDynamic(false);
    physicsBody_box11->setCollisionBitmask(5);
    physicsBody_box11->setCategoryBitmask(1);
    physicsBody_box11->setContactTestBitmask(1);
    box11->setPhysicsBody(physicsBody_box11);

/////////////////////////////////////////////////////////////////////////////////////
    auto* boxi = Sprite::create("box.png");
    boxi->setAnchorPoint(Vec2(0, 0));
    boxi->setPosition(Vec2(1710, 180));
    boxi->setScale(0.130);
    this->addChild(boxi, 3);
    auto physicsBody_boxi = PhysicsBody::createBox(boxi->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_boxi->setDynamic(false);
    physicsBody_boxi->setCollisionBitmask(5);
    physicsBody_boxi->setCategoryBitmask(1);
    physicsBody_boxi->setContactTestBitmask(1);
    boxi->setPhysicsBody(physicsBody_boxi);


    //////////////////////////////////////////////////////////////////////////////////////
    auto* boxa = Sprite::create("box.png");
    boxa->setAnchorPoint(Vec2(0, 0));
    boxa->setPosition(Vec2(1000, 150));
    boxa->setScale(0.130);
    this->addChild(boxa, 3);
    auto physicsBody_boxa = PhysicsBody::createBox(boxa->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_boxa->setDynamic(false);
    physicsBody_boxa->setCollisionBitmask(5);
    physicsBody_boxa->setCategoryBitmask(1);
    physicsBody_boxa->setContactTestBitmask(1);
    boxa->setPhysicsBody(physicsBody_boxa);
    ////////FLOOr///////////////////////////////////////////////////
    auto* floorb = Sprite::create("floor.png");
    floorb->setAnchorPoint(Vec2(0, 0));
    floorb->setPosition(Vec2(1100, 0));
    floorb->setScale(0.125);
    this->addChild(floorb, 1);

    //creating physique for THE FLOOR

    auto physicsBody_floorb = PhysicsBody::createBox(floorb->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
    physicsBody_floorb->setDynamic(false);
    physicsBody_floorb->setCollisionBitmask(1);
    physicsBody_floorb->setCategoryBitmask(1);
    floorb->setPhysicsBody(physicsBody_floorb);
    ////////////////////////////
    // 
    //WALLS////////////////////
    auto* wall7 = Sprite::create("wall3.png");

    wall7->setAnchorPoint(Vec2(0, 0));
    wall7->setPosition(Vec2(1400, 60));
    wall7->setScale(0.125);
    this->addChild(wall7, 3);
    auto physicsBody_wall7 = PhysicsBody::createBox(wall7->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_wall7->setDynamic(false);
    physicsBody_wall7->setCollisionBitmask(1);
    physicsBody_wall7->setCategoryBitmask(1);
    wall7->setPhysicsBody(physicsBody_wall7);

    /////////////////////////////////////////////////////////////////////

    auto* floor8 = Sprite::create("ground-07.png");
    floor8->setAnchorPoint(Vec2(0, 0));
    floor8->setPosition(Vec2(1205, 47));
    floor8->setScale(0.125);
    this->addChild(floor8, 3);

    //creating physique for THE FLOOR

    auto physicsBody_floor8 = PhysicsBody::createBox(floor8->getContentSize(), PhysicsMaterial(1000.0f, 0.5f, 0.5f));

    physicsBody_floor8->setDynamic(false);
    physicsBody_floor8->setCollisionBitmask(3);
    physicsBody_floor8->setCategoryBitmask(1);
    physicsBody_floor8->setContactTestBitmask(1);

    floor8->setPhysicsBody(physicsBody_floor8);
    ///////////////////////////////////////////////////////

    auto* floor6 = Sprite::create("ground-13.png");
    floor6->setAnchorPoint(Vec2(0, 0));
    floor6->setPosition(Vec2(1297, 200));
    floor6->setScale(0.2);
    this->addChild(floor6, 3);

    //creating physique for THE FLOOR

    auto physicsBody_floor6 = PhysicsBody::createBox(floor6->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_floor6->setDynamic(false);
    physicsBody_floor6->setCollisionBitmask(1);
    physicsBody_floor6->setCategoryBitmask(1);


    floor6->setPhysicsBody(physicsBody_floor6);

    ///////////////////////////////////////push ////////////////////////////////////////////////////
    auto* push = Sprite::create("button.png");
    push->setAnchorPoint(Vec2(0, 0));
    push->setPosition(Vec2(1345,214));
    push->setScale(0.3);
    this->addChild(push, 6);

  auto physicsBody_push = PhysicsBody::createBox(push->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_push->setDynamic(false);
    physicsBody_push->setCollisionBitmask(4);
    physicsBody_push->setContactTestBitmask(1);
    push->setPhysicsBody(physicsBody_push);

    /// push2////////////

    auto* push2 = Sprite::create("button.png");
    push2->setAnchorPoint(Vec2(0, 0));
    push2->setPosition(Vec2(1630, 92));
    push2->setScale(0.3);
    this->addChild(push2, 6);

    auto physicsBody_push2 = PhysicsBody::createBox(push2->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_push2->setDynamic(false);
    physicsBody_push2->setCollisionBitmask(7);
    physicsBody_push2->setContactTestBitmask(1);
    push2->setPhysicsBody(physicsBody_push2);

    
    //// //////////////////
 

    /////////door/////////////
    auto* door = Sprite::create("door.png");
    door->setAnchorPoint(Vec2(0, 0));
    door->setPosition(Vec2(1860, 250));
    door->setScale(0.25);
    this->addChild(door, 3);

    //creating physique for THE door

    auto physicsBody_door = PhysicsBody::createBox(door->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));

    physicsBody_door->setDynamic(false);
    physicsBody_door->setCollisionBitmask(9);
    physicsBody_door->setCategoryBitmask(1);
    physicsBody_door->setContactTestBitmask(1);
    door->setPhysicsBody(physicsBody_door);
    ///////////
    // 
    auto* floor2 = Sprite::create("ground-13.png");
    floor2->setAnchorPoint(Vec2(0, 0));
    floor2->setPosition(Vec2(1600, 80));
    floor2->setScale(0.2);
    this->addChild(floor2, 1);

    //creating physique for THE FLOOR

    auto physicsBody_floor2 = PhysicsBody::createBox(floor2->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));

    physicsBody_floor2->setDynamic(false);
    physicsBody_floor2->setCollisionBitmask(1);
    physicsBody_floor2->setCategoryBitmask(1);
    floor2->setPhysicsBody(physicsBody_floor2);
    //////////
    auto* floor1 = Sprite::create("ground-13.png");
    floor1->setAnchorPoint(Vec2(0, 0));
    floor1->setPosition(Vec2(1450, 170));
    floor1->setScale(0.2);
    this->addChild(floor1, 1);

    //creating physique for THE FLOOR

    auto physicsBody_floor1 = PhysicsBody::createBox(floor1->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));

    physicsBody_floor1->setDynamic(false);
    physicsBody_floor1->setCollisionBitmask(1);
    physicsBody_floor1->setCategoryBitmask(1);
    floor2->setPhysicsBody(physicsBody_floor1);
    /////////////////////////
    auto* floorj = Sprite::create("ground-13.png");
    floorj->setAnchorPoint(Vec2(0, 0));
    floorj->setPosition(Vec2(1844, 230));
    floorj->setScale(0.3);
    this->addChild(floorj, 1);

    //creating physique for THE FLOOR

    auto physicsBody_floorj = PhysicsBody::createBox(floor1->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));

    physicsBody_floorj->setDynamic(false);
    physicsBody_floorj->setCollisionBitmask(1);
    physicsBody_floorj->setCategoryBitmask(1);
    floor2->setPhysicsBody(physicsBody_floorj);

    /////////////////////////////////////////////////////////////////////////
    auto* dontpush21 = Sprite::create("button.png");
    dontpush21->setAnchorPoint(Vec2(0, 0));
    dontpush21->setPosition(Vec2(1520, 40));
    dontpush21->setScale(0.30);
    this->addChild(dontpush21, 1);

    auto physicsBody_dontpush21 = PhysicsBody::createBox(dontpush21->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_dontpush21->setDynamic(false);
    physicsBody_dontpush21->setCollisionBitmask(1);
    physicsBody_dontpush21->setContactTestBitmask(1);
    dontpush2->setPhysicsBody(physicsBody_dontpush2);
    //////
    // 
    auto* dontpushs12 = Sprite::create("dont_push.png");
    dontpushs12->setAnchorPoint(Vec2(0, 0));
    dontpushs12->setPosition(Vec2(1520, 60));
    dontpushs12->setScale(0.128);
    this->addChild(dontpushs12, 1);

    auto physicsBody_dontpushs12 = PhysicsBody::createBox(dontpushs12->getContentSize(), PhysicsMaterial(0.1f, 0.5f, 0.5f));
    physicsBody_dontpushs12->setDynamic(false);
    physicsBody_dontpushs12->setCollisionBitmask(0);
    physicsBody_dontpushs12->setContactTestBitmask(0);
    dontpushs12->setPhysicsBody(physicsBody_dontpushs12);

    //////////////////////////////////////////////////////////////////////

    auto* pit_1 = Sprite::create("ground-03.png");
    pit_1->setAnchorPoint(Vec2(0, 0));
    pit_1->setPosition(Vec2(0, -80));
    pit_1->setScale(0.125);
    this->addChild(pit_1, 1);

    auto physicsBody_pit_1 = PhysicsBody::createBox(pit_1->getContentSize(), PhysicsMaterial(1.0f, 1.0f, 1.0f));
    physicsBody_pit_1->setContactTestBitmask(1);
    physicsBody_pit_1->setCollisionBitmask(1);
    physicsBody_pit_1->setDynamic(false);
    pit_1->setPhysicsBody(physicsBody_pit_1);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    auto* acc1 = MoveBy::create(0.056 * winSize3.width, Point(-winSize3.width * 3, 0));

    dontpush2->runAction(acc1);
    floorA->runAction(acc1->clone());
    dontpush3->runAction(acc1->clone());
    box1->runAction(acc1->clone());
    box2->runAction(acc1->clone());
    box3->runAction(acc1->clone());
    box4->runAction(acc1->clone());
    box5->runAction(acc1->clone());
    box6->runAction(acc1->clone());
    box7->runAction(acc1->clone());
    box8->runAction(acc1->clone());
    box9->runAction(acc1->clone());
    box10->runAction(acc1->clone());
    box11->runAction(acc1->clone());
    floorb->runAction(acc1->clone());
    floor9->runAction(acc1->clone());
    floor10->runAction(acc1->clone());
    floor11->runAction(acc1->clone());
    wall7->runAction(acc1->clone());
    floor8->runAction(acc1->clone());
    floor6->runAction(acc1->clone());
    push->runAction(acc1->clone());
    floor3->runAction(acc1->clone());
    boxa->runAction(acc1->clone());
    door->runAction(acc1->clone());
    floor2->runAction(acc1->clone());
    floor1->runAction(acc1->clone());
    floorj->runAction(acc1->clone());
    push2->runAction(acc1->clone());
    boxi->runAction(acc1->clone());
    dontpushs->runAction(acc1->clone());
    dontpushs1->runAction(acc1->clone());
    dontpushs12->runAction(acc1->clone());
    dontpush21->runAction(acc1->clone());

//    box5->setOpacity(0);
  //  box6->setOpacity(0);
    
    /// //////////////////////////////////////////////////////////////////////////////////////////////
   
    /// 
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(SCENE1::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(SCENE1::onKeyPressed, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    keyboardListener->onKeyPressed = [player3](EventKeyboard::KeyCode KeyCode, Event* event)
    {

        if (KeyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
            auto action1 = JumpBy::create(0.5f, Vec2(70, 100), 15.0f, 1);
            auto easeAction = EaseOut::create(action1, 2.0f);
            player3->runAction(action1);
            cocos2d::AudioEngine::preload("jump.mp3"); //upload de notre music mp3 en v4 de cocos
            cocos2d::AudioEngine::play2d("jump.mp3");

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 20.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(100, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player3->runAction(repeatAction);

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 20.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(-100, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player3->runAction(repeatAction);

        }
       

    };
    keyboardListener->onKeyReleased = [player3](EventKeyboard::KeyCode KeyCode, Event* event)
    {
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            player3->stopAllActions();
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            player3->stopAllActions();
        }

    };
    //////////////////////////////////////////////////////////////////////////
  
    /////////////////////////////////////contact collision/////

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [player3,floor8,push](PhysicsContact& contact) {


        PhysicsBody* x = contact.getShapeA()->getBody();
        PhysicsBody* y = contact.getShapeB()->getBody();

        if (1== x->getCollisionBitmask() && 5== y->getCollisionBitmask() || (5 == x->getCollisionBitmask() && 1 == y->getCollisionBitmask())) {
            if (x->getNode()->getScale() == 0.125 || x->getNode()->getScale() == 0.130)
            {
                MoveBy* moveact0 = MoveBy::create(4.0, Vec2(0, -150));
                x->getNode()->runAction(moveact0);
            }
            if (y->getNode()->getScale() == 0.125|| y->getNode()->getScale() == 0.130)
            {
                MoveBy* moveact0 = MoveBy::create(4.0, Vec2(0, -150));
                y->getNode()->runAction(moveact0);
            }
            
  
          
            if (1 == x->getCollisionBitmask() && (1 == y->getCollisionBitmask())) {
               
                auto scene = Gameover::createScene();
                Director::getInstance()->pushScene(TransitionFade::create(0.6, scene));

               
            }
           
            
        }
        if (1 == x->getCollisionBitmask() && (1 == y->getCollisionBitmask())) {

          auto scene = Gameover::createScene();
            Director::getInstance()->pushScene(TransitionFade::create(0.6, scene));

            cocos2d::AudioEngine::preload("gameover.mp3");
            cocos2d::AudioEngine::play2d("gameover.mp3");
        }

        if (4 == x->getCollisionBitmask() || 4 == y->getCollisionBitmask()) {
            auto scaleAction = ScaleTo::create(2.0, 0.125);
            auto easeOutAction = EaseOut::create(scaleAction, 2.0);
            player3->runAction(easeOutAction);
          
        }

        if (3 == x->getCollisionBitmask() || 3 == y->getCollisionBitmask()) {
            if (floor8->getPositionY() == 47)
            {
                MoveBy* moveact = MoveBy::create(1.2, Vec2(0, 150));
                floor8->runAction(moveact);
            }
            if (floor8->getPositionY() == 197)
            {
                MoveBy* moveact2 = MoveBy::create(1.2, Vec2(0, -150));
                floor8->runAction(moveact2);
            }
        }
        if (7== x->getCollisionBitmask() || 7 == y->getCollisionBitmask()) {
            auto scaleAction = ScaleTo::create(2.0, 0.3);
            auto easeOutAction = EaseOut::create(scaleAction, 2.0);
            player3->runAction(easeOutAction);

        }

        if (9 == x->getCollisionBitmask() || (9 == y->getCollisionBitmask())) {

            auto scene = win::createScene();
        Director::getInstance()->pushScene(TransitionFade::create(0.6, scene));

        }
           
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    return true;
}


    


















    

















