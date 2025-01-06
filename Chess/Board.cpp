#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Point.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Empty.h" 
#include "Pawn.h"

#define BOARD "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr"
#define BOARD_LEN 64
#define ROW_COL 8

// constructor 
Board::Board() // white = 0, black = 1
{
	this->_player1 = Player(0);
	this->_player2 = Player(1);
	this->_turn = 1;
	 
	char p = ' '; 
	int color = 0; 
	for (int i = 0; i < BOARD_LEN; i++)
	{
		p = toupper(BOARD[i]); 
		switch (p)
		{
		case 'R':
			this->_board.push_back(new Rook(color, new Point(i)));
			break; 
		case 'N':
			this->_board.push_back(new Knight(color, new Point(i)));
			break;
		case 'B':
			this->_board.push_back(new Bishop(color, new Point(i)));
			break;
		case 'Q': 
			this->_board.push_back(new Queen(color, new Point(i)));
			break;
		case 'K':
			this->_board.push_back(new King(color, new Point(i)));
			break;
		case 'P':
			this->_board.push_back(new Pawn(color, new Point(i)));
			break;
		case '#': 
			this->_board.push_back(new Empty(-1, new Point(i)));
			color = 1; // changes the color after arriving empty
			break;
		}
	}
}

// getters
int Board::get_turn()
{
	return this->_turn;
}

std::vector<Piece*> Board::get_board() const
{
	return this->_board;
}

// other
std::string Board::get_board_string() const
{
	Point coords = Point("00");
	std::string board_str = "";
	int i = 1, j = 1;
	for (i = 1; i <= ROW_COL; i++)
	{
		for (j = 1; j <= ROW_COL; j++)
		{
			board_str += this->_board.at(((8 - i) * 8) + j - 1)->get_type();
			//std::cout << this->_board.at(((8 - i) * 8) + j-1)->get_type();
			if (j % 8 == 0)
			{
				board_str += "\n";
				//std::cout << std::endl;
			}
		}
	}
	return board_str;
}

void Board::update_board(std::vector<Piece*> board)
{
	this->_board = board;
}

int Board::move(int i1, int i2)
{
	int code_to_return = 0;
	if (this->_turn == 0)
	{
		try
		{
			code_to_return = this->_player1.move(this->_board, this->_board[i1], this->_board[i2]);
		}
		catch (int error)
		{
			code_to_return = error;
		}
	}
	else
	{
		try
		{
			code_to_return = this->_player2.move(this->_board, this->_board[i1], this->_board[i2]);
		}
		catch (int error)
		{
			code_to_return = error; 
		}
	}

	//replace the turn
	if (code_to_return == 0 || code_to_return == 1)
		if (this->_turn == 0)
		{
			this->_turn = 1;
		}
		else
		{
			this->_turn = 0;
		}
	return code_to_return; 
}
