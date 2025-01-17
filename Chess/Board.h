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

	// getters
	int get_turn();
	std::vector<Piece*> get_board() const;

	// other
	std::string get_board_string() const;
	void update_board(std::vector<Piece*> board);
	int move(int i1, int i2);
};