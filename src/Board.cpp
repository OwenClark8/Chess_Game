#include "../include/Board.h"
#include "../include/ObserverMapper.h"
#include "../include/Square.h"
#include "../include/Game.h"
#include "../include/GameBuilder.h"
#include "../include/LossBoard.h"


// Board::Board(const Board& otherboard)
// {
// 	m_board = otherboard.m_board;
// }

PieceType Board::getPiece(const Location& i) const
{
	auto square = m_board.find(i);
	if(square == m_board.end())
		throw "invalid location";
	else
	{
		return square->second->getPieceType();
	}
}

void Board::selectSquare(const Location& i)
{
	auto square = m_board.find(i);
	if(square == m_board.end())
		throw "invalid location";
	else
	{
		if(square->second->isAllocated())
		{
			auto options = square->second->clicked();
			square->second->select();

			for(auto& o : options)
			{
				auto squareopt = m_board.find(o);
				if(squareopt == m_board.end())
					throw "invalid location";
				else
					squareopt->second->select();
			}
		}
	}

}

bool Board::checkMove(const Location& movefrom, const Location& moveto) const
{
	auto squarefromit = m_board.find(movefrom);
	auto squaretoit   = m_board.find(moveto);
	if(squarefromit == m_board.end())
	{
		throw "invalid move from location";
	}
	else if (squaretoit == m_board.end())
	{
		throw "invalid move to location ";
	}
	else
	{
		auto squarefrom = squarefromit->second.get();
		auto squareto   = squaretoit->second.get();

		if(squarefrom->isAllocated())
		{
			auto opt = squarefrom->getPieceHandle()->getMovementOptions();
			for(auto& i: opt)
			{
				if(i == moveto)
					return true;
			}
		}
		else
			throw "invalid move";

	}
	return false;
}

void Board::unselectAll()
{
	for(auto& it: m_board)
	{
		it.second->unselect();
	}
}

void Board::updateBoard(const Location& movefrom, const Location& moveto)
{

	auto squarefromit = m_board.find(movefrom);
	auto squaretoit   = m_board.find(moveto);
	if(squarefromit == m_board.end())
	{
		throw "invalid move from location";
	}
	else if (squaretoit == m_board.end())
	{
		throw "invalid move to location ";
	}
	else
	{
		// Move cMove;
		// cMove.m_move = std::make_pair(movefrom, moveto);

		auto squarefrom = squarefromit->second.get();
		auto squareto   = squaretoit->second.get();

		// if(squareto->isAllocated())
		// 	cMove.m_lostPiece = std::make_pair(true, squareto->getPieceType());
		// else
		//	std::get<bool>(cMove.m_lostPiece) = false;
		//mp_game->storeMove(cMove);
		//m_currentMove = cMove; 
		if(squarefrom->isAllocated())
		{
			if(squareto->isAllocated())
				mp_lossBoard->logPiece(squareto->getPieceType());

			squareto->movePieceIn(squarefrom->movePieceOut());
		}
		else
			throw "invalid move";
	}

}

void Board::doMove(const Move& mov, const GameBuilder& b, Key<Game>)
{
	auto squarefromit = m_board.find(std::get<0>(mov.m_move));
	auto squaretoit   = m_board.find(std::get<1>(mov.m_move));
	if(squarefromit == m_board.end())
	{
		throw "invalid move from location";
	}
	else if (squaretoit == m_board.end())
	{
		throw "invalid move to location ";
	}
	else
	{
		auto squarefrom = squarefromit->second.get();
		auto squareto   = squaretoit->second.get();

		if(squarefrom->isAllocated())
		{
			if(squareto->isAllocated())
				mp_lossBoard->logPiece(squareto->getPieceType());

			squareto->movePieceIn(squarefrom->movePieceOut());
		}
		else
			throw "invalid move";

	}
}

void Board::undoMove(const Move& mov, const GameBuilder& b, Key<Game>)
{
	auto squarefromit = m_board.find(std::get<0>(mov.m_move));
	auto squaretoit   = m_board.find(std::get<1>(mov.m_move));
	if(squarefromit == m_board.end())
	{
		throw "invalid move from location";
	}
	else if (squaretoit == m_board.end())
	{
		throw "invalid move to location ";
	}
	else
	{
		auto squarefrom = squarefromit->second.get();
		auto squareto   = squaretoit->second.get();

		if(squareto->isAllocated())
			squarefrom->movePieceIn(squareto->movePieceOut());
		else 
			throw "invlaid move";

		if(std::get<bool>(mov.m_lostPiece))
		{
			auto p = b.buildPiece(this, std::get<PieceType>(mov.m_lostPiece), std::get<1>(mov.m_move));
			squareto->movePieceIn(std::move(p));
			mp_lossBoard->unlogPiece(std::get<PieceType>(mov.m_lostPiece));
		}
	}
	
}

void Board::addSquare(Location loc, std::unique_ptr<Square> sqr)
{
	m_board.emplace(std::move(loc), std::move(sqr));
}

void Board::removeSquare(const Location& loc)
{
	m_board.erase(loc);
}

void Board::pawnAttach(const Location& loc1, const Location& loc2)
{
	auto square1it = m_board.find(loc1);
	auto square2it = m_board.find(loc2);
	if(square1it == m_board.end())
	{
		throw "invalid location 1";
	}
	else if (square2it == m_board.end())
	{
		throw "invalid location 2";
	}
	else
	{
		auto square1 = square1it->second.get();
		auto square2 = square2it->second.get();
		//this->registerObsv(square1->getPieceHandle(), square2->getPieceHandle());
	}

}

void Board::pawnDetach(const Location& loc1, const Location& loc2)
{
	auto square1it = m_board.find(loc1);
	auto square2it = m_board.find(loc2);
	if(square1it == m_board.end())
	{
		throw "invalid location 1";
	}
	else if (square2it == m_board.end())
	{
		throw "invalid location 2";
	}
	else
	{
		auto square1 = square1it->second.get();
		auto square2 = square2it->second.get();
		//this->unregisterObsv(square1->getPieceHandle(), square2->getPieceHandle());
	}

}

void Board::draw() const
{
	mp_Imp->startBoard();

	for(auto& comp : m_board)
	{
		comp.second->draw();
	}
	
	mp_Imp->endBoard();
}


