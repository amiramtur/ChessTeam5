#include "Empty.h"
#include <iostream>

Empty::Empty(Point* srcp) : Piece()
{
	this->_srcp = srcp;
}

Empty::~Empty()
{
	delete(this->_srcp);
}

void Empty::move(Piece* board, Point& dstp)
{
	throw 2; 
}