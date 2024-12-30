#include "Piece.h"
#include <iostream>
#include "Point.h"

Piece::Piece() {}

bool Piece::first_check(const std::vector<Piece*>& board, const Point& sp, const Point& dp, const int color)
{
	char dPiece = Point::get_piece(dp, board);

	if (Point::is_my_color(dPiece, color)) //if there is piece with my color in dp 
	{
		throw 3; //code 3  
	}
	else if (sp.get_x() == dp.get_x() && sp.get_y() == dp.get_y()) //if it is the same points
	{
		throw 7; // code 7  
	}
	else if (dPiece == 'k' || dPiece == 'K')
	{
		throw 8; //code 8
	}
	else
	{
		return false; // valid (passed the test)
	}
	return true; 
}


