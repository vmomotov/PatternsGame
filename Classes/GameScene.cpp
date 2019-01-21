#include "GameScene.h"
//#include "SimpleAudioEngine.h"
#include "GridController.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}

void GameScene::layoutTiles()
{
	//Size
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Director::getInstance()->setClearColor(Color4F(255, 255, 255, 255)); // white background

	SpriteFrameCache* pSpriteCache = SpriteFrameCache::getInstance();
	pSpriteCache->addSpriteFramesWithFile("gems.plist");
	SpriteFrame* pSpriteBackgroundTile = pSpriteCache->getSpriteFrameByName("tile_background.png");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* pSprite = Sprite::createWithSpriteFrame(pSpriteBackgroundTile);
	pSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	pSprite->setScale(0.2);
	this->addChild(pSprite, 0);
	
	return true;
}