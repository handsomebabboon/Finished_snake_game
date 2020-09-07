#pragma once
#include "Location.h"
#include "Graphics.h"
class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(Location& loc , Color c);
	bool isInside(Location& loc);
	int GetGridWidth();
	int GetGridHeight();

private:
	Graphics& brd_gfx;
	static constexpr int dimension = 15;
	static constexpr int width = 50;
	static constexpr int height = 40;
	
};

