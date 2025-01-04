#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(int color, Point* srcp);

	virtual Point* getPoint() const; 
	virtual int get_color() const override;
	virtual char get_type() override;
	virtual bool move( const std::vector<Piece*>& board, const Point& dstp) const override; //sp = source point, dp = distanation point
};

