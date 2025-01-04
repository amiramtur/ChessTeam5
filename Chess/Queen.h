#pragma once

#include "Rook.h"
#include "Bishop.h"


class Queen : public Piece
{
private: 
	Rook* _myRook; 
	Bishop* _myBishop; 
public:
	Queen(const int color, Point* srcp);
	~Queen() override; 
	virtual int get_color() const override; 
	virtual char get_type() override;
	virtual Point* getPoint() const; 
	virtual bool move(const std::vector<Piece*>& board,const Point& dstp) const override; //sp = source point, dp = distanation point

};
