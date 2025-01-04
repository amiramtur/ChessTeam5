#include "Queen.h"

#define WHITE 0

Queen::Queen(const int color, Point* srcp) : Piece(color, srcp)
{
	this->_myBishop = new Bishop(color, srcp); 
	this->_myRook = new Rook(color, srcp); 
}

Queen::~Queen() 
{
	delete this->_myBishop; 
	delete this->_myRook; 
	delete this->_srcp; 
}

int Queen::get_color() const
{
	return this->_myBishop->get_color(); 
}

char Queen::get_type()
{
	if (this->get_color() == WHITE)
	{
		return 'Q';
	}
	return 'q';
}

Point* Queen::getPoint() const
{
	return this->_myBishop->getPoint(); 
}

bool Queen::move(const std::vector<Piece*>& board,const Point& dstp) const
{
	bool isOk = true; 
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
			isOk = false; 
			throw eror2; 
		}
	}

	return isOk; 
}

