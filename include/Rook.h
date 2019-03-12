#ifndef ROOKDEF
#define ROOKDEF


#include "AbstractPiece.h"


class Rook: public AbstractPiece
{
public:
	Rook(Board* b, Colour c, Location pos, PrintImpl* pi) :  AbstractPiece(b, std::make_pair(c, 
		Piece::King), pos, pi)
	{};

	Rook(const Rook&) = delete;
	Rook(Rook&&)      = delete;

	Rook& operator=(const Rook&) = delete;
	Rook& operator=(Rook&&)      = delete;

	std::list<Location> getMovementOptions() const override;

	void movePiece(Location loc) override;

	void draw() const override; 

private:
	void checkU(std::list<Location>& locs) const;
	void checkR(std::list<Location>& locs) const;
	void checkD(std::list<Location>& locs) const;
	void checkL(std::list<Location>& locs) const;


};


#endif