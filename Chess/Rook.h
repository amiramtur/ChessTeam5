#pragma once

#include <string>
#include "King.h"

class Rook : virtual public Piece{
private:
	int _color; //0 = white, 1 = black
	Point* _sp; //source point
public:
	Rook(int color);
	virtual std::string move(std::string& board, Point& dp) override; //sp = source point, dp = distanation point

};