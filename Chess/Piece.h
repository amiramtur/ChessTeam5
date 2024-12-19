#pragma once

#include <string>

class Piece
{
protected: 
	int _color; 
public: 
	//static std::string find_in_board(std::string board, );
	bool is_my_color(char piece) const; //must to get letter (not #)

	Piece(int color); 
};