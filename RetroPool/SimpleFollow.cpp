#include "SimpleFollow.h"
#include <iostream>

SimpleFollow::SimpleFollow()
{

}



void SimpleFollow::FollowMaster(Player& Master, Player& Follower,float playerspeed)
{

	if (getDistance(Master, Follower) >= 30)
	{
		sf::Vector2f follow = Follower.GetPos();
		sf::Vector2f master = Master.GetPos();
		//the follow.x-1 is meant to give some wiggle room for the float decimals
		if (follow.x-1 > master.x) {
			follow.x -= playerspeed/2;
		}
		else if (follow.x+1 < master.x) {
			follow.x += playerspeed/2;
		}
		else if (follow.y-1 > master.y) {
			follow.y -= playerspeed/2;
		}
		else if (follow.y+1 < master.y) {
			follow.y += playerspeed/2;
		}
		Follower.SetPos(follow.x, follow.y);
	}
}

float SimpleFollow::getDistance(Player& Master, Player& Follower)
{

	float dx = Master.GetPos().x - Follower.GetPos().x;
	float dy = Master.GetPos().y - Follower.GetPos().y;
	return std::sqrt(dx * dx + dy * dy);
}