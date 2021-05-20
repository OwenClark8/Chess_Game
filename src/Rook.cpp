#include "../include/Rook.h"
#include "../include/Board.h"
#include "../include/Square.h"


void Rook::movePiece(Location loc)
{
	m_position = std::move(loc);
}


std::list<Location> Rook::getMovementOptions(Colour c) const
{

	std::list<Location> locs;
	checkU(locs); 
	checkR(locs); 
	checkL(locs); 
	checkD(locs); 

	this->TrimMovements(locs, c);

	return locs;

}

void Rook::checkU(std::list<Location>& locs) const
{
	auto u = m_position;

	while(std::get<Number>(u) != Number::Eight)
	{
		++std::get<Number>(u);

		if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty)
			locs.emplace_back(u);
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(u);
			return;
		}
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) == std::get<Colour>(m_type))
			return;

	}
}

void Rook::checkR(std::list<Location>& locs) const
{
	auto u = m_position;

	while(std::get<Letter>(u) != Letter::H)
	{
		++std::get<Letter>(u);

		if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty)
			locs.emplace_back(u);
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(u);
			return;
		}
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) == std::get<Colour>(m_type))
			return;
	}
	return;
}

void Rook::checkD(std::list<Location>& locs) const
{
	auto u = m_position;

	while(std::get<Number>(u) != Number::One)
	{
		--std::get<Number>(u);

		if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty)
			locs.emplace_back(u);
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(u);
			return;
		}
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) == std::get<Colour>(m_type))
			return;
	}
	return;
}

void Rook::checkL(std::list<Location>& locs) const
{


	auto u = m_position;

	while(std::get<Letter>(u) != Letter::A)
	{
		--std::get<Letter>(u);
		

		if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty)
			locs.emplace_back(u);
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(u);
			return;
		}
		else if(std::get<Colour>(mp_gameboard->getPiece(u)) == std::get<Colour>(m_type))
			return;
	}

}




void Rook::draw() const
{
	mp_Imp->drawRook(std::get<Colour>(m_type));
}