#include "Board.h"
#include "Player.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Empty.h" 

#define BOARD "RNBQKBNRPPPPPPPP################################pppppppprnbkqbnr"
#define BOARD_LEN 64

// constructor 
Board::Board() //white =0, black =1
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
		case '#': 
			this->_board.push_back(new Empty(new Point(i)));
			color = 1; //changes the color after arriving empty
			break;
		}
	}
}

// destructor
Board::~Board()
{
	//this->_board = ""; UPDATE!
	~Player(this->_player1); // doesn't need fixing, add a Player destructor
	~Player(this->_player2); // doesn't need fixing, add a Player destructor
}

// getters
int Board::get_turn()
{
	return this->_turn;
}

Piece* Board::get_board()
{
	return this->_board;
}

// other
void Board::update_board(Piece* board)
{
	this->_board = board;
}
