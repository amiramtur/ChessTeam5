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

char Empty::get_type()
{
	return '#';
}

std::vector<Piece*> Empty::move(std::vector<Piece*> board, Point& dstp)
{
	throw 2;

	return board;
}
