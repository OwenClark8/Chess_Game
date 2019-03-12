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

