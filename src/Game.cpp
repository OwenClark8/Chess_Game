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

	mp_Imp->display(m_tick);
}

void Game::implementCommand(const Command& com)
{
	auto b = m_Comps.find(ComponentType::Board);
	if(b == m_Comps.end())
		throw "No board initialised";

	auto c = dynamic_cast<Board*>(b->second.get());
	c->unselectAll();

	switch(com.m_comType)
	{
		case CommandType::Selection:
		{	
			if(!std::get<bool>(m_lastClick))
			{
				if(c->selectSquare(com.m_action.select, m_playerTurn))
					m_lastClick = std::make_pair(com.m_action.select, true);
				break;
			}
			else if(!c->checkMove(std::get<Location>(m_lastClick), com.m_action.select))
			{
				m_lastClick = std::make_pair(Location(), false);
				this->implementCommand(com);
				break;
			}
			auto newCommand = std::make_unique<Command>(Command{});
			newCommand->m_action.move = std::make_pair(std::get<Location>(m_lastClick), com.m_action.select);
			newCommand->m_comType     = CommandType::Movement;
			this->implementCommand(*newCommand.get());
			break;
		}
			
		case CommandType::Movement:
		{
			auto oritype = c->getPiece(std::get<0>(com.m_action.move));
			auto type = c->getPiece(std::get<1>(com.m_action.move));
			
			if(m_playerTurn != std::get<Colour>(oritype))
				throw "Invalid move";

			if(!c->checkMove(std::get<0>(com.m_action.move), std::get<1>(com.m_action.move)))
				throw "Invalid move";

			if(m_currentmove < m_moves.size() && !m_moves.empty())
			{
				auto it = m_moves.cbegin();
				std::advance(it, m_currentmove);
				m_moves.erase(it, m_moves.cend());
			}

	

			if(std::get<Piece>(type) == Piece::Empty)
			{
				auto mov = Move(com.m_action.move, std::make_tuple(false, type, 0));
				m_moves.push_back(Move());
				c->doMove(mov, {});
				m_moves[m_moves.size() - 1].m_move = mov.m_move;
				m_moves[m_moves.size() - 1].m_castle = mov.m_castle;
				m_moves[m_moves.size() - 1].m_moveNo = mov.m_moveNo;
				
				// if(m_moves.size() != 1)
				// 	++m_currentmove;
			}
			else
			{
				auto mov = Move(com.m_action.move, std::make_tuple(true, type, 0));
				c->doMove(mov, {});
				m_moves.push_back(mov);
				// if(m_moves.size() != 1)
				// 	++m_currentmove;
			}
			//Handle castling 
			if(std::get<Piece>(oritype) == Piece::King && std::get<Letter>(std::get<0>(com.m_action.move)) == Letter::E)
			{
				if(std::get<Letter>(std::get<1>(com.m_action.move)) == Letter::B)
				{
					auto num = (m_playerTurn == Colour::White) ? Number::One : Number::Eight;
					auto rookfrom = std::make_pair(Letter::A, num);
					auto rookto   = std::make_pair(Letter::C, num);
					//c->updateBoard(rookfrom, rookto);
					
					auto mov = Move(std::make_pair(rookfrom, rookto), std::make_tuple(false, type, 0));
					mov.m_castle = true;
					c->doMove(mov, {});
					m_moves[m_moves.size() -1].m_castle = true;
					m_moves.push_back(mov);
					++m_currentmove;

				}

				if(std::get<Letter>(std::get<1>(com.m_action.move)) == Letter::G)
				{
					auto num = (m_playerTurn == Colour::White) ? Number::One : Number::Eight;
					auto rookfrom = std::make_pair(Letter::H, num);
					auto rookto   = std::make_pair(Letter::F, num);
					//c->updateBoard(rookfrom, rookto);

					auto mov = Move(std::make_pair(rookfrom, rookto), std::make_tuple(false, type, 0));
					mov.m_castle = true;
					m_moves[m_moves.size() -1].m_castle = true;
					c->doMove(mov, {});
					m_moves.push_back(mov);
					++m_currentmove;
				}
			}
			//c->updateBoard(std::get<0>(com.m_action.move), std::get<1>(com.m_action.move));

			
			this->turnSwitch();
			m_lastClick = std::make_pair(Location(), false);
			break;
		}
		case CommandType::Info:
		{
			auto b = m_Comps.find(ComponentType::Info);
			if(b != m_Comps.end())
				b->second->draw();
			else
				throw "Info unavailable";
			m_lastClick = std::make_pair(Location(), false);
			break;
		}
		case CommandType::StateChange:
		{
			this->implementStateChange(com.m_action.changeState);
			m_lastClick = std::make_pair(Location(), false);
			break;
		}	
	}
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
	else if(s == State::Restart)
	{
		this->restart();
	}

}

