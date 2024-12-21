#pragma once
#include <string>
#include "Player.h"

class Board
{
private:
	std::string _board; // BIG LETTER - WHITE | small letter - black 
	int _turn; // white - 0 | black - 1
	Player _player1;
	Player _player2;
public:
	// constructor 
	Board();

	// destructor
	~Board();

	// getter
	int get_turn();

	// other
	std::string update_board(std::string board);
};