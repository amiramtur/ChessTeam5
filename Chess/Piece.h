#pragma once

#include <string>
#include "Point.h"
#include <vector>

#define ROW 8

class Piece
{
public:
	virtual char get_type() = 0;
	virtual Point* getPoint() const = 0;
	static bool first_check(const std::vector<Piece*>& board, const Point& sp, const Point& dp, const int color); // treat at 3 and 7 codes 
	virtual void move(std::vector<Piece*>& board, Point& dstp) = 0;
};
