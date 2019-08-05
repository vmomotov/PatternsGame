#include "GridController.h"
#include "GameScene.h"

GameTile::GameTile(int value)
{

}

USING_NS_CC;

// 5x5 dimensions
const int g_nMaxGridSize = 5;

GridController::GridController()
	: m_gridTiles(g_nMaxGridSize, std::vector<GameTile*>(g_nMaxGridSize, nullptr))
{
	int a = 0;
}

GridController::GridController(GameScene* pParentScene)
	: m_pParentScene(pParentScene)
	, m_gridTiles(g_nMaxGridSize, std::vector<GameTile*>(g_nMaxGridSize, nullptr))
{
	//GridController();
}

GridController::~GridController()
{
	for (int i = 0; i < g_nMaxGridSize; ++i)
		for (int j = 0; j < g_nMaxGridSize; ++j)
		{
			delete m_gridTiles[i][j];
			m_gridTiles[i][j] = nullptr;
		}
}

void GridController::generateArray()
{
	// test values
	m_gridValuesArray = { {1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0} };
}

void GridController::generateTiles()
{
	SpriteFrameCache* pSpriteCache = SpriteFrameCache::getInstance();
	SpriteFrame* pSpriteBackgroundTile = pSpriteCache->getSpriteFrameByName("tile_background.png");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

	float gapSize = 10;
	float scale = 0.2; // scale < 1, because original art is too big

	int halfGridSize = g_nMaxGridSize / 2;

	for (int i = - halfGridSize; i <= halfGridSize; ++i)
		for (int j = -halfGridSize; j <= halfGridSize; ++j)
		{
			Sprite* pSprite = Sprite::createWithSpriteFrame(pSpriteBackgroundTile);

			pSprite->setScale(scale);

			pSprite->setPosition(Vec2(center.x + i * (gapSize + scale * pSprite->getContentSize().width),
				center.y + j * (gapSize + scale * pSprite->getContentSize().height)));

			if (m_pParentScene != nullptr) { 
				m_pParentScene->addChild(pSprite, 0);
			}
				
		}

	/*
	for (int i = 0; i < g_nMaxGridSize; ++i)
		for (int j = 0; j < g_nMaxGridSize; ++j)
		{
			m_gridTiles[i][j] = new GameTile(m_gridValuesArray[i][j]);
		}
	*/
}