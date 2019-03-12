#ifndef PRINTIMPL
#define PRINTIMPL

enum class InfoLoc{Top, Bottom, Left, Right};

#include "defs.h"
#include <chrono>

class PrintImpl
{
	using clock = std::chrono::high_resolution_clock;
public:
	PrintImpl(void) = default;

	virtual ~PrintImpl() = default;

	virtual void drawTimer(const std::array<clock::time_point, 2>& t) = 0;

	virtual void drawLossBoard(const std::array<std::array<int,6>, 2>& lb) = 0;

	virtual	void drawPlayerTurn(int i) = 0;

	virtual void drawTurnNumber(int i) = 0;

	virtual void drawPawn(Colour C) = 0;

	virtual void drawKing(Colour C) = 0;

	virtual void drawQueen(Colour C) = 0;

	virtual void drawKnight(Colour C) = 0;

	virtual void drawBishop(Colour C) = 0;

	virtual void drawRook(Colour C) = 0;

	virtual void startSquare(Location loc, bool selected) = 0;

	virtual void endSquare(Location loc) = 0;

	virtual void startBoard() = 0;

	virtual void endBoard() = 0;

	virtual void display(bool tick) const = 0;

};



#endif