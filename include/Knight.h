#ifndef KNIGHTDEF
#define KNIGHTDEF

#include "AbstractPiece.h"




class Knight: public AbstractPiece
{
public:
	Knight(Board* b, Colour c, Location pos, PrintImpl* pi) :  AbstractPiece(b, std::make_pair(c, 
		Piece::Knight), pos, pi)
	{};

	Knight(const Knight&) = delete;
	Knight(Knight&&)      = delete;

	Knight& operator=(const Knight&) = delete;
	Knight& operator=(Knight&&)      = delete;

	std::list<Location> getMovementOptions() const override;

	void movePiece(Location loc) override;

	void draw() const override; 

private:

	void checkD(std::list<Location>& locs) const;
	void checkU(std::list<Location>& locs) const;
	void checkR(std::list<Location>& locs) const;
	void checkL(std::list<Location>& locs) const;



};


#endif