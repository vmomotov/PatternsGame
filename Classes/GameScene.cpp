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
	
	return true;
}