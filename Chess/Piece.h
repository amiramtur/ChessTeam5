#pragma once

#include <vector>
class Point;

class Piece
{
protected:
	int _color; //0 = white, 1 = black
	Point* _srcp; //source point
public:
	Piece(int color, Point* srcp);
	virtual ~Piece();  
	virtual char get_type() = 0;
	virtual int get_color() const = 0;
	virtual Point* getPoint() const = 0;
	static bool first_check(const std::vector<Piece*>& board, const Point& sp, const Point& dp, const int color); // treat at 3 and 7 codes 
	virtual bool move(const std::vector<Piece*>& board, const Point& dstp) const = 0;
};