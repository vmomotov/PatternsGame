#pragma once

#include <vector>
#include "cocos2d.h"

class GameTile : public cocos2d::Node
{
public:
	GameTile(int nValue);
private:
	cocos2d::Sprite* m_pCoverSprite;
	cocos2d::Sprite* m_pMainSprite;
};

class GridController
{
public:
	GridController();
	~GridController();

	void generateArray();
	void generateTiles();
	std::vector<std::vector<GameTile*> >& getTiles() { return m_gridTiles; }

private:
	std::vector<std::vector<int> > m_gridValuesArray;

	std::vector<std::vector<GameTile*> > m_gridTiles;
};