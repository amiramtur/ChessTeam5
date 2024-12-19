#pragma once
#include <string>
#include "Piece.h"

class King : Piece
{
public:
	King(int color); 
	int left_step(std::string board, int cord) const; //return code
	int right_step(std::string board, int cord) const; //return code
	int back_step(std::string board, int cord) const;
	int forward_step(std::string board, int cord) const;

};