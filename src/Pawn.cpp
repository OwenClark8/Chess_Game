#include "../include/Pawn.h"
#include "../include/Board.h"
#include "../include/Square.h"
//NEED TO CODE ENPOISSANT REQUIRES PREV MOVE
//

	
void Pawn::check2Ahead(std::list<Location>& l) const 
{
	if(!m_unused)
		return;

	if(std::get<Colour>(m_type) == Colour::White)
	{
		auto x = std::make_pair(std::get<Letter>(m_position), std::get<Number>(m_position) + 2 );

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty)
			l.emplace_back(x);
	}
	else
	{
		auto x = std::make_pair(std::get<Letter>(m_position), std::get<Number>(m_position) - 2 );

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty)
			l.emplace_back(x);
	}
	
	return;
}


void Pawn::check1Ahead(std::list<Location>& l) const
{
	if(std::get<Colour>(m_type) == Colour::White && std::get<Number>(m_position) != Number::Eight)
	{
		auto x = std::make_pair(std::get<Letter>(m_position), std::get<Number>(m_position) + 1 );

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty)
			l.emplace_back(x);
	}
	else if(std::get<Colour>(m_type) == Colour::Black && std::get<Number>(m_position) != Number::One)
	{
		auto x = std::make_pair(std::get<Letter>(m_position), std::get<Number>(m_position) - 1 );

		if(std::get<Piece>(mp_gameboard->getPiece(x)) == Piece::Empty)
			l.emplace_back(x);
	}

	return;
}


void Pawn::checkSides(std::list<Location>& l) const
{
	if(std::get<Colour>(m_type) == Colour::Black && std::get<Number>(m_position) == Number::One)
		return;

	if(std::get<Colour>(m_type) == Colour::White && std::get<Number>(m_position) == Number::Eight)
		return;

	if(std::get<Colour>(m_type) == Colour::White && std::get<Letter>(m_position) != Letter::A)
	{
		auto left  = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) + 1);
		if(std::get<Colour>(mp_gameboard->getPiece(left)) != std::get<Colour>(m_type))
		{
			if(std::get<Piece>(mp_gameboard->getPiece(left)) != Piece::Empty)
				l.emplace_back(std::move(left));
		}
	}

	if(std::get<Colour>(m_type) == Colour::Black && std::get<Letter>(m_position) != Letter::H)
	{
		auto left  = std::make_pair(std::get<Letter>(m_position) + 1, std::get<Number>(m_position) - 1);
		if(std::get<Colour>(mp_gameboard->getPiece(left)) != std::get<Colour>(m_type))
		{
			if(std::get<Piece>(mp_gameboard->getPiece(left)) != Piece::Empty)
				l.emplace_back(std::move(left));
		}
	}
	
	
	if(std::get<Colour>(m_type) == Colour::White && std::get<Letter>(m_position) != Letter::H)
	{
		auto right = std::make_pair(std::get<Letter>(m_position) + 1, std::get<Number>(m_position) + 1);
		if(std::get<Colour>(mp_gameboard->getPiece(right)) != std::get<Colour>(m_type))
		{
			if(std::get<Piece>(mp_gameboard->getPiece(right)) != Piece::Empty)
				l.emplace_back(std::move(right));
		}
	}

	if(std::get<Colour>(m_type) == Colour::Black && std::get<Letter>(m_position) != Letter::A)
	{
		auto right = std::make_pair(std::get<Letter>(m_position) - 1, std::get<Number>(m_position) - 1);
		if(std::get<Colour>(mp_gameboard->getPiece(right)) != std::get<Colour>(m_type))
		{
			if(std::get<Piece>(mp_gameboard->getPiece(right)) != Piece::Empty)
				l.emplace_back(std::move(right));
		}
	}
	
	return;
}

// use observer to check en poissant

// When pawn moves into 5 row add itself to approiprate other pawns to be notified of x2 move


void Pawn::checkEnPassant(std::list<Location>& l) const
{
	if(m_empassantcheck[0])
	{
		auto loc = std::get<Location>(m_empassantlocs[0]);
		int i = (std::get<Colour>(m_type) == Colour::White) ? 1 : -1;
		loc = std::make_pair(std::get<Letter>(loc), std::get<Number>(loc) + i);
		l.emplace_back(loc);
	}

	if(m_empassantcheck[1])
	{
		auto loc = std::get<Location>(m_empassantlocs[1]);
		int i = (std::get<Colour>(m_type) == Colour::White) ? 1 : -1;
		loc = std::make_pair(std::get<Letter>(loc), std::get<Number>(loc) + i);
		l.emplace_back(loc);
	}
}

