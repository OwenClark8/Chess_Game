#include "../include/Knight.h"
#include "../include/Board.h"
#include "../include/Square.h"


void Knight::movePiece(Location loc)
{
	m_position = std::move(loc);
}


std::list<Location> Knight::getMovementOptions() const
{

	std::list<Location> locs;
	checkU(locs);
	checkL(locs);
	checkR(locs);
	checkD(locs);

	return locs;
}


void Knight::checkU(std::list<Location>& locs) const
{	
	if(std::get<Number>(m_position) != Number::Seven || std::get<Number>(m_position) != Number::Eight)
	{
		if(std::get<Letter>(m_position) != Letter::A)
		{

			auto u = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) + 2 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}


		if(std::get<Letter>(m_position) != Letter::H)
		{
			auto u = std::make_pair(std::get<Letter>(m_position) + 1, std::get<Number>(m_position) + 2 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}
		
	}
}

void Knight::checkD(std::list<Location>& locs) const
{
	if(std::get<Number>(m_position) != Number::One || std::get<Number>(m_position) != Number::Two)
	{
		if(std::get<Letter>(m_position) != Letter::A)
		{

			auto u = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) - 2 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}


		if(std::get<Letter>(m_position) != Letter::H)
		{
			auto u = std::make_pair(std::get<Letter>(m_position) + 1, std::get<Number>(m_position) - 2 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}
		
	}

}

void Knight::checkR(std::list<Location>& locs) const
{
	if(std::get<Letter>(m_position) != Letter::H || std::get<Letter>(m_position) != Letter::G)
	{
		if(std::get<Number>(m_position) != Number::Eight)
		{

			auto u = std::make_pair(std::get<Letter>(m_position) + 2, std::get<Number>(m_position) + 1 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}


		if(std::get<Number>(m_position) != Number::One)
		{
			auto u = std::make_pair(std::get<Letter>(m_position) + 2, std::get<Number>(m_position) - 1 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}
		
	}

}

void Knight::checkL(std::list<Location>& locs) const
{
	if(std::get<Letter>(m_position) != Letter::A || std::get<Letter>(m_position) != Letter::B)
	{
		if(std::get<Number>(m_position) != Number::Eight)
		{

			auto u = std::make_pair(std::get<Letter>(m_position) - 2, std::get<Number>(m_position) + 1 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}


		if(std::get<Number>(m_position) != Number::One)
		{
			auto u = std::make_pair(std::get<Letter>(m_position) - 2, std::get<Number>(m_position) - 1 );
			if(std::get<Piece>(mp_gameboard->getPiece(u)) == Piece::Empty || 
					std::get<Colour>(mp_gameboard->getPiece(u)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(u);
			}

		}
		
	}
}



void Knight::draw() const
{
	mp_Imp->drawKnight(std::get<Colour>(m_type));
}

