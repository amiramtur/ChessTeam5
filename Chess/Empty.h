#pragma once

#include "Point.h"


class Empty : public Piece {
private: 
	Point* _srcp; 
public: 
	Empty(Point* srcp);
	~Empty();
	virtual void move(Piece* board, Point& dstp); 
};