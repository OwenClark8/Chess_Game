#include "stdafx.h"
#include "EmptyPiece.h"


EmptyPiece::EmptyPiece(int* position)
{
	m_position = position;
}


EmptyPiece::~EmptyPiece()
{
}

int* EmptyPiece::GetPosition() const
{
	return m_position;
}
