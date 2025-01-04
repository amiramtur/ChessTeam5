#include "Pawn.h"
#include <cstdlib> // for "abs()"

#define WHITE 0
#define BLACK 1

Pawn::Pawn(const int color, Point* sp) : Piece()
{
	this->_color = color; 
	this->_srcp = sp; 
}

Pawn::~Pawn()
{
	this->_color = -1; //no value 
	delete this->_srcp; 
}

char Pawn::get_type()
{
	if (this->_color == WHITE)
	{
		return 'P';
	}
	return 'p';
}

int Pawn::get_color() const
{
	return this->_color; 
}

Point* Pawn::getPoint() const
{
	return this->_srcp; 
}

bool Pawn::move(const std::vector<Piece*>& board, const Point& dstp) const
{
	char sPiece = Point::get_piece(*this->_srcp, board), dPiece = Point::get_piece(dstp, board);
	int dx = dstp.get_x() - this->_srcp->get_x(), dy = dstp.get_y() - this->_srcp->get_y(); // d = distance 
	bool start = std::abs(this->_srcp->get_y()) == 2; 
	bool isOk = true;

	if (Piece::first_check(board, *this->_srcp, dstp, this->_color))
	{ 
		isOk = false;
	}



	// Pawn check
	int direction = (this->_color == WHITE) ? 1 : -1;
	int maxDy = start ? 2 : 1;

	// normal movement
	if (dy * direction < 1 || dy * direction > maxDy || std::abs(dx) > 1) {
		isOk = false;
		throw 6; // code 6
	}
	// eating
	if (std::abs(dx) == 1 && dPiece == '#') {
		isOk = false;
		throw 6; // code 6
	}
	
	return isOk; 
}


// pawn check
	//if ((start && this->_color == WHITE) && 
	//	((dy > 2) || (dy < 1) // normal movement
	//	|| (std::abs(dx) > 1) || (std::abs(dx) == 1 && Point::get_piece(dstp, board) == '#'))) // eating
	//{
	//	isOk = false;
	//	throw 6; // code 6
	//}

	//else if ((start && this->_color == BLACK) &&
	//		((dy < 2) || (dy > 1) // normal movement
	//		|| (std::abs(dx) > 1) || (std::abs(dx) == 1 && Point::get_piece(dstp, board) == '#'))) // eating
	//{
	//	isOk = false;
	//	throw 6; // code 6
	//}

	//else if ((!start && this->_color == WHITE) &&
	//		((dy > 1) || (dy < 1) // normal movement
	//		|| (std::abs(dx) > 1) || (std::abs(dx) == 1 && Point::get_piece(dstp, board) == '#'))) // eating
	//{
	//	isOk = false;
	//	throw 6; // code 6
	//}
	//else if ((start && this->_color == BLACK) &&
	//		((dy < 1) || (dy > 1) // normal movement
	//		|| (std::abs(dx) > 1) || (std::abs(dx) == 1 && Point::get_piece(dstp, board) == '#'))) // eating
	//{
	//	isOk = false;
	//	throw 6; // code 6
	//}