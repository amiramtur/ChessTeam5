#include "Pawn.h"
#include <cstdlib> // for "abs()"

Pawn::Pawn(const int color, Point* sp) : Piece()
{
	this->_color = color;
	this->_sp = sp; 
}

Pawn::~Pawn()
{
	this->_color = -1; //no value 
	delete(this->_sp); 
}

std::string Pawn::move(Piece* board, Point& dp)
{
	char sPiece = Point::get_piece(*this->_sp, board), dPiece = Point::get_piece(dp, board); 
	int dx = dp.get_x() - this->_sp->get_x(), dy = dp.get_y() - this->_sp->get_y(); // d = distance 
	bool start = this->_sp->get_y() == 2; 

	
	if (Piece::first_check(board, *this->_sp, dp, this->_color)) 
	{ 
		if ((start == true && std::abs(dy) > 2) || (start == false && std::abs(dy) > 1) || 
			(std::abs(dx) > 1 && dPiece == '#') || dy < 1)  // invalid moves - pawn 
		{
			throw 6; // code 6
		}
		else if (dPiece == 'k' || dPiece == 'K')
		{
			throw 8; // code 8, needs fixing
		}
	}

	return Point::replace(*this->_sp, dp, board);
}
