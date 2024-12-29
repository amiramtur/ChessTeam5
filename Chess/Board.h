#pragma once
#include "Piece.h"
#include "Player.h"
#include <string>

#define BOARD_LEN 64
#define WHITE 0
#define BLACK 1

class Board
{
private:
	Piece* _board;
	int _turn; //white - 0 | black - 1
	Player _player1(int color = WHITE);
	Player _player2(int color = BLACK);
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