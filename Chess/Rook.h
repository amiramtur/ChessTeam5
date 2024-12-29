#pragma once

#include <string>
#include "King.h"

class Rook : virtual public Piece{
public:
	Rook(int color);
	virtual std::string move(Point& board, Point& dp) override; //sp = source point, dp = distanation point

};