#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class SimpleFollow
{
public:
	bool playerLR;
	
	SimpleFollow();

	void FollowMaster(Player& Master, Player &Follower,float playerspeed);

	float getDistance(Player& Master, Player& Follower);


};

