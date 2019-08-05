#include "GameScene.h"
//#include "SimpleAudioEngine.h"
#include "GridController.h"

USING_NS_CC;

GameScene::GameScene()
	: m_pGridController( new GridController(this) )
{
}

GameScene::~GameScene()
{
	delete m_pGridController;
	m_pGridController = nullptr;
}

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

	// init configs to SpriteFrameCache
	SpriteFrameCache* pSpriteCache = SpriteFrameCache::getInstance();
	pSpriteCache->addSpriteFramesWithFile("gems.plist");

	m_pGridController->generateTiles();
	/*
	SpriteFrame* pSpriteBackgroundTile = pSpriteCache->getSpriteFrameByName("tile_background.png");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

	float gapSize = 10;
	float scale = 0.2; // scale < 1, because original art is too big

	for (int i = -2; i <= 2; ++i)
		for(int j = -2; j <= 2; ++j)
		{
			Sprite* pSprite = Sprite::createWithSpriteFrame(pSpriteBackgroundTile);

			pSprite->setScale(scale); 

			pSprite->setPosition( Vec2(center.x + i * (gapSize + scale * pSprite->getContentSize().width), 
									center.y + j * (gapSize + scale * pSprite->getContentSize().height)) );
			
			this->addChild(pSprite, 0);
		}
	*/
	
	return true;
}