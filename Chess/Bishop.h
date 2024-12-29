#pragma once

#include <string>
#include "king.h"

class Bishop : virtual public Piece
{
private: 
	int _color; //0 = white, 1 = black
	Point* _sp; //source point
public: 
	Bishop(const int color, Point* sp);
	virtual std::string move(std::string& board, Point& dp) override; //sp = source point, dp = distanation point
};