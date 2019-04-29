#include "../include/SFMLPrinter.h"

void SFMLPrinter::drawLossBoard(const std::array<std::array<int,6>, 2>& lb)
{
	mp_game->loadLossBoard(lb);
}

void SFMLPrinter::drawTimer(const std::array<clock::time_point, 2>& t)
{
	mp_game->updateTimer(t);
}

void SFMLPrinter::drawPlayerTurn(int i)
{
	mp_game->updatePlayerTurn(i);
}

void SFMLPrinter::drawTurnNumber(int i)
{
	mp_game->updateTurnNo(i);
}

void SFMLPrinter::drawPawn(Colour C)
{
	if(C == Colour::White)
		m_logic[m_currentSquarei][m_currentSquarej] = 5;
	else
		m_logic[m_currentSquarei][m_currentSquarej] = 11;
}

void SFMLPrinter::drawKing(Colour C)
{
	if(C == Colour::White)
		m_logic[m_currentSquarei][m_currentSquarej] = 0;
	else
		m_logic[m_currentSquarei][m_currentSquarej] = 6;
}

void SFMLPrinter::drawQueen(Colour C)
{
	if(C == Colour::White)
		m_logic[m_currentSquarei][m_currentSquarej] = 1;
	else
		m_logic[m_currentSquarei][m_currentSquarej] = 7;
}

void SFMLPrinter::drawKnight(Colour C)
{
	if(C == Colour::White)
		m_logic[m_currentSquarei][m_currentSquarej] = 3;
	else
		m_logic[m_currentSquarei][m_currentSquarej] = 9;
}

void SFMLPrinter::drawBishop(Colour C)
{
		if(C == Colour::White)
		m_logic[m_currentSquarei][m_currentSquarej] = 2;
	else
		m_logic[m_currentSquarei][m_currentSquarej] = 8;
}

void SFMLPrinter::drawRook(Colour C)
{
	if(C == Colour::White)
		m_logic[m_currentSquarei][m_currentSquarej] = 4;
	else
		m_logic[m_currentSquarei][m_currentSquarej] = 10;
}

void SFMLPrinter::startSquare(Location loc, bool selected)
{

	m_currentSquarei = static_cast<int>(std::get<Letter>(loc));
	m_currentSquarej = static_cast<int>(std::get<Number>(loc));

	m_logic[m_currentSquarei][m_currentSquarej] = -1;
	if(selected)
		m_selected[m_currentSquarei][m_currentSquarej] = true;
	else
		m_selected[m_currentSquarei][m_currentSquarej] = false;
		//mp_game->Board[m_currentSquare].select();

}

void SFMLPrinter::endSquare(Location loc)
{
	//m_currentSquare = -1;

}

void SFMLPrinter::startBoard()
{
	//mp_logic = ;

}

void SFMLPrinter::endBoard()
{

}

void SFMLPrinter::display(bool tick) const
{
	mp_game->loadImageBoard(m_logic);
	mp_game->selectSquares(m_selected);
	mp_game->display();
}

