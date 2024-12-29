#include "Queen.h"

#define WHITE 0

char Queen::get_type()
{
	if (this->_color == WHITE)
	{
		return 'Q';
	}
	return 'q';
}