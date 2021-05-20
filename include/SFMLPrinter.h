#ifndef SFMLPRINTERDEF
#define SFMLPRINTERDEF

#include "PrintImpl.h"
#include "SFMLPrintLib.h"

// using PiecePrototype = std::pair<std::vector<std::string>, std::vector<std::array<int, 2>>>;
// using SquarePrtotype = std::pair<std::vector<std::string>, Colour>;

class SFMLPrinter : public PrintImpl
{
	using clock = std::chrono::high_resolution_clock;
public:
	SFMLPrinter(SFMLLib::SFMLGame* game) :mp_game(std::move(game))
	{};

	~SFMLPrinter() = default;

	void drawLossBoard(const std::array<std::array<int,6>, 2>& lb) override;

	void drawTimer(const std::array<clock::time_point, 2>& t) override;

	void drawPlayerTurn(int i) override;

	void drawTurnNumber(int i) override;

	void drawPawn(Colour C) override;

	void drawKing(Colour C) override;

	void drawQueen(Colour C) override;

	void drawKnight(Colour C) override;

	void drawBishop(Colour C) override;

	void drawRook(Colour C) override;

	void startSquare(Location loc, bool selected) override;

	void endSquare(Location loc) override;

	void startBoard() override;

	void endBoard() override;

	void drawCheck(Colour c, bool b) override;

	void drawLossMessage(Colour c) override;

	void display(bool tick) const override;


protected:

	SFMLLib::SFMLGame* mp_game;

	int m_currentSquarei = -1;
	int m_currentSquarej = -1;

	std::array<std::array<int, 8>, 8> m_logic;
	std::array<std::array<bool, 8>, 8> m_selected;

};


#endif

