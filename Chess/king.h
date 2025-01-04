#pragma once
#include <string>
#include "Point.h"
#include "Piece.h"

class King : public Piece 
{
public:
	King(int color, Point* srcp); 

	virtual Point* getPoint() const override; 
	virtual int get_color() const override;
	virtual char get_type() override;
	virtual bool move(const std::vector<Piece*>& board, const Point& dstp) const override; // dstp = distanation point
};