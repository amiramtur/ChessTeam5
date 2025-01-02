#include "king.h"
#include <iostream>
#include <cstdlib> //for "abs()"

#define WHITE 0

King::King(int color, Point* srcp) : Piece(color, srcp)
{}


Point* King::getPoint() const
{
	return this->_srcp;
}

int King::get_color() const
{
	return this->_color; 
}

char King::get_type()
{
	if (this->_color == WHITE)
	{
		return 'K';
	}
	return 'k';
}

bool King::move(const std::vector<Piece*>& board, const Point& dstp) const
{
	int dx = dstp.get_x() - this->_srcp->get_x(), dy = dstp.get_y() - this->_srcp->get_y(); //d = distance 
	bool isOk = true;

	if (Piece::first_check(board, *this->_srcp, dstp, this->_color))
	{
		isOk = false; 
	}
	else if (std::abs(dx) > 1 || std::abs(dy) > 1) // king check
	{
		isOk = false; 
		throw 6; //code 6  
	}

	return isOk; 
}

