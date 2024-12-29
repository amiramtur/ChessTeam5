#pragma once

#include <string>
#include "king.h"

class Bishop : virtual public King
{
public: 
	Bishop(int color);
	virtual std::string move(std::string board, Point sp, Point dp) override; //sp = source point, dp = distanation point
};