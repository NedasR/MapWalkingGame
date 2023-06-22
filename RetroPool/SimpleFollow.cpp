#include "SimpleFollow.h"
#include <iostream>

SimpleFollow::SimpleFollow()
{
	WhichRow = 0;
}



void SimpleFollow::FollowMaster(Player& Master, Player& Follower,float playerspeed)
{

	if (getDistance(Master, Follower) >= 31)
	{
		sf::Vector2f follow = Follower.GetPos();
		sf::Vector2f master = Master.GetPos();
		//the follow.x-1 is meant to give some wiggle room for the float decimals
		
		if ((follow.y+1 >= master.y && follow.y-1 <= master.y))
		{
			playerLR = false;
		}

		if (follow.x-1 > master.x && (!playerLR)) {
			follow.x -= playerspeed / Folower_DividedSpeed;
			WhichRow = 96;
		}
		else if (follow.x+1 < master.x && (!playerLR)) {
			follow.x += playerspeed / Folower_DividedSpeed;
			WhichRow = 32;
		}
		else if (follow.y-1 > master.y) {
			follow.y -= playerspeed / Folower_DividedSpeed;
			WhichRow = 0;
		}
		else if (follow.y+1 < master.y) {
			follow.y += playerspeed / Folower_DividedSpeed;
			WhichRow = 64;
		}

		Follower.SetPos(follow.x, follow.y);
		playerLR = false;
		
	}
}

float SimpleFollow::getDistance(Player& Master, Player& Follower)
{

	float dx = Master.GetPos().x - Follower.GetPos().x;
	float dy = Master.GetPos().y - Follower.GetPos().y;
	return std::sqrt(dx * dx + dy * dy);
}

int SimpleFollow::SpriteDiraction()
{
	return WhichRow;
}