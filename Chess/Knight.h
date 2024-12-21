#pragma once
#include "King.h"

class Knight : public King
{
public:
	Knight(int color);
	std::string move(std::string board, Point sp, Point dp) override; //sp = source point, dp = distanation point
};

