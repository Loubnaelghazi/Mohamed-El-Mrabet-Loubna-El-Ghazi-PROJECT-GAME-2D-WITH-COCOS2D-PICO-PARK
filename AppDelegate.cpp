#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        //glview = GLViewImpl::create("Pico Park");
        //glview->setFrameSize(480, 320);
        glview = GLViewImpl::createWithRect("SimpleGame", Rect(0, 0, 480, 320),2.0);
        director->setOpenGLView(glview);
    }

    auto scene = HelloWorld::createScene();
    director->runWithScene(scene);

    return true;
}
void AppDelegate::applicationDidEnterBackground()
{
}

void AppDelegate::applicationWillEnterForeground() {
}