std::list<Location> Pawn::getMovementOptions() const
{
	std::list<Location> locs;

	
	check2Ahead(locs);

	check1Ahead(locs);

	checkSides(locs);

	checkEnPassant(locs);

	return locs;
}

void Pawn::movePiece(Location position)
{

	if(std::get<Number>(position) == Number::Five && std::get<Colour>(m_type) == Colour::White)
	{
		auto leftpos = std::make_pair(std::get<Letter>(position) - 1, Number::Seven);
		auto left    = mp_gameboard->getPiece(leftpos);

		if(std::get<Piece>(left) == Piece::Pawn && std::get<Colour>(left) == Colour::Black)
		{
			mp_gameboard->pawnAttach(leftpos, position);
			m_empassantlocs.at(0) = {leftpos, true};
		}

		auto rightpos = std::make_pair(std::get<Letter>(position) + 1, Number::Seven);
		auto right    = mp_gameboard->getPiece(rightpos);

		if(std::get<Piece>(right) == Piece::Pawn && std::get<Colour>(right) == Colour::Black)
		{
			mp_gameboard->pawnAttach(rightpos, position);
			m_empassantlocs.at(1) = std::pair<Location, bool>{rightpos, true};
		}
	}
	else if(std::get<Number>(position) == Number::Four && std::get<Colour>(m_type) == Colour::Black)
	{
		auto leftpos = std::make_pair(std::get<Letter>(position) - 1, Number::Two);
		auto left    = mp_gameboard->getPiece(leftpos);

		if(std::get<Piece>(left) == Piece::Pawn && std::get<Colour>(left) == Colour::White)
		{
			mp_gameboard->pawnAttach(leftpos, position);
			m_empassantlocs.at(0) = std::pair<Location, bool>{leftpos, true};
		}

		auto rightpos = std::make_pair(std::get<Letter>(position) + 1, Number::Two);
		auto right    = mp_gameboard->getPiece(rightpos);

		if(std::get<Piece>(right) == Piece::Pawn && std::get<Colour>(right) == Colour::White)
		{
			mp_gameboard->pawnAttach(rightpos, position);
			m_empassantlocs.at(1) = std::pair<Location, bool>{rightpos, true};
		}
	}
	else
	{
		if(std::get<bool>(m_empassantlocs[0]))
		{
			mp_gameboard->pawnDetach(std::get<Location>(m_empassantlocs[0]), position);
			std::get<bool>(m_empassantlocs[0]) = false;
		}

		if(std::get<bool>(m_empassantlocs[1]))
		{
			mp_gameboard->pawnDetach(std::get<Location>(m_empassantlocs[1]), position);
			std::get<bool>(m_empassantlocs[1]) = false;
		}

		if(m_empassantcheck[0])
		{
			auto loc = std::get<Location>(m_empassantlocs[0]);

			mp_gameboard->empassantRemove(loc, {});

		}
		if(m_empassantcheck[1])
		{
			auto loc = std::get<Location>(m_empassantlocs[1]);

			mp_gameboard->empassantRemove(loc, {});
		}
	}

	if(abs(static_cast<int>(std::get<Number>(position)) - static_cast<int>(std::get<Number>(m_position))) == 2 )
	{
		m_position = std::move(position);
		this->notify();
	}
	else
	{
		m_position = std::move(position);
		for(auto& i : m_observers)
		{
			m_observers.erase(i);
		}
	}

	m_unused   = false;

	m_empassantcheck = std::array<bool,2>{false, false};

}

void Pawn::notify() const
{
	for(auto& i : m_observers)
	{
		i->update(m_position);
	}
}

void Pawn::update(const Location& L)
{
	if(static_cast<int>(std::get<Letter>(m_position)) - static_cast<int>(std::get<Letter>(L)) == -1)
	{
		std::get<Location>(m_empassantlocs[1]) = L;
		m_empassantcheck[1] = true;

	}
	else if(static_cast<int>(std::get<Letter>(m_position)) - static_cast<int>(std::get<Letter>(L)) == 1)
	{
		std::get<Location>(m_empassantlocs[0]) = L;
		m_empassantcheck[0] = true;
	}
}

void Pawn::draw() const
{
	mp_Imp->drawPawn(std::get<Colour>(m_type));
}

void Pawn::undoEmpassant(const Location& L)
{
	if(static_cast<int>(std::get<Letter>(m_position)) - static_cast<int>(std::get<Letter>(L)) == -1)
	{
		m_empassantlocs[0] = {L , true};
		m_empassantcheck[0] = true;

	}
	else if(static_cast<int>(std::get<Letter>(m_position)) - static_cast<int>(std::get<Letter>(L)) == 1)
	{
		m_empassantlocs[1] = {L , true};
		m_empassantcheck[1] = true;
	}
}



