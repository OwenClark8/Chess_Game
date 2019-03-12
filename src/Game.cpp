#include "../include/Game.h"
#include "../include/Board.h"
#include "../include/LossBoard.h"
#include "../include/GameBuilder.h"
#include "../include/Square.h"
#include "../include/Timer.h"
#include <iterator>



void Game::addComponent(ComponentType ct, std::unique_ptr<Component> comp)
{
	m_Comps.emplace(ct, std::move(comp));
}

void Game::removeComponent(ComponentType ct)
{
	for(auto& it : m_Comps)
	{
		if(it.first == ct)
		{
			m_Comps.erase(ct);
		}
	}
}

void Game::createNewGame(const GameBuilder& builder)
{
	
	auto lb = builder.buildLossBoard();

	auto pointerlb = lb.get();

	addComponent(ComponentType::LossBoard, std::move(lb));

	auto time = builder.buildTimer(std::chrono::minutes(30),  std::chrono::seconds(0));

	addComponent(ComponentType::Timer, std::move(time));

	auto b = builder.buildBoard(dynamic_cast<LossBoard*>(pointerlb));

	auto board = dynamic_cast<Board*>(b.get());

	Location loc = std::make_pair(Letter::A, Number::One);
	
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Rook), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Knight), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Bishop), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Queen), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::King), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Bishop), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Knight), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Rook), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	++std::get<Number>(loc);

	{
		for(int j = 0 ; j < 8; ++j)
		{
			
			std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
			square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::White, Piece::Pawn), loc)));
			board->addSquare(loc, std::move(square));
			++std::get<Letter>(loc);
		}
		std::get<Letter>(loc) == Letter::A;
		++std::get<Number>(loc);
	}


	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0 ; j < 8; ++j)
		{
			std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
			board->addSquare(loc, std::move(square));
			++std::get<Letter>(loc);
		}
		std::get<Letter>(loc) == Letter::A;
		++std::get<Number>(loc);
	}

	
	{
		for(int j = 0 ; j < 8; ++j)
		{
			std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
			square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Pawn), loc)));
			board->addSquare(loc, std::move(square));
			++std::get<Letter>(loc);
		}
		std::get<Letter>(loc) == Letter::A;
		++std::get<Number>(loc);
	}

	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Rook), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Knight), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Bishop), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Queen), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::King), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Bishop), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Knight), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}
	{
		std::unique_ptr<Square> square(std::move(builder.buildSquare(loc)));
		square->addPiece(std::move(builder.buildPiece(board, std::make_pair(Colour::Black, Piece::Rook), loc)));
		board->addSquare(loc, std::move(square));
		++std::get<Letter>(loc);
	}

	addComponent(ComponentType::Board, std::move(b));

	addComponent(ComponentType::LossBoard, builder.buildLossBoard());
}

void Game::deleteGame()
{
	for(auto& i : m_Comps)
	{
		m_Comps.erase(i.first);
	}
}

void Game::draw() const
{
	mp_Imp->drawPlayerTurn(static_cast<int>(m_playerTurn));
	mp_Imp->drawTurnNumber(m_currentmove);

	for(auto& comp : m_Comps)
	{
		comp.second->draw();
	}

	mp_Imp->display(true);
}

void Game::implementCommand(const Command& com)
{
	auto b = m_Comps.find(ComponentType::Board);
	if(b != m_Comps.end())
	{
		auto c = dynamic_cast<Board*>(b->second.get());
		c->unselectAll();

		switch(com.m_comType)
		{
			case CommandType::Selection:
			{	
				c->selectSquare(com.m_action.select);
				break;
			}
				
			case CommandType::Movement:
			{
				auto type = c->getPiece(std::get<1>(com.m_action.move));
				
				if(m_playerTurn != std::get<Colour>(c->getPiece(std::get<0>(com.m_action.move))))
					throw "Invalid move";

				if(!c->checkMove(std::get<0>(com.m_action.move), std::get<1>(com.m_action.move)))
					throw "Invalid move";

				if(m_currentmove < m_moves.size() && !m_moves.empty())
				{
					auto it = m_moves.cbegin();
					std::advance(it, m_currentmove + 1);
					m_moves.erase(it, m_moves.cend());
				}

				if(std::get<Piece>(type) == Piece::Empty)
				{
					m_moves.push_back(Move(com.m_action.move, std::make_pair(false, type)));
					if(m_moves.size() != 1)
						++m_currentmove;
				}
				else
				{
					m_moves.push_back(Move(com.m_action.move, std::make_pair(true, type)));
					if(m_moves.size() != 1)
						++m_currentmove;
				}
				c->updateBoard(std::get<0>(com.m_action.move), std::get<1>(com.m_action.move));
				
				this->turnSwitch();
				break;
			}
			case CommandType::Info:
			{
				auto b = m_Comps.find(ComponentType::Info);
					if(b != m_Comps.end())
						b->second->draw();
					else
						throw "Info unavailable";
					break;
			}
			case CommandType::StateChange:
			{
				this->implementStateChange(com.m_action.changeState);
				break;
			}	
		}
	}
	else
		throw "No board initialised";
	

}

