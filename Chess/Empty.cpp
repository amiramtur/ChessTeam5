#include "Empty.h"
#include <iostream>

Empty::Empty(Point* sp) : Piece()
{
	this->_sp = sp; 
}

Empty::~Empty()
{
	delete(this->_sp); 
}

void Empty::move(Piece* board, Point& dp)
{
	throw 2; 
}
