#include "Knight.h"
#include "Point.h"
#include <cstdlib> // for "abs()"

#define WHITE 0


Knight::Knight(int color, Point* srcp) : Piece(color, srcp)
{}

Point* Knight::getPoint() const
{
	return this->_srcp; 
}

int Knight::get_color() const
{
	return this->_color; 
}

char Knight::get_type()
{
	if (this->_color == WHITE)
	{
		return 'N';
	}
	return 'n';
}

bool Knight::move(const std::vector<Piece*>& board,const Point& dstp) const
{
	int dx = dstp.get_x() - this->_srcp->get_x(), dy = dstp.get_y() - this->_srcp->get_y(); // d = distance 
	bool isOk = true;
	
	if (Piece::first_check(board, *this->_srcp, dstp, this->_color))
	{
		isOk = false;
	}
	else if (!(std::abs(dx) == 2 && std::abs(dy) == 1) && !(std::abs(dx) == 1 && std::abs(dy) == 2)) // knight check
	{
		isOk = false;
		throw 6; // code 6  
	}
	
	return isOk; 
}
