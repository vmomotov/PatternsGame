#include "GridController.h"
#include "GameScene.h"
#include "GameTile.h"

USING_NS_CC;

// 5x5 dimensions
const int g_nMaxGridSize = 5;

GridController::GridController()
	: m_gridTiles(g_nMaxGridSize, std::vector<GameTile*>(g_nMaxGridSize, nullptr))
	, m_pParentScene(nullptr)
{
}

GridController::GridController(GameScene* pParentScene)
	: m_pParentScene(pParentScene)
	, m_gridTiles(g_nMaxGridSize, std::vector<GameTile*>(g_nMaxGridSize, nullptr))
{
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
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

	float gapSize = 10;
	float scale = 0.2; // scale < 1, because original art is too big

	int halfGridSize = g_nMaxGridSize / 2;

	for (int i = - halfGridSize; i <= halfGridSize; ++i)
		for (int j = -halfGridSize; j <= halfGridSize; ++j)
		{
			GameTile* pTile = (cocos2d::ui::Button::create("tile_background.png", "gem_1.png", "tile_black.png", cocos2d::ui::Widget::TextureResType::PLIST));
			pTile->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
				if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
					cocos2d::ui::Button* pButton = dynamic_cast<cocos2d::ui::Button*>(sender);
					if (pButton != nullptr) {
						pButton->setBright(false);
					}
				}
			});

			pTile->setScale(scale);

			pTile->setPosition(Vec2(center.x + i * (gapSize + scale * pTile->getContentSize().width),
				center.y + j * (gapSize + scale * pTile->getContentSize().height)));

			if (m_pParentScene != nullptr) {
				m_pParentScene->addChild(pTile, 0);
			}
		}
}