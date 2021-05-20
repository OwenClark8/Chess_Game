#include "../include/LossBoard.h"


void LossBoard::logPiece(PieceType p)
{
	int i = static_cast<int>(std::get<Colour>(p));
	int j = static_cast<int>(std::get<Piece>(p));
	++m_pieces[i][j];
}

void LossBoard::unlogPiece(PieceType p)
{
	int i = static_cast<int>(std::get<Colour>(p));
	int j = static_cast<int>(std::get<Piece>(p));
	if(m_pieces[i][j] != 0)
		--m_pieces[i][j];
}


void LossBoard::draw() const
{
	mp_Imp->drawLossBoard(m_pieces);
}