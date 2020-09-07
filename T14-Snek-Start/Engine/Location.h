#pragma once
class Location {
public:
	void Add(Location& val) {
		x += val.x;
		y += val.y;
	}
	bool operator==(Location& rhs) {
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};