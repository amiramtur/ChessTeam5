#pragma once

#include "Board.h"
#include "Player.h"

#define PieceString "RNBQKBNRPPPPPPPP################################pppppppprnbkqbnr"


// constructor 
Board::Board()
{
	this->_board = PieceString;
	this->_player1 = Player(0); // doesn't need fixing, add a parameter in Player's constructor
	this->_player2 = Player(1); // doesn't need fixing, add a parameter in Player's constructor
	this->_turn = 1;
}

// destructor
Board::~Board()
{
	this->_board = "";
	~Player(this->_player1); // doesn't need fixing, add a Player destructor
	~Player(this->_player2); // doesn't need fixing, add a Player destructor
}

// getter
int Board::get_turn()
{
	return this->_turn;
}

// other
std::string Board::update_board(std::string board)
{
	this->_board = board;
}
