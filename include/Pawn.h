#ifndef PAWNDEF
#define PAWNDEF

#include "AbstractPiece.h"
#include "Component.h"

#include "Subject.h"


class Pawn :
	public AbstractPiece, public Observer<Location>, public Subject<Location>
{	

protected:

	std::array<bool,2> m_empassantcheck = std::array<bool,2>{false, false}; 

	std::array<std::pair<Location, bool>, 2> m_empassantlocs = 
			std::array<std::pair<Location, bool>, 2>{ std::make_pair(Location(), false) , std::make_pair(Location(), false) };
	
public:

	Pawn(Board* b, Colour c, Location pos, PrintImpl* pi): AbstractPiece(b, std::make_pair(c, 
		Piece::Pawn), pos, pi)
	{};

	~Pawn() = default;

	void movePiece(Location position) override; 

	//std::unique_ptr<AbstractPiece> clone() override;

	std::list<Location> getMovementOptions() const override;

	void draw() const override;

	void notify() const override;

	void update(const Location& L) override;

private:

	void check2Ahead(std::list<Location>& l) const;

	void check1Ahead(std::list<Location>& l) const;

	void checkSides(std::list<Location>& l) const;

	void checkEnPassant(std::list<Location>& l) const;


};
#endif
