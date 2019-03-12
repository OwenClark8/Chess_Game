#ifndef ABSTRACTPIECEDEF
#define ABSTRACTPIECEDEF
#include <iostream>
#include <string>
#include <cassert>


#include "Component.h"



class Board;

class AbstractPiece: public Component
{
protected:
	Location m_position;
	PieceType m_type;
	Board* mp_gameboard;

public:
	AbstractPiece(Board* b, PieceType type, Location pos, PrintImpl* pi) : Component(pi),
		mp_gameboard(b), m_position(pos), m_type(type)
	{};	

	virtual ~AbstractPiece(); 

	AbstractPiece(const AbstractPiece&) = delete;
	AbstractPiece(AbstractPiece&&)      = delete;

	AbstractPiece& operator=(const AbstractPiece&) = delete;
	AbstractPiece& operator=(AbstractPiece&&)      = delete;

	//virtual std::unique_ptr<AbstractPiece> clone() const = 0; 

	virtual std::list<Location> getMovementOptions() const = 0; 

	virtual void  draw() const = 0;

	virtual void movePiece(Location position); 

	Location getPosition() const; 

	PieceType getPieceType() const;
};

#endif