#pragma once

#include <string>
#include "king.h"

class Bishop : virtual public Piece
{
public: 
	Bishop(int color);
	virtual std::string move(std::string& board, Point& dp) override; //sp = source point, dp = distanation point
};