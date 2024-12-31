#pragma once
#include "Piece.h"

class Knight : public Piece
{
private: 
	int _color; 
	Point* _srcp; 
public:
	Knight(int color, Point* srcp);
	virtual Point* getPoint() const; 
	virtual char get_type() override;
	virtual void move(std::vector<Piece*>& board, Point& dstp) override; //sp = source point, dp = distanation point
};

