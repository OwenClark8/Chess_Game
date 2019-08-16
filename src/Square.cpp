#include "../include/AbstractPiece.h"
#include "../include/Square.h"

void Square::addPiece(std::unique_ptr<AbstractPiece> P)
{
	mp_piece.reset(P.release());
	m_allocated = true;
	//mp_piece->movePiece(m_position);
}

void Square::movePieceIn(std::unique_ptr<AbstractPiece> P)
{
	mp_piece.reset(P.release());
	m_allocated = true;
	mp_piece->incrementMoveNo();
	mp_piece->movePiece(m_position);
}

void Square::removePiece()
{
	mp_piece.reset();
	m_allocated = false;
}

PieceType Square::getPieceType() const
{
	if(!m_allocated)
		return std::make_pair(Colour::White, Piece::Empty);

	return mp_piece->getPieceType();
}

std::unique_ptr<AbstractPiece> Square::movePieceOut()
{
	m_allocated = false;
	return std::unique_ptr<AbstractPiece>(mp_piece.release());
}

bool Square::isAllocated() const
{
	return m_allocated;
}

AbstractPiece* Square::getPieceHandle()
{
	if(!m_allocated)
		throw "Square not alocated";
	return mp_piece.get();
}

void Square::select()
{
	m_selected = true;
}

void Square::unselect()
{
	m_selected = false;
}

std::list<Location> Square::clicked() const
{
	if(m_allocated)
		return std::move(mp_piece->getMovementOptions(std::get<Colour>(mp_piece->getPieceType())));
	else
	{
		std::list<Location> loc = {};
		return std::move(loc);
	}
}

void Square::draw() const
{
	mp_Imp->startSquare(m_position, m_selected);

	if(m_allocated)
		mp_piece->draw();

	mp_Imp->endSquare(m_position);
	
}