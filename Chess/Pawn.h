#pragma once
#include "King.h"
#include "Piece.h"
#include "Point.h"

class Pawn : public Piece
{
private:
	int _color; //0 = white, 1 = black
	Point* _srcp; //source point
public:
	Pawn(const int color, Point* sp);
	~Pawn();
	
	virtual char get_type() override;
	virtual int get_color() const override;
	virtual Point* getPoint() const override; 
	virtual bool move( const std::vector<Piece*>& board, const Point& dstp) const override; // sp = source point, dp = distanation point
};

