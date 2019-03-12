#ifndef KINGDEF
#define KINGDEF

#include "AbstractPiece.h"


class King :
	public AbstractPiece 
{
public:

	King(Board* b, Colour c, Location pos, PrintImpl* pi) :  AbstractPiece(b, std::make_pair(c, 
		Piece::King), pos, pi)
	{};

	~King() = default;

	void movePiece(Location position) override; 

	std::list<Location> getMovementOptions() const override;

	void draw() const override;

private:

	//void checkCastle(std::list<Location>& locs) const;

};

#endif
