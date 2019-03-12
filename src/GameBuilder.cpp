#include "../include/GameBuilder.h"
#include "../include/Pawn.h"
#include "../include/King.h"
#include "../include/Queen.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rook.h"
#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/LossBoard.h"
#include "../include/Timer.h"


std::unique_ptr<Square> GameBuilder::buildSquare(Location l) const
{
	return std::unique_ptr<Square>(new Square(mp_print, l));
}

std::unique_ptr<Component> GameBuilder::buildBoard(LossBoard* lb) const
{
	return std::unique_ptr<Board>(new Board(mp_game, lb, mp_print));
}

std::unique_ptr<Pawn> GameBuilder::buildPawn(Board* b, Colour c, Location l) const
{
	return std::unique_ptr<Pawn>(new Pawn(b, c, l, mp_print));
}

std::unique_ptr<King> GameBuilder::buildKing(Board* b, Colour c, Location l) const
{
	return std::unique_ptr<King>(new King(b, c, l, mp_print));
}

std::unique_ptr<Queen> GameBuilder::buildQueen(Board* b, Colour c, Location l) const
{
	return std::unique_ptr<Queen>(new Queen(b, c, l, mp_print));
}

std::unique_ptr<Knight> GameBuilder::buildKnight(Board* b, Colour c, Location l) const
{
	return std::unique_ptr<Knight>(new Knight(b, c, l, mp_print));
}

std::unique_ptr<Rook> GameBuilder::buildRook(Board* b, Colour c, Location l) const
{
	return std::unique_ptr<Rook>(new Rook(b, c, l, mp_print));
}

std::unique_ptr<Bishop> GameBuilder::buildBishop(Board* b, Colour c, Location l) const
{
	return std::unique_ptr<Bishop>(new Bishop(b, c, l, mp_print));
}

std::unique_ptr<Component> GameBuilder::buildLossBoard() const
{
	return std::unique_ptr<LossBoard>(new LossBoard(mp_print));
}

std::unique_ptr<Component> GameBuilder::buildTimer(const std::chrono::minutes& min, const std::chrono::seconds& sec) const
{
	return std::unique_ptr<Timer>(new Timer(mp_print, min, sec));
}

std::unique_ptr<AbstractPiece> GameBuilder::buildPiece(Board* b, PieceType p, Location l) const
{
	switch(std::get<Piece>(p))
	{
		case Piece::Pawn:
			return buildPawn(b, std::get<Colour>(p), l);
			break;

		case Piece::King:
			return buildKing(b, std::get<Colour>(p), l);
			break;

		case Piece::Queen:
			return buildQueen(b, std::get<Colour>(p), l);
			break;

		case Piece::Knight:
			return buildKnight(b, std::get<Colour>(p), l);
			break;

		case Piece::Bishop:
			return buildBishop(b, std::get<Colour>(p), l);
			break;

		case Piece::Rook:
			return buildRook(b, std::get<Colour>(p), l);
			break;

		default:
			throw("Invalid piece type");
			break;
	}
}