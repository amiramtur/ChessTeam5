#pragma once

#include "Piece.h"
#include <string>

class Player
{
protected: 
	int _color;
public:
	// constructor
	Player(int color);

	// destructor
	~Player();

	// getter
	int get_color();

	void move(std::vector<Piece*>& board, Piece* srcp, Piece* dstp);
};