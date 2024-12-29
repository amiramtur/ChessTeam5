#pragma once

#include <string>
#include "king.h"

class Bishop : virtual public Piece
{
public: 
	Bishop(int color);
	virtual std::string move(Point& board, Point& dp) override; //sp = source point, dp = distanation point
};