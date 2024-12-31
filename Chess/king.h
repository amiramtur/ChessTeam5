#pragma once
#include <string>
#include "Point.h"
#include "Piece.h"

class King : public Piece 
{
private: 
	int _color; // 0 - white 1 - black 
	Point* _srcp; //source point 
public:
	King(int color, Point* srcp); 
	~King();
	virtual Point* getPoint() const override; 
	virtual char get_type() override;
	virtual void move(std::vector<Piece*>& board, Point& dstp) override; // dstp = distanation point
};