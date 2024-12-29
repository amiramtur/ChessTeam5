#pragma once

#include "Player.h"
#include <string>

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

	// getters
	int get_turn();
	std::string get_board();

	// other
	std::string update_board(std::string board);
};