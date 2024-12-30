#pragma once

#include "Point.h"


class Empty : public Piece {
private: 
	Point* _srcp; 
public: 
	Empty(Point* srcp);
	~Empty();

	virtual Point* getPoint() const override; 
	virtual char get_type() override;
	virtual std::vector<Piece*> move(std::vector<Piece*> board, Point& dstp) override;
};