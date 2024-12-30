#include "Point.h"
#include "Empty.h"

#define WHITE 0
//#define BLACK 1

Point::Point(std::string cords)
{
	this->_x = (int)cords[0]; 
	this->_y = (int)cords[1] - '0'; // converting ascii value to number 
}

Point::Point(int index)
{
	this->_x = (index / 8) + 1; 
	this->_y = (index % 8) + 1; 
}

Point::~Point()
{
	this->_x = -1;
	this->_y = -1;
}

int Point::get_x() const
{
	return this->_x; 
}

int Point::get_y() const
{
	return this->_y; 
}

void Point::set_x(const int x)
{
	this->_x = x; 
}

void Point::set_y(const int y)
{
	this->_y = y; 
}

bool Point::operator!=(const Point& other) const
{
	return (other.get_x() != this->_x || other.get_y() != this->_y);
}

int Point::get_index(const Point& p)
{
	int i = 0;
	i = (p.get_y() - 1) * 8;
	i += (p.get_x() - 1);

	return i;
}

void Point::replace(const Piece& srcp, const Piece& dstp, std::vector<Piece*>& board)
{
	int srci = Point::get_index(*srcp.getPoint()), dsti = Point::get_index(*dstp.getPoint()); 

	delete board[dsti];
	board[dsti] = board[srci];
	board[srci] = new Empty(srcp.getPoint());
}

Piece* Point::get_piece_class(const Point& p, const std::vector<Piece*>& board)
{
	return board[Point::get_index(p)];
}

char Point::get_piece(const Point& p, const std::vector<Piece*>& board) // needs checking
{ 
	return board[Point::get_index(p)]->get_type(); 
}

bool Point::is_my_color(const char piece, const int my_color)
{
	if (my_color == WHITE) // - uppercase
	{
		if (isupper(piece))
		{
			return true;
		}
	}
	else // black - lowercase
	{
		if (!(isupper(piece)))
		{
			return true;
		}
	}
	return false;
}


