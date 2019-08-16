#include "../include/AbstractPiece.h"
#include "../include/Board.h"


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
	++m_moveNo;
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

	m_moveNo = i;

}



//
//
//
//
//
//
void AbstractPiece::TrimMovements(std::list<Location>& locs, Colour curPlayTurn) const
{
	if(curPlayTurn != std::get<Colour>(m_type) || std::get<Piece>(m_type) == Piece::King)
		return;

	//auto otherlocs = mp_gameboard->getLocsForCheck(std::get<Colour>(m_type));
	// Check each move to see if check is exited

	auto it = locs.begin();
	auto tlocs = locs;
	auto moveNo = m_moveNo;

	for(auto i = tlocs.begin(); i != tlocs.end(); ++i)
	{
		auto to = mp_gameboard->getPiece(*i);
		Move mov;

		if(std::get<Piece>(to) == Piece::Empty)
			mov = Move(std::make_pair(m_position, *i), std::make_tuple(false, to, moveNo));
		else
			mov = Move(std::make_pair(m_position, *i), std::make_tuple(true, to, moveNo));
		
		mp_gameboard->doMove(mov);

		if(mp_gameboard->inCheck(std::get<Colour>(m_type), curPlayTurn))
		{
			it = locs.erase(it);
		}
		else
			++it;

		mov.m_moveNo = moveNo;
		mp_gameboard->undoMove(mov);

		mp_gameboard->inCheck(std::get<Colour>(m_type), curPlayTurn);


		//mp_gameboard->getLocsForCheck(std::get<Colour>(m_type));


	} 

}

