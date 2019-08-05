#pragma once

#include "cocos2d.h"

//forward declarations
class GridController;

class GameScene : public cocos2d::Scene
{
public:
	GameScene();
	virtual ~GameScene();
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	void layoutTiles();

private:
	GridController* m_pGridController;
};
