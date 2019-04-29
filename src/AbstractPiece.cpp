#include "../include/AbstractPiece.h"


AbstractPiece::~AbstractPiece()
{
}

Location AbstractPiece::getPosition() const
{
	return m_position;
}

void AbstractPiece::movePiece(Location position)
{
	m_position = std::move(position);
}

PieceType AbstractPiece::getPieceType() const
{
	return m_type; 
}

void AbstractPiece::incrementMoveNo()
{
	--m_moveNo;
}

void AbstractPiece::decrementMoveNo()
{
	if(m_moveNo == 0)
		return;

	if(--m_moveNo == 0 && m_default)
		m_unused = true;
}

int AbstractPiece::getMoveNo() const
{
	return m_moveNo;
}

void AbstractPiece::updateMoveNo(int i)
{
	if(i == 0 && m_default)
		m_unused = true;

}

