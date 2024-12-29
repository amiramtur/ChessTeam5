#pragma once
#include <string>
#include "Point.h"
#include "Piece.h"

class King : public Piece 
{
protected: 
	int _color; // 0 - white 1 - black 
public:
	King(int color); 
	virtual std::string move(std::string& board, Point& dp) override; //sp = source point, dp = distanation point
};