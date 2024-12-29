#include "Point.h"



Point::Point(std::string cords)
{
	this->_x = (int)cords[0]; 
	this->_y = (int)cords[1]; 
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

std::string Point::replace(Point sp, Point dp, std::string board)
{
	int si = Point::get_index(sp), di = Point::get_index(dp); 

	board[di] = board[si]; 
	board[si] = '#'; 

	return board; 
}

char Point::get_piece(Point p, std::string board)
{ 
	return board[Point::get_index(p)];
}

bool Point::is_my_color(char piece, int color)
{
	//0 - white 1 - black 
	if (color == 0) //if the color is white (big letters)
	{
		if (isupper(piece))
		{
			return true;
		}
	}
	else
	{
		if (!(isupper(piece)))
		{
			return true;
		}
	}
	return false;
}


