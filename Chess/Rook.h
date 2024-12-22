#pragma once

#include <string>
#include "king.h"

class Rook : King
{
public:
	Rook(int color);
	virtual std::string move(std::string board, Point sp, Point dp) override; //sp = source point, dp = distanation point

};