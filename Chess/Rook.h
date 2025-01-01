#pragma once

#include <string>
#include "King.h"

class Rook : virtual public Piece{
private:
	int _color; //0 = white, 1 = black
	Point* _srcp; //source point
public:
	Rook(int color, Point* srcp);
	virtual Point* getPoint() const override;
	virtual char get_type() override;
	virtual int get_color() const override;
	virtual bool move(const std::vector<Piece*>& board, const Point& dstp) const override; //sp = source point, dp = distanation point

};