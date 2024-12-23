#include "Pawn.h"
#include "Point.h"
#include <cstdlib> // for "abs()"

Pawn::Pawn(int color) : King(color)
{
	this->_color = color;
	this->_start = true;
}

std::string Pawn::move(std::string board, Point sp, Point dp)
{
	char sPiece = Point::get_piece(sp, board), dPiece = Point::get_piece(dp, board);
	int dx = dp.get_x() - sp.get_x(), dy = dp.get_y() - sp.get_y(); // d = distance 
	bool start = sp.get_y() == 2; 

	if (sPiece != 'P' && sPiece != 'p' || !(Point::is_my_color(sPiece, this->_color))) // if the source is not ok 
	{
		throw 2; //code 2  
	}
	else if (Point::is_my_color(dPiece, this->_color)) // if there is piece with my color in dp 
	{
		throw 3; //code 3  
	}
	else if (dx == 0 && dy == 0) // if it is the same points
	{
		throw 7; // code 7  
	}
	else if ((start == true && std::abs(dy) > 2) || (start == false && std::abs(dy) > 1) ||
			 (std::abs(dx) > 1 && dPiece == '#') || dy < 1)  // invalid moves - pawn
	{
		throw 6; // code 6  
	}
	else if (dPiece == 'k' || dPiece == 'K')
	{
		throw 8; // code 8, needs fixing
	}


	return Point::replace(sp, dp, board);
}
