#include "Rook.h"
#include <iostream>

Rook::Rook(int color) : Piece()
{
}

std::string Rook::move(std::string& board, Point& dp)
{
	char dPiece = Point::get_piece(dp, board);
	int dx = dp.get_x() - this->_sp->get_x(), dy = dp.get_y() - this->_sp->get_y(); //d = distance 

	Point temp = *this->_sp;
	if (Piece::first_check(board, *this->_sp, dp, this->_color)) {
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
			while (temp != dp) //temp is a point
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
			while (temp != dp) //temp is a point
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
			while (temp != dp) //temp is a point
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
			while (temp != dp) //temp is a point
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

