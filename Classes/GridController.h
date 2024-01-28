#pragma once

#include <vector>
#include "cocos2d.h"

class GameScene;

#include "ui/UIButton.h"
#define GameTile cocos2d::ui::Button


class GridController
{
public:
	GridController();
	GridController(GameScene* inputScene);
	~GridController();

	void generateArray();
	void generateTiles();
	std::vector<std::vector<GameTile*> >& getTiles() { return m_gridTiles; }

private:
	std::vector<std::vector<int> > m_gridValuesArray;

	std::vector<std::vector<GameTile*> > m_gridTiles;

	GameScene* m_pParentScene;
};