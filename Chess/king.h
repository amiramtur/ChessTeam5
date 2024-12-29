#pragma once
#include <string>
#include "Point.h"
#include "Piece.h"

class King : public Piece 
{
protected: 
	int _color; // 0 - white 1 - black 
public:
	King(int color); 
	virtual char get_type() override;
	virtual Piece* move(Piece* board, Point& srcp, Point& dstp) override; // dstp = distanation point
};