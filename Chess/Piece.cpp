#include "Piece.h"

#define BIG_A 65
#define BIG_Z 90
#define SMALL_A 97
#define SMALL_Z 122

bool Piece::is_my_color(char piece) const
{ 

	if (this->_color == 0) //if the color is white (big letters)
	{
		if ((int)piece >= BIG_A && (int)piece <= BIG_Z)
		{
			return true; 
		}
	}
	else 
	{
		if ((int)piece >= SMALL_A && (int)piece <= SMALL_Z)
		{
			return true;
		}
	}
	return false; 
}

Piece::Piece(int color)
{
	this->_color = color; 
}
