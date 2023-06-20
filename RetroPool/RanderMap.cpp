#include "RanderMap.h"
RanderMap::RanderMap() 
{
	texture.loadFromFile("assets/set.png");
	rect.width = 16;
	rect.height = 16;
	rect.top = 48;
	rect.left = 48;
	Map.resize(80);
	for (int y = 0; y < 80; y++) 
	{
		Map[y].resize(80);
		for (int x = 0; x < 80; x++)
		{
			Map[y][x].setTextureRect(rect);
			Map[y][x].setTexture(&texture);
			Map[y][x].setSize(sf::Vector2f(GRID_CELL_SIZE, GRID_CELL_SIZE));
			Map[y][x].setPosition(GRID_CELL_SIZE * x, GRID_CELL_SIZE * y);
		}
	}
}

void RanderMap::DrawMap(sf::RenderWindow& window)
{
	
	for (int y = 0; y < 80; y++)
	{
		;
		for (int x = 0; x < 80; x++)
		{
			window.draw(Map[y][x]);
		}
	}

}

void RanderMap::LoadMap()
{
	filemap.open("GameSaveFile.txt", std::fstream::in);

	if (filemap.fail()) {
		std::cout << " not loaded";
	}
	int xp, yp;
	xp = yp = 0;
	for (int y = 0; y < 80; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			filemap >> xp;
			filemap >> yp;
			rect.top = xp;
			rect.left = yp;
			Map[x][y].setTextureRect(rect);
		}
	}
	filemap.close();
}