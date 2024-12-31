#include "Queen.h"

#define WHITE 0

Queen::Queen(const int color, Point* srcp) : Piece()
{
	this->_myBishop = new Bishop(color, srcp); 
	this->_myRook = new Rook(color, srcp); 
	this->_color = color; 
}

Queen::~Queen()
{
	delete this->_myBishop; 
	delete this->_myRook; 
}

char Queen::get_type()
{
	if (this->_color == WHITE)
	{
		return 'Q';
	}
	return 'q';
}

Point* Queen::getPoint() const
{
	return this->_myBishop->getPoint(); 
}

void Queen::move(std::vector<Piece*>& board, Point& dstp)
{
	try
	{
		this->_myBishop->move(board, dstp); 
	}
	catch (int eror1)
	{
		try
		{
			this->_myRook->move(board, dstp);
		}
		catch (int eror2)
		{
			throw eror2; 
		}
	}
}

