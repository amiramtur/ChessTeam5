#pragma once
#include "King.h"
#include "Piece.h"
#include "Point.h"

class Pawn : public Piece
{
public:
	Pawn(const int color, Point* sp);

	
	virtual char get_type() override;
	virtual int get_color() const override;
	virtual Point* getPoint() const override; 
	virtual bool move( const std::vector<Piece*>& board, const Point& dstp) const override; // sp = source point, dp = distanation point
};

