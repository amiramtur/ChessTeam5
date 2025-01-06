#include "Rook.h"
//#include "Point.h"
#include <iostream>

#define WHITE 0

Rook::Rook(int color, Point* srcp) : Piece(color, srcp)
{
}

Point* Rook::getPoint() const
{
	return this->_srcp; 
}

char Rook::get_type()
{
	if (this->_color == WHITE)
	{
		return 'R';
	}
	return 'r';
}

int Rook::get_color() const
{
	return this->_color; 
}

bool Rook::move(const std::vector<Piece*>& board, const Point& dstp) const
{
	int dx = dstp.get_x() - this->_srcp->get_x(), dy = dstp.get_y() - this->_srcp->get_y(); //d = distance 
	bool isOk = true; 
	Point temp = *this->_srcp;

	if (Piece::first_check(board, *this->_srcp, dstp, this->_color))
	{
		isOk = false; 
	}
	else if (std::abs(dx) != 0 && std::abs(dy) != 0) // rook check
	{
		isOk = false; 
	 	throw 6; //code 6  
	}
	else
	{
		//checks if there is a piece in the rook's way
		if (dx > 0) //if the rook moves right 
		{
			while (temp != dstp) //temp is a point
			{
				temp.set_x(temp.get_x() + 1);
				if (temp != dstp)
				{
					if (Point::get_piece(temp, board) != '#')
					{
						isOk = false;
						throw 6; //code 6 
					}
				}
			}
		}
		else if (dx < 0) //if the rook moves left
		{
			while (temp != dstp) //temp is a point
			{
				temp.set_x(temp.get_x() - 1);
				if (temp != dstp)
				{
					if (Point::get_piece(temp, board) != '#')
					{
						isOk = false;
						throw 6; //code 6 
					}
				}
			}
		}
		else if (dy > 0) //if the rook moves forward
		{
			while (temp != dstp) //temp is a point
			{
				temp.set_y(temp.get_y() + 1);
				if (temp != dstp)
				{
					if (Point::get_piece(temp, board) != '#')
					{
						isOk = false;
						throw 6; //code 6 
					}
				}
			}
		}
		else //if the rook moves backwards
		{
			while (temp != dstp) //temp is a point
			{
				temp.set_y(temp.get_y() - 1);
				if (temp != dstp)
				{
					if (Point::get_piece(temp, board) != '#')
					{
						isOk = false;
						throw 6; //code 6 
					}
				}
			}
		}
	}

	return isOk; 
}

