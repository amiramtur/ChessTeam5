#include <iostream>
#include <string> // check if necessary
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

#define BOARD "RNBQKBNRPPPPPPPP################################pppppppprnbkqbnr"
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
			this->_board.push_back(new Empty(new Point(i)));
			color = 1; //changes the color after arriving empty
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
void Board::print_board() const
{
	Point coords = Point("00");
	int i = 1, j = 1, k = 0;
	for (i = 1; i <= ROW_COL; i++)
	{
		for (j = 1; j <= ROW_COL; j++)
		{
			std::cout << this->_board.at(k)->get_type();
			k++;
			if (j % 8 == 0)
			{
				std::cout << std::endl;
			}
		}
	}
}

void Board::update_board(std::vector<Piece*> board)
{
	this->_board = board;
}
