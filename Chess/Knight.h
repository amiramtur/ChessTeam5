#pragma once
#include "King.h"

class Knight : public King
{
public:
	Knight(int color);
	virtual char get_type() override;
	virtual std::string move(Point& board, Point& dp) override; //sp = source point, dp = distanation point
};

