#ifndef BOARDDEF
#define BOARDDEF

#include <iostream>
#include "Component.h"
#include "ObserverMapper.h"
#include "Square.h"
#include "Key.h"

class GameBuilder;
class Game;
class LossBoard;
class Pawn;

/* Needs to be able to restore enpassant links */
struct Move{
	Move(const std::pair<Location, Location>& m, const std::tuple<bool, PieceType, int>& lp):
		m_move(m), m_lostPiece(lp)
	{};
	Move(void) = default;
	std::pair<Location, Location> m_move;
	// bool: 0 has been lost, 1: has not
	// int: 
	std::tuple<bool, PieceType, int>    m_lostPiece;
	bool 						  m_castle= false;
	int 						  m_moveNo = 0;
	bool 						  m_enpassant = false;
};


class Board : public Component, private ObserverMapper<Location>
{
protected:
	 std::map<Location, std::unique_ptr<Square>> m_board;
	 //Move m_currentMove;
	 Game* mp_game;
	 LossBoard * mp_lossBoard;
	 GameBuilder* mp_builder;
	 std::pair<bool, bool> m_check = {false, false};

public: 
	Board(Game* game, LossBoard* lb, PrintImpl* pi, GameBuilder* gb) : Component(pi), mp_game(game), mp_lossBoard(lb),
					mp_builder(gb)
	{};

	//Board(const Board& otherboard);
	Board(Board&& otherboard)       = delete;

	Board&  operator=(const Board&) = delete;
	Board&& operator=(Board&&)      = delete;

	~Board() = default;
	
	PieceType getPiece(const Location& i) const;

	bool selectSquare(const Location& i, const Colour& c);

	bool checkMove(const Location& movefrom, const Location& moveto) const;

	void unselectAll();

	void updateBoard(const Location& movefrom, const Location& moveto);

	void doMove(Move& mov);

	void undoMove(const Move& mov);

	void addSquare(Location loc, std::unique_ptr<Square> sqr);
	void removeSquare(const Location& loc);

	void draw() const override;

	void pawnAttach(const Location& loc1, const Location& loc2);

	void pawnDetach(const Location& loc1, const Location& loc2);

	void empassantRemove(const Location& loc, Key<Pawn>);

	bool inCheck(Colour c, Colour pturn);

	bool getCheck(Colour c, Key<AbstractPiece>) const; 

	std::list<Location> getLocsForCheck(Colour c, Colour pturn) const;


	//void checkCastle(Colour c) const;

	
};





#endif