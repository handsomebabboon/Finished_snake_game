#include "Board.h"

Board::Board(Graphics& gfx)
	:
	brd_gfx(gfx)
	
{
}

void Board::DrawCell(Location& loc, Color c)
{
	brd_gfx.DrawRectDim(loc.x * dimension , loc.y * dimension , dimension , dimension , c);
}

bool Board::isInside(Location& loc)
{
	return loc.x < width && loc.x> 0 && loc.y > 0 && loc.y < height;
}

int Board::GetGridWidth()
{
	return width;
}

int Board::GetGridHeight()
{
	return height;
}
