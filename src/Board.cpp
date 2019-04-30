#include "../include/Board.h"
#include "../include/ObserverMapper.h"
#include "../include/Square.h"
#include "../include/Game.h"
#include "../include/GameBuilder.h"
#include "../include/LossBoard.h"
#include "../include/Pawn.h"


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

bool Board::selectSquare(const Location& i, const Colour& c)
{
	auto square = m_board.find(i);
	if(square == m_board.end())
		throw "invalid location";
	else
	{
		if(square->second->isAllocated())
		{
			if(std::get<Colour>(square->second->getPieceHandle()->getPieceType()) == c)
			{
				auto options = square->second->clicked();
				
				for(auto& o : options)
				{
					auto squareopt = m_board.find(o);
					if(squareopt == m_board.end())
						throw "invalid location";
					else
						squareopt->second->select();
				}
				square->second->select();
				return true;
			}
		}

		square->second->select();
		return false;
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

void Board::doMove(Move& mov,  Key<Game>)
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
			mov.m_moveNo = squarefrom->getPieceHandle()->getMoveNo();
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
		{
			squarefrom->movePieceIn(squareto->movePieceOut());
			squarefrom->getPieceHandle()->updateMoveNo(mov.m_moveNo);
		}
		else 
			throw "invlaid move";

		if(std::get<bool>(mov.m_lostPiece))
		{
			auto p = b.buildPiece(this, std::get<PieceType>(mov.m_lostPiece), std::get<1>(mov.m_move));
			p->updateMoveNo(mov.m_moveNo - 1);
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
		auto pawn1 = dynamic_cast<Pawn*>(square1it->second.get()->getPieceHandle());
		auto pawn2 = dynamic_cast<Pawn*>(square2it->second.get()->getPieceHandle());
		this->registerObsv(dynamic_cast<Subject<Location>*>(pawn1), dynamic_cast<Observer<Location>*>(pawn2));
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
		auto pawn1 = dynamic_cast<Pawn*>(square1it->second.get()->getPieceHandle());
		auto pawn2 = dynamic_cast<Pawn*>(square2it->second.get()->getPieceHandle());
		this->unregisterObsv(dynamic_cast<Subject<Location>*>(pawn1), dynamic_cast<Observer<Location>*>(pawn2));
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

void Board::empassantRemove(const Location& loc, Key<Pawn>)
{
	auto squareit = m_board.find(loc);

	if(squareit == m_board.end())
	{
		throw "invalid location 1";
	}
	else
	{
		auto square = squareit->second.get();	
		if(square->isAllocated())
		{
			mp_lossBoard->logPiece(square->getPieceType());
			square->movePieceOut();
		}
	}

}


