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
	SFMLPrinter(std::unique_ptr<SFMLPrintLib::Game> game) :mp_game(std::move(game))
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

	void display(bool tick) const override;


protected:

	std::unique_ptr<SFMLPrintLib::Game> mp_game;

	int m_currentSquare = -1;

};


#endif

