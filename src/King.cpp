#include "../include/King.h"
#include "../include/Board.h"
#include "../include/Square.h"
//NEED TO CODE ENPOISSANT REQUIR


void King::movePiece(Location position)
{
	m_position = std::move(position);
}

std::list<Location> King::getMovementOptions() const
{

	std::list<Location> locs;

	if(std::get<Number>(m_position) != Number::Eight)
	{
		
		auto x = std::make_pair(std::get<Letter>(m_position), std::get<Number>(m_position) + 1 );

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(x)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(x);
		}

		if(std::get<Letter>(m_position) != Letter::A)
		{
			auto xL = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) + 1 );

			if(std::get<Piece>(mp_gameboard->getPiece(xL)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(xL)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(xL);
			}
		}


		if(std::get<Letter>(m_position) != Letter::H)
		{
			auto xR = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) + 1 );

			if(std::get<Piece>(mp_gameboard->getPiece(xR)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(xR)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(xR);
			}
		}	
	}

	if(std::get<Number>(m_position) != Number::One)
	{
		
		auto x = std::make_pair(std::get<Letter>(m_position), std::get<Number>(m_position) - 1 );

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(x)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(x);
		}

		if(std::get<Letter>(m_position) != Letter::A)
		{
			auto xL = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) - 1 );

			if(std::get<Piece>(mp_gameboard->getPiece(xL)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(xL)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(xL);
			}
		}


		if(std::get<Letter>(m_position) != Letter::H)
		{
			auto xR = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) - 1 );

			if(std::get<Piece>(mp_gameboard->getPiece(xR)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(xR)) != std::get<Colour>(m_type))
			{
				locs.emplace_back(xR);
			}
		}	
	}

	if(std::get<Letter>(m_position) != Letter::A)
	{
		auto x = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position));

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(x)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(x);
		}
	}

	if(std::get<Letter>(m_position) != Letter::H)
	{
		auto x = std::make_pair(std::get<Letter>(m_position) + 1, std::get<Number>(m_position));

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty || 
				std::get<Colour>(mp_gameboard->getPiece(x)) != std::get<Colour>(m_type))
		{
			locs.emplace_back(x);
		}
	}

	//this->checkCastle(locs);

	return locs;
}

// void King::checkCastle(std::list<Location>& locs) const
// {

// }

void King::draw() const
{
	mp_Imp->drawKing(std::get<Colour>(m_type));
}


