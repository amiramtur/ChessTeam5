#pragma once

#include <string>
#include "Point.h"

#define ROW 8

class Piece
{
public:
	virtual char get_type() = 0;
	static bool first_check(const std::string& board, const Point& sp, const Point& dp, const int color); // treat at 3 and 7 codes 
	virtual Piece* move(Piece* board, Point& srcp, Point& dstp) = 0;
};
