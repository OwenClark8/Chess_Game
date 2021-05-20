#include "../include/King.h"
#include "../include/Board.h"
#include "../include/Square.h"
#include <algorithm>



void King::movePiece(Location position)
{
	m_position = std::move(position);
	m_unused = false;
}

void King::computeMove()
{
	//m_computeMove = true;
}

void King::getTrimmedMovements(std::list<Location>& locs, Colour c) const
{
	if(locs.empty())
		return;
	//m_movements   = locs;
	//m_computeMove = false;

	auto otherlocs = mp_gameboard->getLocsForCheck(std::get<Colour>(m_type), c);

	// std::remove_if(locs.begin(), locs.end(), [&otherlocs](Location l){
	// 	return (std::find(otherlocs.begin(), otherlocs.end(), l) != otherlocs.end());
	// });

	auto templocs = locs;
	auto rit = locs.begin();

	for(auto it = templocs.begin(); it != templocs.end(); ++it)
	{

		if(std::find(otherlocs.begin(), otherlocs.end(), *it) != otherlocs.end())
		{
			locs.erase(rit);
		}
		else
			++rit;
	}

}

std::list<Location> King::getMovementOptions(Colour c) const
{
	if(!m_computeMove)
		return m_movements;

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
			auto xR = std::make_pair(std::get<Letter>(m_position) + 1, std::get<Number>(m_position) + 1 );

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
			auto xR = std::make_pair(std::get<Letter>(m_position) + 1, std::get<Number>(m_position) - 1 );

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

	this->checkCastle(locs);

	this->getTrimmedMovements(locs, c);

	return locs;
}

void King::checkCastle(std::list<Location>& locs) const
{
	if(!m_unused)
		return;

	int i = 1;
	bool cont = true;
	while(cont)
	{
		auto left = std::make_pair(std::get<Letter>(m_position) - i, std::get<Number>(m_position) );

		if(!(std::get<Piece>(mp_gameboard->getPiece(left)) == Piece::Empty))
		{
			if(std::get<Piece>(mp_gameboard->getPiece(left)) == Piece::Rook && std::get<Letter>(left) == Letter::A)
			{
				locs.emplace_back(std::make_pair(std::get<Letter>(m_position) - 3, std::get<Number>(m_position)));
			}
			cont = false;
		}
		if(std::get<Letter>(left) == Letter::A)
			cont = false;
		++i;
	}

	i = 1;
	cont = true;
	while(cont)
	{
		auto right = std::make_pair(std::get<Letter>(m_position) + i, std::get<Number>(m_position));

		if(!(std::get<Piece>(mp_gameboard->getPiece(right)) == Piece::Empty))
		{
			if(std::get<Piece>(mp_gameboard->getPiece(right)) == Piece::Rook && std::get<Letter>(right) == Letter::H)
			{
				locs.emplace_back(std::make_pair(std::get<Letter>(m_position) + 2, std::get<Number>(m_position)));
			}
			cont = false;
		}
		if(std::get<Letter>(right) == Letter::H)
			cont = false;
		++i;
	}

}

void King::draw() const
{
	mp_Imp->drawKing(std::get<Colour>(m_type));
}


