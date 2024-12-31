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

Point* Empty::getPoint() const
{
	return this->_srcp; 
}

int Empty::get_color() const
{
	return -1; 
}

char Empty::get_type()
{
	return '#';
}

void Empty::move(std::vector<Piece*>& board, Point& dstp)
{
	throw 2;
}
