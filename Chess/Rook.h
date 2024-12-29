#pragma once

#include <string>
#include "King.h"

class Rook : virtual public King 
{
public:
	Rook(int color);
	virtual std::string move(std::string board, Point sp, Point dp) override; //sp = source point, dp = distanation point

};