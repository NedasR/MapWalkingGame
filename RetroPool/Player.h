#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
sf::Texture Tex;
sf::RectangleShape player;
sf::IntRect Rect;
sf::Clock time;
sf::Time timer;
int spritenum;
float X, Y;
public:

Player(); 

bool setTexture(std::string textureLoc);
    
void drawplayer(sf::RenderWindow& window);

void SetRect(float left, float top, float width, float height);

void SpriteMovemnet(int Spritelentgh, int &CurrentSprite,int Row, int left);

void Movement(float x, float y);

void SetPos(float X, float Y);

sf::Vector2f PlayerCords();

sf::Vector2f GetPos();

void stillSpriteUpdate();
};
