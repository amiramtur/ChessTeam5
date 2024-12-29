#pragma once

#include "Rook.h"
#include "Bishop.h"


class Queen : public Rook, Bishop
{
	Queen(int color);
	virtual std::string move(std::string board, Point sp, Point dp) override; //sp = source point, dp = distanation point
};
