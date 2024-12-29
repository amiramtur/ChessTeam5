#pragma once

#include "Point.h"


class Empty : public Piece {
private: 
	Point* _sp; 
public: 
	Empty(Point* sp);
	~Empty();
	virtual void move(Piece* board, Point& dp); 
};