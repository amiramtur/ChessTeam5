#pragma once
#include "King.h"
#include "Piece.h"
#include "Point.h"

class Pawn : public Piece
{
private:
	int _color; //0 = white, 1 = black
	Point* _srcp; //source point
public:
	Pawn(const int color, Point* sp);
	~Pawn();

	virtual char get_type() override;
	virtual void move(const std::vector<Piece*>& board, const Point& dstp) override; // sp = source point, dp = distanation point
};

