#ifndef SQUARE
#define SQUARE



#include "Component.h"
#include "AbstractPiece.h"



class Square : public Component
{
protected:
	std::unique_ptr<AbstractPiece> mp_piece;
	bool 						   m_allocated = false;
	Location	                   m_position;
	bool 						   m_selected = false;

public:
	Square(PrintImpl* pi, const Location& pos) : Component(pi), m_position(pos)
	{};

	~Square() = default;

	void addPiece(std::unique_ptr<AbstractPiece> P);
	void removePiece();

	void movePieceIn(std::unique_ptr<AbstractPiece> P);

	std::unique_ptr<AbstractPiece> movePieceOut();

	PieceType getPieceType() const;

	AbstractPiece* getPieceHandle();

	bool isAllocated() const;

	void select();

	void unselect();

	std::list<Location> clicked() const;
 
	void draw() const override;
};

#endif