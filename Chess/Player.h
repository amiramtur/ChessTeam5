#pragma once

#include "Piece.h"
#include <string>

class Player
{
protected: 
	int _color;
public:
	// constructors
	Player(); // might cause issues, keep an eye on it
	Player(int color);

	// getter
	int get_color();

	void move(std::vector<Piece*>& board, Piece* srcp, Piece* dstp);
};