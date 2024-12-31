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
	~Queen(); 
	virtual int get_color() const override; 
	virtual char get_type() override;
	virtual Point* getPoint() const; 
	virtual void move(std::vector<Piece*>& board, Point& dstp) override; //sp = source point, dp = distanation point

};
