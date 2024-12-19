#include "king.h"
#include <iostream>

King::King(int color) : Piece(color)
{
}

//check if phisicaly the piece able to move
int King::left_step(std::string board, int cord) const
{
	if (!(this->is_my_color(board[cord])))
	{
		return 2; 
	}
	if (cord % 8 == 0)
	{
		return 5; //code 5 = there is not index in that place
	}
	if (this->is_my_color(board[cord - 1]))
	{
		return 3; 
	}
	return 0;
}


int King::right_step(std::string board, int cord) const
{
	if (!(this->is_my_color(board[cord])))
	{
		return 2;
	}
	if ((cord + 1) % 8 == 0)
	{
		return 5; //code 5 = there is not index in that place
	}
	if (this->is_my_color(board[cord + 1]))
	{
		return 3;
	}
	return 0;
}

int King::back_step(std::string board, int cord) const
{
	if (!(this->is_my_color(board[cord])))
	{
		return 2;
	}
	if ((cord -8) < 0)
	{
		return 5; //code 5 = there is not index in that place
	}
	if (this->is_my_color(board[cord -8]))
	{
		return 3;
	}
	return 0;
}

int King::forward_step(std::string board, int cord) const
{
	if (!(this->is_my_color(board[cord])))
	{
		return 2;
	}
	if ((cord + 8) < 63)
	{
		return 5; //code 5 = there is not index in that place
	}
	if (this->is_my_color(board[cord + 8]))
	{
		return 3;
	}
	return 0;
}
