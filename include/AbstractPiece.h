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
	bool m_unused = true;
	int  m_moveNo = 0;
	bool m_default = true;

public:
	AbstractPiece(Board* b, PieceType type, Location pos, PrintImpl* pi, bool defaultGame = true) : Component(pi),
		mp_gameboard(b), m_position(pos), m_type(type)
	{
		if(!defaultGame)
		{
			m_unused = false;
			m_default = false;
		}
	};	

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

	void incrementMoveNo();

	void decrementMoveNo();

	int getMoveNo() const;

	void updateMoveNo(int i);


};

#endif