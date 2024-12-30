#include "king.h"
#include <iostream>
#include <cstdlib> //for "abs()"

#define WHITE 0

King::King(int color, Point* srcp) 
{
	this->_color = color; 
	this->_srcp = srcp; 
}

King::~King()
{
	delete this->_srcp; 
}

Point* King::getPoint() const
{
	return this->_srcp;
}

char King::get_type()
{
	if (this->_color == WHITE)
	{
		return 'K';
	}
	return 'k';
}

void King::move(const std::vector<Piece*>& board, const Point& dstp)
{
	Piece* sPiece = Point::get_piece_class(*this->_srcp, board);
	Piece* dPiece = Point::get_piece_class(dstp, board);
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

	if (isOk)
	{
		Point::replace(*Point::get_piece_class(*this->_srcp, board), *Point::get_piece_class(dstp, board), board);
	}
}

