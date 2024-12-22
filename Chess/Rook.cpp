#include "Rook.h"
#include <iostream>

Rook::Rook(int color) : King(color)
{
}

std::string Rook::move(std::string board, Point sp, Point dp)
{
	char sPiece = Point::get_piece(sp, board);
	char dPiece = Point::get_piece(dp, board);
	int dx = dp.get_x() - sp.get_x(), dy = dp.get_y() - sp.get_y(); //d = distance 

	Point temp = sp; 

	if (sPiece != 'R' && sPiece != 'r' || !(Point::is_my_color(sPiece, this->_color))) //if the source is not ok 
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
	else if (std::abs(dx) != 0 && std::abs(dy) != 0) //if it not matches the rook's movements
	{
		throw 6; //code 6  
	}
	else if (dPiece == 'k' || dPiece == 'K')
	{
		throw 8; //code 8
	}
	else
	{
		//checks if there is a piece in the rook's way
		if (dx > 0) //if the rook moves right 
		{
			while (temp != dp)
			{
				temp.set_x(temp.get_x() + 1); 
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else if (dx < 0) //if the rook moves left
		{
			while (temp != dp)
			{
				temp.set_x(temp.get_x() - 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else if (dy > 0) //if the rook moves forward
		{
			while (temp != dp)
			{
				temp.set_y(temp.get_y() + 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else //if the rook moves backwards
		{
			while (temp != dp)
			{
				temp.set_y(temp.get_y() - 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
	}

	return Point::replace(sp, dp, board);
}
