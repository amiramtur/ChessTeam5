#pragma once

#include <string>
#include "king.h"

class Bishop :King
{
public: 
	Bishop(int color);
	virtual std::string move(std::string board, Point sp, Point dp) override; //sp = source point, dp = distanation point
};