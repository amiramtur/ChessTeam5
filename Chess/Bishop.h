#pragma once

#include <string>
#include "king.h"

class Bishop : virtual public Piece
{
private: 
	int _color; //0 = white, 1 = black
	Point* _srcp; //source point
public:
	Bishop(const int color, Point* srcp);
	virtual Point* getPoint() const override; 
	virtual int get_color() const override;
	virtual char get_type() override;
	virtual bool move(const std::vector<Piece*>& board, const Point& dstp) const override; //sp = source point, dp = distanation point
};