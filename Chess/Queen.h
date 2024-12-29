#pragma once

#include "Rook.h"
#include "Bishop.h"


class Queen : public Rook, Bishop
{
public:
	Queen(int color);
	virtual char get_type() override;
	virtual std::string move(Point& board, Point& dp) override; //sp = source point, dp = distanation point

private:
	int _color;
};
