#pragma once
#include <string>

class board
{
private:
	std::string _theBoard; //big letter - white, small letter - black 
	int _turn; //0 - white 1 - black 
public:
	//constructor 
	board(); 
};