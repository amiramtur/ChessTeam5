#include "Bishop.h"

#define WHITE 0

Bishop::Bishop(const int color, Point* srcp) : Piece(){
	this->_color = color; 
	this->_srcp = srcp; 
}

Point* Bishop::getPoint() const
{
	return this->_srcp; 
}

char Bishop::get_type()
{
	if (this->_color == WHITE)
	{
		return 'B';
	}
	return 'b';
}

std::vector<Piece*> Bishop::move(std::vector<Piece*> board, Point& dstp)
{
	char sPiece = Point::get_piece(*this->_srcp, board);
	char dPiece = Point::get_piece(dstp, board);
	int dx = dstp.get_x() - this->_srcp->get_x(), dy = dp.get_y() - this->_srcp->get_y(); //d = distance 

	Point temp = *this->_srcp;

	if (sPiece != 'B' && sPiece != 'b' || !(Point::is_my_color(sPiece, this->_color))) //if the source is not ok 
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
	else if (std::abs(dx) != std::abs(dy)) //if it not matches the bishop's movements
	{
		throw 6; //code 6  
	}
	else if (dPiece == 'k' || dPiece == 'K')
	{
		throw 8; //code 8
	}
	else
	{
		//checks if there is a piece in the bishop's way
		if (dx > 0 && dy > 0) //if the bishop moves right and forward
		{
			while (temp != dp) //temp is a point
			{
				temp.set_x(temp.get_x() + 1);
				temp.set_y(temp.get_y() + 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else if (dx < 0 && dy > 0) //if the bishop moves left and forward
		{
			while (temp != dp) //temp is a point
			{
				temp.set_x(temp.get_x() - 1);
				temp.set_y(temp.get_y() + 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else if (dy < 0 && dx > 0) //if the bishop moves backwards and right
		{
			while (temp != dp) //temp is a point
			{
				temp.set_y(temp.get_y() - 1);
				temp.set_x(temp.get_x() + 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else //if the bishop moves backwards and left
		{
			while (temp != dp) //temp is a point
			{
				temp.set_y(temp.get_y() - 1);
				temp.set_x(temp.get_x() - 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
	}

	return Point::replace(*this->_sp, dp, board);
}




