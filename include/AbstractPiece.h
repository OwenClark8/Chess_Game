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
	bool m_inCheck = false;

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

	virtual std::list<Location> getMovementOptions(Colour c) const = 0; 

	virtual void TrimMovements(std::list<Location>& locs, Colour curPlayTurn) const;

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



/**************************************************************************
 *
 *  FUNCTION NAME: TrimMovements
 *
 *  PURPOSE:       Eleiminate any movemetns that are constrained by being in check          
 *  
 *  ARGUMENT LIST:
 *
 *  Argument        Type        			IO      Description
 *
 *  locs            std::list<location>     I       list of locations piece can move to unconstrained 
 *   
 *  out             void   				    O       
 *
 *
 *************************************************************************/