#include "Player.h"
Player::Player()
{
	player.setSize(sf::Vector2f(32, 32));
	player.setTexture(&Tex);
	player.setPosition(0, 0);
	X = 0;
	Y = 0;
}

bool Player::setTexture(std::string textureLoc)
{
	if (Tex.loadFromFile(textureLoc)) 
	{
		return false;
	}
	return true;
}

void Player::drawplayer(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::SetRect(float left = 0, float top = 0,float width = 0, float height =0)
{
	
	Rect.left = left;
	Rect.top = top;
	Rect.width = width;
	Rect.height = height;
	player.setTextureRect(Rect);
}

void Player::SpriteMovemnet(int Spritelentgh, int &Currentsprite,int Row, int left = 64)
{
	if (Currentsprite > Spritelentgh) {
		Currentsprite = 0;
    }
	Rect.left = left * Currentsprite;
	Rect.top = Row;
	player.setTextureRect(Rect);
	if (time.getElapsedTime() >= sf::milliseconds(100))
	{
		time.restart();
		Currentsprite++;
	}
}

void Player::Movement(float x, float y)
{
	if (x != 0) {
		X += x;
	}
	if (y != 0) {
		Y += y;
	}
	player.setPosition(std::round(X), std::round(Y));
}

sf::Vector2f Player::PlayerCords()
{
	return player.getPosition();
}

void Player::SetPos(float xX, float yY)
{
	X = xX;
	Y = yY;
	player.setPosition(X, Y);
}

sf::Vector2f Player::GetPos()
{
	return player.getPosition();
}
