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
	sprite = Sprite::create("neko.png");
	this->addChild(sprite);
	
	sprite2 = Sprite::create("one.png");
	this->addChild(sprite2);

	sprite->setPosition(640.0f, 360.0f);
	sprite2->setPosition(10.0f, 100.0f);


	/*sprite->setPosition(Vec2(1280.0f, 720.0f));
	

	sprite->setRotation(45.0f);

	sprite->setScale(3.0f, 4.0f);

	sprite->setFlippedX(true);

	sprite->setFlippedY(true);*/

	//sprite->setVisible(false);

	//�F������ݒ�
	//sprite->setColor(Color3B(0x80, 0x80, 0x80));
	//sprite->setColor(Color3B(255,0,0));

	//�s�����x��ݒ�
	sprite->setOpacity(255);
	sprite2->setOpacity(255);

	//�A���`�G�C���A�X�̉����@�H
	sprite->getTexture()->setAliasTexParameters();

	//�J�E���^�[�̏�����
	//counter = 0;
	counter = 10;
	counter2 = 0;

	//������
	state = 0;

	//
	flag = false;

	//update���Ăяo�����悤�ɂ���
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
	//�����ɍX�V����������

	//�X�v���C�g�̌��ݍ��W���擾
	Vec2 pos = sprite->getPosition();

	////�摜�̒��S�ʒu�̕ύX�@��_���w��
	//sprite->setAnchorPoint(Vec2(0.0f, 1.0f));

	////��]
	//float rot = sprite->getRotation();
	//sprite->setRotation3D();
	//rot += 1.0f;
	//sprite->setRotation(rot);
	
	
		
	float screenXMax = 1280.0f;//visibleSize.width	
	float screenYMax = 720.0f;
	float screenMin = 0.0f;
	float speed = 16.0f;

	//if (pos.x >= screenXMax && pos.y <= screenYMax) { pos += Vec2(0.0f, speed); }//��
	//else if (pos.x <= screenMin && pos.y >= screenMin) { pos += Vec2(0.0f, -speed); }//��
	//else if (pos.x > screenMin && pos.y >= screenYMax) { pos += Vec2(-speed ,0.0f); }//��
	//else if (pos.x <= screenXMax && pos.y <= screenMin) { pos += Vec2(speed, 0.0f); }//�E

	//��ʈړ�
	//switch (state)
	//{
	//	case 0: pos += Vec2(-speed, 0.0f); if (pos.x <= 0.0f) { state = 1; } break;//��
	//	case 1: pos += Vec2(0.0f, -speed); if (pos.y <= 0.0f) { state = 2; } break;//��
	//	case 2: pos += Vec2( speed, 0.0f); if (pos.x >= 1280.0f) { state = 3; } break;//�E
	//	case 3: pos += Vec2( 0.0f, speed); if (pos.y >= 720.0f) { state = 0; } break;//��
	//}

	//�ړ���̍��W�𔽉f
	sprite->setPosition(pos);

	////������
	//counter++;
	//float opacity = 255 - counter / 300.0f * 255.0f;
	//if (opacity < 0.0f) { opacity = 0.0f; }
	//sprite->setOpacity(opacity);
	//if (counter == 300) { counter = 0; }	

	//�F����
	//sprite->setColor(Color3B(0, 0, 255));


	counter++;
	if (counter == 13 ) {
		counter = 0;

		if (flag)
		{
			state--;
		}
		else {
			state++;
		}

		if (state == 0 || state == 2) { if (flag) { flag = false; } else { flag = true; } }
	}

	//�摜�̐؂���		�J�n�_XY�@�͈�WH
	sprite->setTextureRect(Rect( 32 * state , 64, 32, 32 ));
	sprite->setScale(10);

	
	counter2++;
	sprite2->setScaleX(counter2);
	sprite2->setScaleY(counter2 / 10);
	sprite2->setOpacity(counter2 % 127 + 128);
	
	
	//�����@�摜�����ύX
	/*if (pos.x <= 0 || pos.x > 1000) { 
		counter = -counter; 
		if (flag) { flag = false; }
		else { flag = true; }
	}
	pos.x += counter;

	sprite->setPosition(pos);
	sprite->setFlippedX(flag);*/


	//�N���X�t�F�[�h
	/*sprite2->setTextureRect(Rect(0, 0, 32, 32));
	sprite2->setScale(10);
	if(counter < 255)counter++;
	sprite->setOpacity(255 - counter);
	sprite2->setOpacity(counter);*/

	/*Color3B color = sprite->getColor();
	counter++;
	if (color.r > 0) { color.r = 255 - counter / 180.0f * 255.0f; }
	if (color.b < 255) { color.b = counter / 180.0f * 255.0f; }
	sprite->setColor(color);*/

	//���E���]
	//sprite->setFlippedX(true);
}
