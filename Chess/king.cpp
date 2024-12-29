#include "king.h"
#include <iostream>
#include <cstdlib> //for "abs()"

#define WHITE 0

King::King(int color) 
{
	this->_color = color; 
}

char King::get_type()
{
	if (this->_color == WHITE)
	{
		return 'K';
	}
	return 'k';
}

Piece* King::move(Piece* board, Point& srcp, Point& dstp)
{
	Piece* sPiece = Point::get_piece(srcp, board);
	Piece* dPiece = Point::get_piece(dstp, board);
	int dx = dstp.get_x() - srcp.get_x(), dy = dstp.get_y() - srcp.get_y(); //d = distance 
	
	if ((sPiece->get_type() != 'K' && sPiece->get_type() != 'k') || !(Point::is_my_color(sPiece->get_type(), this->_color))) // if the source is not ok 
	{
		throw 2; //code 2  
	}
	else if (Point::is_my_color(dPiece->get_type(), this->_color)) //if there is piece with my color in dp 
	{
		throw 3; //code 3  
	}
	else if (dx == 0 && dy == 0) //if it is the same points
	{
		throw 7; // code 7  
	}
	else if (std::abs(dx) > 1 || std::abs(dy) > 1) //if it not matches the king's movements
	{
		throw 6; //code 6  
	}
	else if (dPiece->get_type() == 'K')
	{
		throw 8; //code 8
	}
	
	return Point::replace(srcp, dstp, board); 
}

