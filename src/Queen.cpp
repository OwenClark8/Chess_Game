#include "../include/Queen.h"
#include "../include/Board.h"
#include "../include/Square.h"


void Queen::movePiece(Location loc)
{
	m_position = std::move(loc);
}


std::list<Location> Queen::getMovementOptions(Colour c) const
{

	std::list<Location> locs;
	checkULDiag(locs); 
	checkURDiag(locs); 
	checkLRDiag(locs); 
	checkLLDiag(locs); 
	checkU(locs); 
	checkR(locs); 
	checkL(locs); 
	checkD(locs); 

	this->TrimMovements(locs, c);

	return locs;

}

void Queen::checkULDiag(std::list<Location>& locs) const
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
	return;
}

void Queen::checkURDiag(std::list<Location>& locs) const
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

void Queen::checkLRDiag(std::list<Location>& locs) const
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

void Queen::checkLLDiag(std::list<Location>& locs) const
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


void Queen::checkU(std::list<Location>& locs) const
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

void Queen::checkR(std::list<Location>& locs) const
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

void Queen::checkD(std::list<Location>& locs) const
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

void Queen::checkL(std::list<Location>& locs) const
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




void Queen::draw() const
{
	mp_Imp->drawQueen(std::get<Colour>(m_type));
}