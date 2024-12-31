#include "Player.h"
#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"

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

void Player::move(std::vector<Piece*>& board, Piece* srcp, Piece* dstp)
{

}
