#include "Player.h"
#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"

#define BOARD_LEN 64

Player::Player()
{
	this->_color = -1;
}

Player::Player(int color)
{
	this->_color = color; 
}

int Player::get_color()
{
	return this->_color;
}

int Player::move(std::vector<Piece*>& board, Piece* srcp, Piece* dstp)
{
	int code_to_return = 0, i = 0;
	bool isOk = true;
	
	if (srcp->get_color() != this->_color){
		isOk = false; 
		code_to_return = 2;
	}

	if(isOk)
	{
		try //try to move the piece
		{
			isOk = srcp->move(board, *dstp->getPoint());
			if (isOk) {
				Point::replace(*srcp, *dstp, board);
			}
		}
		catch (int eror_code)
		{
			isOk = false;
			code_to_return = eror_code;
		}
	}

	

	if (isOk) //check if there is chess on the kings
	{
		//chess checks: 
		int other_color = 0;
		if (other_color == this->_color)
		{
			other_color = 1;
		}
		Point my_king = *Point::find_king(board, this->_color);
		Point other_king = *Point::find_king(board, other_color);
		for (i = 0; i < BOARD_LEN; i++) //Goes through every piece on the board
		{
			if(board.at(i)->get_color() == other_color)
			{
				try
				{
					if (board.at(i)->move(board, my_king))
					{
						code_to_return = 4; 
					}
				}
				catch (int error)
				{}
			}
			else if (board.at(i)->get_color() == this->_color)
			{
				try
				{
					if (board.at(i)->move(board, other_king))
					{
						code_to_return = 1;
					}
				}
				catch (int error)
				{}
			}
		}
	}

	return code_to_return;


}
