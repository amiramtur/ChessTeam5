#include "Player.h"
#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"

Player::Player(int color)
{
	this->_color = color;
	//this->_king = King(color);
	//this->_rook = Rook(color); // add Rook constructor
	//this->_knight = Knight(color); // add Knight constructor
	//this->_pawn = Pawn(color); // add Pawn Constructor
	//this->_queen = Queen(color); // add Queen constructor
	//this->_bishop = Bishop(color); // add Bishop constructor
	//this->_board = Board::get_board();
}

Player::~Player()
{
	// distructors are automatically called
	this->_board = "";
}

int Player::get_color()
{
	return this->_color;
}