#include "GridController.h"

GameTile::GameTile(int value)
{

}


// 5x5 dimensions
const int g_nMaxGridSize = 5;

GridController::GridController()
	: m_gridTiles(g_nMaxGridSize, std::vector<GameTile*>(g_nMaxGridSize, nullptr))
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
	m_gridValuesArray = { {1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0} };
}

void GridController::generateTiles()
{
	for (int i = 0; i < g_nMaxGridSize; ++i)
		for (int j = 0; j < g_nMaxGridSize; ++j)
		{
			m_gridTiles[i][j] = new GameTile(m_gridValuesArray[i][j]);
		}
}