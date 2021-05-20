#ifndef QueenDEF
#define QueenDEF


#include "AbstractPiece.h"


class Queen: public AbstractPiece
{
public:
	Queen(Board* b, Colour c, Location pos, PrintImpl* pi) :  AbstractPiece(b, std::make_pair(c, 
		Piece::Queen), pos, pi)
	{};

	Queen(const Queen&) = delete;
	Queen(Queen&&)      = delete;

	Queen& operator=(const Queen&) = delete;
	Queen& operator=(Queen&&)      = delete;

	std::list<Location> getMovementOptions(Colour c) const override;

	void movePiece(Location loc) override;

	void draw() const override; 

private:
	void checkULDiag(std::list<Location>& locs) const;
	void checkURDiag(std::list<Location>& locs) const;
	void checkLRDiag(std::list<Location>& locs) const;
	void checkLLDiag(std::list<Location>& locs) const;
	void checkU(std::list<Location>& locs) const;
	void checkR(std::list<Location>& locs) const;
	void checkD(std::list<Location>& locs) const;
	void checkL(std::list<Location>& locs) const;


};


#endif