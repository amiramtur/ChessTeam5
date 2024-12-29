#include "Point.h"
#include "Empty.h"

#define WHITE 0
//#define BLACK 1

Point::Point(std::string coords)
{
	this->_x = (int)coords[0]; 
	this->_y = (int)coords[1] - '0'; // converting ascii value to number 
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

void Point::set_x(int x)
{
	this->_x = x; 
}

void Point::set_y(int y)
{
	this->_y = y; 
}

bool Point::operator!=(const Point& other) const
{
	return (other.get_x() != this->_x || other.get_y() != this->_y);
}

int Point::get_index(Point p)
{
	int i = 0;
	i = (p.get_y() - 1) * 8;
	i += (p.get_x() - 1);

	return i;
}

Piece* Point::replace(Point sp, Point dp, Piece* board)
{
	int srci = Point::get_index(sp), dsti = Point::get_index(dp); 

	board[dsti] = board[srci]; 
	board[srci] = Empty(srci); // help :(

	return board; 
}

Piece* Point::get_piece(Point p, Piece* board) // needs checking
{ 
	return &board[Point::get_index(p)];
}

bool Point::is_my_color(char piece, int my_color)
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


