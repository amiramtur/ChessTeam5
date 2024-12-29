#include "Board.h"
#include "Player.h"

//#define PieceString "RNBQKBNRPPPPPPPP################################pppppppprnbkqbnr"


// constructor 
Board::Board()
{
	this->_board[BOARD_LEN];
	this->_player1 = Player(0);
	this->_player2 = Player(1);
	this->_turn = 1;
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
