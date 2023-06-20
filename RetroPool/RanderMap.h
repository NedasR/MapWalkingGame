#pragma once

#define GRID_CELL_SIZE 64

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
class RanderMap
{
	std::vector < std::vector<sf::RectangleShape>> Map;
	sf::IntRect rect;
	sf::Texture texture;
	std::fstream filemap;

public:
	
	RanderMap();

	void DrawMap(sf::RenderWindow &window);

	void LoadMap();


};