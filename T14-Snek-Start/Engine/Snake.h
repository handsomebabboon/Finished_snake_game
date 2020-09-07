#pragma once
#include "Board.h"
class Snake
{
private:
	class Segment {
	private:
		Location loc;
		Color c;
	public:
		void Draw(Board& brd);
		void Follow(Segment& next);
		void Moveby(Location& delta_loc);
		void InitHead(Location& in_loc);
		void InitBody();
		Location GetLocation();
		
	};

private:
	int nSegments = 1;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	static constexpr Color HeadColor = Colors::Blue;
	static constexpr Color BodyColor = Colors::Green;

public:
	Snake(Location& loc);
	void MoveBy(Location& delta_loc);
	void Draw(Board& brd);
	void Grow();
	bool isInTileExceptEnd(Location& target);
	bool isInTile(Location& target);
	Location GetNextHead(Location& delta_loc);
};
