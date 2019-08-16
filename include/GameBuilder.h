#ifndef GAMEBUILDERDEF
#define GAMEBUILDERDEF

#include "PrintImpl.h"
#include "Game.h"
#include "Component.h"

class Pawn;
class King;
class Queen;
class Rook;
class Knight;
class Bishop;
class AbstractPiece;
class Square;
class Board;
class LossBoard;
class Timer;

struct Move;

class GameBuilder
{
public:

	GameBuilder(Game* game, PrintImpl* pi) : mp_print(pi), mp_game(game)
	{};

	std::unique_ptr<AbstractPiece> buildPiece(Board* b, PieceType p, Location l) const;

	std::unique_ptr<Square> buildSquare(Location l) const;

	std::unique_ptr<Component> buildBoard(LossBoard* lb);

	std::unique_ptr<Component> buildLossBoard() const;

	std::unique_ptr<Component> buildTimer(const std::chrono::minutes& min, const std::chrono::seconds& sec) const;

private:

	std::unique_ptr<Pawn> buildPawn(Board* b, Colour c, Location l) const;
	std::unique_ptr<King> buildKing(Board* b, Colour c, Location l) const;
	std::unique_ptr<Queen> buildQueen(Board* b, Colour c, Location l) const;
	std::unique_ptr<Knight> buildKnight(Board* b, Colour c, Location l) const;
	std::unique_ptr<Bishop> buildBishop(Board* b, Colour c, Location l) const;
	std::unique_ptr<Rook> buildRook(Board* b, Colour c, Location l) const;

protected:
	
	PrintImpl* mp_print;
	Game*      mp_game;
};

#endif