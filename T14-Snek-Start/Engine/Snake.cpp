#include "Snake.h"

Snake::Snake(Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].Moveby(delta_loc);
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(brd);
	}
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) {
		segments[nSegments].InitBody();
		++nSegments;
	}
}

bool Snake::isInTileExceptEnd(Location& target)
{
	for (int i = 0; i < nSegments-1; i++) {
		if (segments[i].GetLocation() == target) {
			return true;
			
		}
	}
	return false;
	
}

bool Snake::isInTile(Location& target)
{
	for (int i = 0; i < nSegments ; i++) {
		if (segments[i].GetLocation() == target) {
			return true;

		}
	}
	return false;

}

Location Snake::Segment::GetLocation()
{
	return loc;
}

Location Snake::GetNextHead(Location& delta_loc)
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

void Snake::Segment::Follow(Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Moveby(Location& delta_loc)
{
	loc.Add(delta_loc);
}

void Snake::Segment::InitHead(Location& in_loc)
{
	c = Snake::HeadColor;
	loc = in_loc;
}

void Snake::Segment::InitBody()
{
	c = Snake::BodyColor;
}

