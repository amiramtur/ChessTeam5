#pragma once

#include "Piece.h"
#include "Point.h"


class Empty : public Piece {
private: 
	Point* _srcp; 
public: 
	Empty(Point* srcp);
	~Empty();

	virtual Point* getPoint() const override; 
	virtual int get_color() const override;
	virtual char get_type() override;
	virtual void move(std::vector<Piece*>& board, Point& dstp) override;
};