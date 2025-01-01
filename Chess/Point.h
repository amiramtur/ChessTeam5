#pragma once

#include <vector>
#include <string>

class Piece;

class Point
{
private:
	int _x; 
	int _y; 
public: 
	Point(std::string cords); // For example cords = [e,1] (the value which is returned from the c# file) 
	Point(int index); 
	~Point(); 

	int get_x() const; 
	int get_y() const; 
	void set_x(const int x); 
	void set_y(const int y); 
	
	static int get_index(const Point& p);
	static char get_piece(const Point& p, const std::vector<Piece*>& board);
	static Piece* get_piece_class(const Point& p, const std::vector<Piece*>& board);
	static void replace(const Piece& srcp, const Piece& dstp, std::vector<Piece*>& board); // swaps two points
	static bool is_my_color(const char piece, const int my_color);
	static Point* find_king(const std::vector<Piece*>& board, const int color); 
	bool operator!=(const Point& other) const;
};