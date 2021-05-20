#ifndef KINGDEF
#define KINGDEF

#include "AbstractPiece.h"
#include "Key.h"


class King :
	public AbstractPiece 
{
public:

	King(Board* b, Colour c, Location pos, PrintImpl* pi) :  AbstractPiece(b, std::make_pair(c, 
		Piece::King), pos, pi)
	{};

	~King() = default;

	void movePiece(Location position) override; 

	std::list<Location> getMovementOptions(Colour c) const override;

	void draw() const override;

	void getTrimmedMovements(std::list<Location>& locs, Colour c) const;

	void computeMove();
private:

	void checkCastle(std::list<Location>& locs) const;

	bool m_computeMove = true;

	std::list<Location> m_movements;


};

#endif
