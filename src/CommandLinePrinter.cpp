#include "../include/CommandLinePrinter.h" 





void CommandLinePrinter::drawLossBoard(const std::array<std::array<int,6>, 2>& lb)
{
	mp_game->Players[0].LostPieces = lb[0];
	mp_game->Players[1].LostPieces = lb[1];
	mp_game->updateLossBoard();
}

void CommandLinePrinter::drawTimer(const std::array<clock::time_point, 2>& t)
{
	mp_game->Players[0].TimeLeft = t[0];
	mp_game->Players[1].TimeLeft = t[1];

}

void CommandLinePrinter::drawPlayerTurn(int i)
{
	if(i == 0)
		mp_game->PlayerTurn = CommandLinePrintLib::Colour::White;
	else if(i == 1)
		mp_game->PlayerTurn = CommandLinePrintLib::Colour::Black;
	else
		throw "invalid colour";
}

void CommandLinePrinter::drawTurnNumber(int i) 
{
	mp_game->TurnNumber = i;
}

void CommandLinePrinter::drawPawn(Colour C)
{
	
	if(m_currentSquare == -1)
		throw "Square not initialised";

	CommandLinePrintLib::Colour c;
	if(C == Colour::Black)
		c = CommandLinePrintLib::Colour::Black;
	else
		c = CommandLinePrintLib::Colour::White;

	std::unique_ptr<CommandLinePrintLib::Piece> p(CommandLinePrintLib::makePawn(c)); 
	mp_game->Board[m_currentSquare].removePiece();

	//std::cout<<"Pawn at"<<m_currentSquare;
	mp_game->Board[m_currentSquare].addPiece(p.get());
}

void CommandLinePrinter::drawKing(Colour C)
{

	if(m_currentSquare == -1)
		throw "Square not initialised";

	CommandLinePrintLib::Colour c;
	if(C == Colour::Black)
		c = CommandLinePrintLib::Colour::Black;
	else
		c = CommandLinePrintLib::Colour::White;

	std::unique_ptr<CommandLinePrintLib::Piece> p(CommandLinePrintLib::makeKing(c)); 
	mp_game->Board[m_currentSquare].removePiece();
	mp_game->Board[m_currentSquare].addPiece(p.get());

}

void CommandLinePrinter::drawQueen(Colour C)
{

	if(m_currentSquare == -1)
		throw "Square not initialised";

	CommandLinePrintLib::Colour c;
	if(C == Colour::Black)
		c = CommandLinePrintLib::Colour::Black;
	else
		c = CommandLinePrintLib::Colour::White;

	std::unique_ptr<CommandLinePrintLib::Piece> p(CommandLinePrintLib::makeQueen(c)); 
	mp_game->Board[m_currentSquare].removePiece();
	mp_game->Board[m_currentSquare].addPiece(p.get());

}

void CommandLinePrinter::drawKnight(Colour C)
{

	if(m_currentSquare == -1)
		throw "Square not initialised";

	CommandLinePrintLib::Colour c;
	if(C == Colour::Black)
		c = CommandLinePrintLib::Colour::Black;
	else
		c = CommandLinePrintLib::Colour::White;

	std::unique_ptr<CommandLinePrintLib::Piece> p(CommandLinePrintLib::makeKnight(c)); 
	mp_game->Board[m_currentSquare].removePiece();
	mp_game->Board[m_currentSquare].addPiece(p.get());
}

void CommandLinePrinter::drawBishop(Colour C)
{

	if(m_currentSquare == -1)
		throw "Square not initialised";

	CommandLinePrintLib::Colour c;
	if(C == Colour::Black)
		c = CommandLinePrintLib::Colour::Black;
	else
		c = CommandLinePrintLib::Colour::White;

	std::unique_ptr<CommandLinePrintLib::Piece> p(CommandLinePrintLib::makeBishop(c));
	mp_game->Board[m_currentSquare].removePiece(); 
	mp_game->Board[m_currentSquare].addPiece(p.get());
}

void CommandLinePrinter::drawRook(Colour C) 
{

	if(m_currentSquare == -1)
		throw "Square not initialised";

	CommandLinePrintLib::Colour c;
	if(C == Colour::Black)
		c = CommandLinePrintLib::Colour::Black;
	else
		c = CommandLinePrintLib::Colour::White;

	std::unique_ptr<CommandLinePrintLib::Piece> p(CommandLinePrintLib::makeRook(c)); 
	mp_game->Board[m_currentSquare].removePiece();
	mp_game->Board[m_currentSquare].addPiece(p.get());
}

void CommandLinePrinter::startSquare(Location loc, bool selected) 
{
	int i = static_cast<int>(std::get<Letter>(loc));
	int j = static_cast<int>(std::get<Number>(loc));

	m_currentSquare = i + 8 * j;
	mp_game->Board[m_currentSquare].removePiece();
	mp_game->Board[m_currentSquare].unselect();
	if(selected)
		mp_game->Board[m_currentSquare].select();
	//std::cout << "Current square = " << m_currentSquare;
}

void CommandLinePrinter::endSquare(Location loc) 
{
	//mp_game->Board[m_currentSquare].select();
	m_currentSquare = -1;
}

void CommandLinePrinter::startBoard() 
{
	m_currentSquare = -1;

}

void CommandLinePrinter::endBoard() 
{

}

void CommandLinePrinter::display(bool tick) const
{

	CommandLinePrintLib::printGame(mp_game.get(), tick);

}

void CommandLinePrinter::drawCheck(Colour c, bool b)
{

}

void CommandLinePrinter::drawLossMessage(Colour c)
{
	
}