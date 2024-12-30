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

void Bishop::move(const std::vector<Piece*>& board, const Point& dstp)
{
	char sPiece = Point::get_piece(*this->_srcp, board);
	char dPiece = Point::get_piece(dstp, board);
	int dx = dstp.get_x() - this->_srcp->get_x(), dy = dstp.get_y() - this->_srcp->get_y(); //d = distance 
	bool isOk = true;

	Point temp = *this->_srcp;
	if (Piece::first_check(board, *this->_srcp, dstp, this->_color))
	{
		isOk = false;
	}
	else if (std::abs(dx) != std::abs(dy)) // bishop check
	{
		isOk = false;
		throw 6; //code 6  
	}
	else
	{
		//checks if there is a piece in the bishop's way
		if (dx > 0 && dy > 0) // forward and right
		{
			while (temp != dstp) //temp is a point
			{
				temp.set_x(temp.get_x() + 1);
				temp.set_y(temp.get_y() + 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else if (dx < 0 && dy > 0) // forward and left
		{
			while (temp != dstp) //temp is a point
			{
				temp.set_x(temp.get_x() - 1);
				temp.set_y(temp.get_y() + 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else if (dy < 0 && dx > 0) // backwards and right
		{
			while (temp != dstp) //temp is a point
			{
				temp.set_y(temp.get_y() - 1);
				temp.set_x(temp.get_x() + 1);
				if (Point::get_piece(temp, board) != '#')
				{
					throw 6; //code 6 
				}
			}
		}
		else // backwards and left
		{
			while (temp != dstp) //temp is a point
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

	if (isOk)
	{
		Point::replace(*Point::get_piece_class(*this->_srcp, board), *Point::get_piece_class(dstp, board), board);
	}
}




