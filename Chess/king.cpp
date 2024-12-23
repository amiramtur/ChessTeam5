#include "king.h"
#include <iostream>
#include <cstdlib> //for "abs()"

King::King(int color) 
{
	this->_color = color; 
}

std::string King::move(std::string board, Point sp, Point dp)
{
	char sPiece = Point::get_piece(sp, board);
	char dPiece = Point::get_piece(dp, board);
	int dx = dp.get_x() - sp.get_x(), dy = dp.get_y() - sp.get_y(); //d = distance 
	

	if (sPiece != 'K' && sPiece != 'k' || !(Point::is_my_color(sPiece, this->_color))) //if the source is not ok 
	{
		throw 2; //code 2  
	}
	else if (Point::is_my_color(dPiece, this->_color)) //if there is piece with my color in dp 
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
	else if (dPiece == 'k' || dPiece == 'K')
	{
		throw 8; //code 8
	}
	
	return Point::replace(sp, dp, board); 
}

