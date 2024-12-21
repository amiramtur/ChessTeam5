#pragma once

#include "Piece.h"
#include <string>

class Player
{
private: 
	King _king;
	Rook _rook;
	Knight _knight;
	Pawn _pawn;
	Queen _queen;
	Bishop _bishop;
protected: 
	int _color;
	std::string _board;

public:
	// constructor 
	Player(int color);

	// destructor
	~Player();

	// getter
	int get_color();
};