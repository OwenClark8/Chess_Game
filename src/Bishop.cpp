#include "../include/Bishop.h"
#include "../include/Board.h"
#include "../include/Square.h"


void Bishop::movePiece(Location loc)
{
	m_position = std::move(loc);
}


std::list<Location> Bishop::getMovementOptions(Colour c) const
{

	std::list<Location> locs;
	checkULDiag(locs); 
	checkURDiag(locs); 
	checkLRDiag(locs); 
	checkLLDiag(locs); 

	this->TrimMovements(locs, c);

	return locs;

}

void Bishop::checkULDiag(std::list<Location>& locs) const
{
	auto u = m_position;

	while(std::get<Number>(u) != Number::Eight && std::get<Letter>(u) != Letter::A)
	{
		--std::get<Letter>(u);
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

void Bishop::checkURDiag(std::list<Location>& locs) const
{
	auto u = m_position;

	while(std::get<Number>(u) != Number::Eight && std::get<Letter>(u) != Letter::H)
	{
		++std::get<Letter>(u);
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
	return;
}

void Bishop::checkLRDiag(std::list<Location>& locs) const
{
	auto u = m_position;

	while(std::get<Number>(u) != Number::One && std::get<Letter>(u) != Letter::H)
	{
		++std::get<Letter>(u);
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

void Bishop::checkLLDiag(std::list<Location>& locs) const
{


	auto u = m_position;

	while(std::get<Number>(u) != Number::One && std::get<Letter>(u) != Letter::A)
	{
		--std::get<Letter>(u);
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

}




void Bishop::draw() const
{
	mp_Imp->drawBishop(std::get<Colour>(m_type));
}