#pragma once
#include <string>
#include "Point.h"

class King 
{
protected: 
	int _color; 
public:
	King(int color); 
	std::string move(std::string board, Point sp, Point dp); //sp = source point, dp = distanation point
};