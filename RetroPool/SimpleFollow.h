#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#define Folower_DividedSpeed 1.10
#define Flower_MIN_DISTENCE 30
class SimpleFollow
{
	int WhichRow;
public:
	bool playerLR;
	int Spritenum;
	
	SimpleFollow();

	void FollowMaster(Player& Master, Player &Follower,float playerspeed);

	float getDistance(Player& Master, Player& Follower);

	int SpriteDiraction();
	
};