void Game::implementStateChange(const State& s)
{
	if(s == State::Undo)
	{
		this->undo();
	}
	else if(s == State::Redo)
	{
		this->redo();
	}

}

void Game::undo()
{
	if(m_currentmove < 0)
		return;
	else
	{
		auto b = m_Comps.find(ComponentType::Board);
		if(b != m_Comps.end())
		{
			auto c = dynamic_cast<Board*>(b->second.get());
			//auto p = std::find(m_moves.cbegin(), m_moves.cend(), m_currentmove);

			//c->updateBoard(std::get<0>(m_currentmove.m_move), std::get<1>(m_currentmove.m_move));
			c->undoMove(m_moves.at(m_currentmove), GameBuilder(this, mp_Imp), {});
			if(m_currentmove != 0)
				--m_currentmove;
		}
		else
			throw "Board not initialised";
	}

}

void Game::redo()
{
	if(m_currentmove >= m_moves.size() - 1)
		return;
	else
	{
		auto b = m_Comps.find(ComponentType::Board);
		if(b != m_Comps.end())
		{
			auto c = dynamic_cast<Board*>(b->second.get());
			//auto p = std::find(m_moves.cbegin(), m_moves.cend(), m_currentmove);

			//c->updateBoard(std::get<0>(m_currentmove.m_move), std::get<1>(m_currentmove.m_move));
			c->doMove(m_moves.at(++m_currentmove), GameBuilder(this, mp_Imp), {});
			//++m_currentmove;
		}
		else
			throw "Board not initialised";
		
	}

}

void Game::storeMove(Move mov)
{
	m_moves.push_back(std::move(mov));
}

void Game::turnSwitch()
{

	++m_currentmove;

	auto t = m_Comps.find(ComponentType::Timer);
	if(t != m_Comps.end())
	{
		auto timer = dynamic_cast<Timer*>(t->second.get());

		if(m_playerTurn == Colour::White)
		{
			m_playerTurn = Colour::Black;
			timer->startTimer(Colour::Black);
			timer->stopTimer(Colour::White);
		}
		else
		{
			m_playerTurn = Colour::White;
			timer->startTimer(Colour::White);
			timer->stopTimer(Colour::Black);
		}
		
	}
	else
	{
		if(m_playerTurn == Colour::White)
		{
			m_playerTurn = Colour::Black;
		}
		else
		{
			m_playerTurn = Colour::White;
		}
		
	}
	++m_currentmove;

}



Location strToLoc(const std::string& str)
{
	if(str.size() !=2)
		throw "Wrong size";

	Letter l;

	if(str.substr(0,1) == "A")
		l = Letter::A;
	else if(str.substr(0,1) == "B")
		l = Letter::B;
	else if(str.substr(0,1) == "C")
		l = Letter::C;
	else if(str.substr(0,1) == "D")
		l = Letter::D;
	else if(str.substr(0,1) == "E")
		l = Letter::E;
	else if(str.substr(0,1) == "F")
		l = Letter::F;
	else if(str.substr(0,1) == "G")
		l = Letter::G;
	else if(str.substr(0,1) == "H")
		l = Letter::H;
	else
		throw "Invalid letter";

	Number n;


	if(str.substr(1,1) == "1")
		n = Number::One;
	else if(str.substr(1,1) == "2")
		n = Number::Two;
	else if(str.substr(1,1) == "3")
		n = Number::Three;
	else if(str.substr(1,1) == "4")
		n = Number::Four;
	else if(str.substr(1,1) == "5")
		n = Number::Five;
	else if(str.substr(1,1) == "6")
		n = Number::Six;
	else if(str.substr(1,1) == "7")
		n = Number::Seven;
	else if(str.substr(1,1) == "8")
		n = Number::Eight;
	else
		throw "Invalid number";

	return std::make_pair(l, n);
}





std::unique_ptr<Command> makeCommand(const std::string& s)
{

	auto newCommand = std::make_unique<Command>(Command{});
	auto s1 = s;

	if(s == "Resign")
	{
		newCommand->m_comType            = CommandType::StateChange;
		newCommand->m_action.changeState = State::Resign;
	}
	else if(s == "Info")
	{
		newCommand->m_comType = CommandType::Info;
		//newCommand->m_action.State = State::Info
	}
	else if(s == "Restart")
	{
		newCommand->m_comType            = CommandType::StateChange;
		newCommand->m_action.changeState = State::Restart;
	}
	else if(s == "Undo")
	{
		newCommand->m_comType		     = CommandType::StateChange;
		newCommand->m_action.changeState = State::Undo;
	}
	else if(s == "Redo")
	{
		newCommand->m_comType		     = CommandType::StateChange;
		newCommand->m_action.changeState = State::Redo;
	}
	else if(s.size() == 2)
	{
		newCommand->m_action.select = strToLoc(s);
		newCommand->m_comType       = CommandType::Selection;
	}
	else if(s.find("->") != std::string::npos)
	{
		if(s.size() != 6)
			throw "Invalid command";
		auto loc = std::make_pair(strToLoc(s.substr(0,2)), strToLoc(s.substr(4,2)));
		newCommand->m_action.move = loc;
		newCommand->m_comType       = CommandType::Movement;
	}
	else
		throw "Invalid Command";


	return newCommand;
}