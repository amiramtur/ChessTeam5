#pragma once

#include "Piece.h"
#include <string>

class Point
{
private:
	int _x; 
	int _y; 
public: 
	Point(std::string coords); //For example cords = [e,1] (the value which is returned from the c# file) 
	~Point(); 

	int get_x() const; 
	int get_y() const; 
	void set_x(int x); 
	void set_y(int y); 
	
	static int get_index(Point p);
	static Piece* get_piece(Point p, Piece* board);
	static Piece* replace(Point sp, Point dp, Piece* board); // swaps two points
	static bool is_my_color(char piece, int my_color);
	bool operator!=(const Point& other) const;
};