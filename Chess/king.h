#pragma once
#include <string>
#include "Point.h"

class King 
{
protected: 
	int _color; // 0 - white 1 - black 
public:
	King(int color); 
	virtual std::string move(std::string board, Point sp, Point dp); //sp = source point, dp = distanation point
};