#pragma once

#include <string>
#include "Point.h"

#define ROW 8
class Piece
{
public: 
	Piece(); 
	static bool first_check(const std::string& board, const Point& sp, const Point& dp, const int color); //treat at 3 and 7 codes 
	virtual void move(Piece* board, Point& dp) = 0;
};
