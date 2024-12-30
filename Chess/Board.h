#pragma once
#include "Piece.h"
#include "Player.h"
#include <string>
#include <vector>

#define BOARD_LEN 64

class Board
{
private:
	std::vector<Piece*> _board;
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
	Piece* get_board();

	// other
	void update_board(Piece* board);
};