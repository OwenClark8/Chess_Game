#ifndef BishopDEF
#define BishopDEF


#include "AbstractPiece.h"


class Bishop: public AbstractPiece
{
public:
	Bishop(Board* b, Colour c, Location pos, PrintImpl* pi) :  AbstractPiece(b, std::make_pair(c, 
		Piece::Bishop), pos, pi)
	{};

	Bishop(const Bishop&) = delete;
	Bishop(Bishop&&)      = delete;

	Bishop& operator=(const Bishop&) = delete;
	Bishop& operator=(Bishop&&)      = delete;

	std::list<Location> getMovementOptions(Colour c) const override;

	void movePiece(Location loc) override;

	void draw() const override; 

private:
	void checkULDiag(std::list<Location>& locs) const;
	void checkURDiag(std::list<Location>& locs) const;
	void checkLRDiag(std::list<Location>& locs) const;
	void checkLLDiag(std::list<Location>& locs) const;


};


#endif