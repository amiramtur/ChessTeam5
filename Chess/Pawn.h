#pragma once
#include "King.h"
#include "Piece.h"
#include "Point.h"

class Pawn : public Piece
{
private:
	int _color; //0 = white, 1 = black
	Point _sp; //source point
public:
	Pawn(int color, Point sp);
	std::string move(std::string board, Point dp) override; // sp = source point, dp = distanation point
};

