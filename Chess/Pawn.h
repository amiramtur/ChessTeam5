#pragma once
#include "King.h"

class Pawn : public King
{
public:
	Pawn(int color);
	std::string move(std::string board, Point sp, Point dp) override; // sp = source point, dp = distanation point
};

