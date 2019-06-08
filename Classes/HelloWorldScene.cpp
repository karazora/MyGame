/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}

	//Sprite* sprite = Sprite::create("four.png");
	sprite = Sprite::create("four.png");
	this->addChild(sprite);

	sprite->setPosition(Vec2(1280.0f, 720.0f));

	sprite->setRotation(45.0f);

	sprite->setScale(3.0f, 4.0f);

	sprite->setFlippedX(true);

	sprite->setFlippedY(true);

	//sprite->setVisible(false);

	//色あいを設定
	//sprite->setColor(Color3B(0x80, 0x80, 0x80));

	//不透明度を設定
	sprite->setOpacity(255);

	//カウンターの初期化
	counter = 0;

	//updateが呼び出されるようにする
	this->scheduleUpdate();

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	//ここに更新処理を書く

	//スプライトの現在座標を取得
	Vec2 pos = sprite->getPosition();

	//移動	
	/*if (pos.x >= 1000.f && pos.y <= 600.0f) { pos += Vec2(0.0f, 4.0f); }else
	if (pos.y <= 100.0f && pos.x < 1000.0f) { pos += Vec2(4.0f, 0.0f); }else
	if (pos.x <= 0.0f && pos.y > 100.0f) { pos += Vec2(0.0f, -4.0f); }else
	if (pos.y > 300.0f && pos.x > 0.0f) { pos += Vec2(-4.0f, 0.0f); }*/
		
	float screenXMax = 1280.0f;
	float screenYMax = 720.0f;
	float screenMin = 0.0f;
	float speed = 16.0f;

	if (pos.x >= screenXMax && pos.y <= screenYMax) { pos += Vec2(0.0f, speed); }//上
	else if (pos.x <= screenMin && pos.y >= screenMin) { pos += Vec2(0.0f, -speed); }//下
	else if (pos.x > screenMin && pos.y >= screenYMax) { pos += Vec2(-speed ,0.0f); }//左
	else if (pos.x <= screenXMax && pos.y <= screenMin) { pos += Vec2(speed, 0.0f); }//右


	//移動後の座標を反映
	sprite->setPosition(pos);

	//
	//Vec2 vec;// = Vec2(0.0f, 0.0f);

	//int posx = (int)pos.x;

	//if (posx >= 700) {
	//	vec = Vec2(-1.0f, 0.0f);
	//}

	//座標を移動させる
	//pos += Vec2(-1.0f, 0.0f);
	//pos += vec;

	//透明化
	//int opacity = sprite->getOpacity();
	//if (opacity > 0) { opacity--; }
	//sprite->setOpacity(opacity);

	counter++;
	float opacity = 255 - counter / 300.0f * 255.0f;
	if (opacity < 0.0f) { opacity = 0.0f; }
	sprite->setOpacity(opacity);
	if (counter == 300) { counter = 0; }

	/*if (pos.x <= 100)
	{
		vec = Vec2(1.0f, 0.0f);
	}*/
	

}
