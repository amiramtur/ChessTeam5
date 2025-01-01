#pragma once

#include <vector>
class Point;

class Piece
{
public:
	Piece();
	virtual char get_type() = 0;
	virtual int get_color() const = 0;
	virtual Point* getPoint() const = 0;
	static bool first_check(const std::vector<Piece*>& board, const Point& sp, const Point& dp, const int color); // treat at 3 and 7 codes 
	virtual bool move(const std::vector<Piece*>& board, const Point& dstp) const = 0;
};