void Game::undo()
{
	if(m_currentmove <=  0)
		return;

	auto b = m_Comps.find(ComponentType::Board);

	if(b == m_Comps.end())
		throw "Board not initialised";

	auto c = dynamic_cast<Board*>(b->second.get());
	//auto p = std::find(m_moves.cbegin(), m_moves.cend(), m_currentmove);

	//c->updateBoard(std::get<0>(m_currentmove.m_move), std::get<1>(m_currentmove.m_move));
	c->undoMove(m_moves.at(--m_currentmove), GameBuilder(this, mp_Imp), {});
	
	if(m_currentmove != 0)
	{
		if(m_moves.at(m_currentmove -1 ).m_castle)
		{
			//--m_currentmove;
			this->undo();
		}
	}

	if(m_playerTurn == Colour::White)
	{
		m_playerTurn = Colour::Black;
	}
	else
	{
		m_playerTurn = Colour::White;
	}

}

void Game::redo()
{
	if(m_currentmove >= m_moves.size())
		return;

	auto b = m_Comps.find(ComponentType::Board);
	if(b == m_Comps.end())
		throw "Board not initialised";

	auto c = dynamic_cast<Board*>(b->second.get());
	//auto p = std::find(m_moves.cbegin(), m_moves.cend(), m_currentmove);

	//c->updateBoard(std::get<0>(m_currentmove.m_move), std::get<1>(m_currentmove.m_move));
	c->doMove(m_moves.at(m_currentmove), {});

	if(m_moves.at(m_currentmove + 1).m_castle)
	{
		++m_currentmove;
		this->redo();
	}
	++m_currentmove;
	if(m_playerTurn == Colour::White)
	{
		m_playerTurn = Colour::Black;
	}
	else
	{
		m_playerTurn = Colour::White;
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
	if(t == m_Comps.end())
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

	auto b = m_Comps.find(ComponentType::Board);
	if(b == m_Comps.end())
		throw "Board not initialised";

	auto c = dynamic_cast<Board*>(b->second.get());

	if(c->inCheck(m_playerTurn))
	{
		if(m_playerTurn == Colour::White)
			std::cout<<"Black in check";
		else
			std::cout<<"White in check";
	}
	
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
	//++m_currentmove;

}

void Game::checkMate(Colour c)
{
	if(c == Colour::White)
		std::cout<<"White wins";
	else
		std::cout<<"Black wins";

}

void Game::restart()
{
	m_Comps.clear();

	m_moves = {};

	m_currentmove = 0;

	m_playerTurn = Colour::White;

	m_tick = true;

	m_lastClick = std::make_pair(Location(), false); 

	GameBuilder builder(this, mp_Imp);

	this->createNewGame(builder);

}

void Game::logEnpassant(int moveNo, Key<Board>)
{
	m_moves[m_moves.size() -1].m_enpassant = true;

	auto c = (m_playerTurn == Colour::White) ? Colour::Black : Colour::White;
	m_moves[m_moves.size() -1].m_lostPiece = std::make_tuple(true, std::make_pair(c, Piece::Pawn), moveNo);

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