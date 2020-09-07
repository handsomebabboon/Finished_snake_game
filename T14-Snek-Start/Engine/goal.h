#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>
class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd, Snake& snake);
	void Respawn(std::mt19937& rng,Board& brd,Snake& snake);
	void Draw(Board& brd);
	Location& GetLocation();
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};

