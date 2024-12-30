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

std::vector<Piece*> King::move(std::vector<Piece*> board, Point& dstp)
{
	Piece* sPiece = Point::get_piece(*this->_srcp, board);
	Piece* dPiece = Point::get_piece(dstp, board);
	int dx = dstp.get_x() - this->_srcp->get_x(), dy = dstp.get_y() - this->_srcp->get_y(); //d = distance 
	bool isOk = true; 
	if (Piece::first_check(board, *this->_srcp, dstp, this->_color))
	{
		isOk = false; 
	}
	else if (std::abs(dx) > 1 || std::abs(dy) > 1) //if it not matches the king's movements
	{
		isOk = false; 
		throw 6; //code 6  
	}
	else if (dPiece->get_type() == 'K')
	{
		isOk = false; 
		throw 8; //code 8
	}

	if (isOk)
	{
		return Point::replace(*this->_srcp, dstp, board);
	}
	return board; 
}

