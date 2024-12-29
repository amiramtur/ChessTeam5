#pragma once

#include <string>
#include "king.h"

class Bishop : virtual public Piece
{
private: 
	int _color; //0 = white, 1 = black
	Point* _sp; //source point
public: 
	Bishop(int color);
	virtual std::string move(Point& board, Point& dp) override; //sp = source point, dp = distanation point
};