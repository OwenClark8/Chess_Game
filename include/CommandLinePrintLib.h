#ifndef COMMANDLINEPRINTLIBDEF
#define COMMANDLINEPRINTLIBDEF

#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <vector>
#include <numeric>

namespace CommandLinePrintLib{
	
enum class Colour{White, Black};
enum class PName{Pawn, Knight, Queen,  Bishop, Rook, King, Empty};

struct Piece{
	Colour Player;
	PName  Type;
	std::vector<std::string>        Image;
	std::vector<std::array<int,2>>  Logic;


	Piece(Colour c, PName t, std::vector<std::string> i,
			std::vector<std::array<int,2>> l) : Player(c), Type(t), Image(i), Logic(l){};
};

Piece* makePawn(Colour C);

Piece* makeKing(Colour C);

Piece* makeQueen(Colour C);

Piece* makeRook(Colour C);

Piece* makeBishop(Colour C);

Piece* makeKnight(Colour C);


struct Square{
	std::vector<std::string> Image;
	Colour                   SquareColour;
	PName 					 PieceType = PName::Empty;

	bool 					 Selected = false;

	Square() : SquareColour(Colour::Black)
	{
		setImage();
	}

	Square(Colour C) : SquareColour(C)
	{
		setImage();
	};

	void drawLine(int i) const
	{
		std::cout << Image[i];
	};

	void select()
	{
		Selected = true;
	}

	void unselect()
	{
		Selected = false;
	}

	void addPiece(const Piece *p)
	{
		if(p->Player == Colour::White)
			Image[0].replace(0, 1, "W");
		else if(p->Player == Colour::Black)
			Image[0].replace(0, 1, "B");
		auto size = p->Image.size();
		int i = 0;
		for(auto &line : p->Image)
		{
			Image[6-size+i].replace(p->Logic[i][0], p->Logic[i][1], line);
			i++;
		}
		PieceType = p->Type;
	};

	void removePiece()
	{
		setImage();
		PieceType = PName::Empty;
	};
private:
	void setImage()
	{
		if(SquareColour == Colour::White)
		{
			Image = {"             ",
					   "             ",
					   "             ",
					   "             ",
					   "             ",
					   "             ",
					   "             "};
		}
		else if(SquareColour == Colour::Black)
		{
			Image = {"*************",
					   "*************",
					   "*************",
					   "*************",
					   "*************",
					   "*************",
					   "*************"};
		}
	}
};


struct Player{
	using clock = std::chrono::high_resolution_clock;
	Colour 			             PColour;
	std::array<int,6>            LostPieces = {{0, 0, 0, 0, 0, 0}};
	clock::time_point            TimeLeft;

	Player(Colour C, std::chrono::minutes min) : PColour(C), TimeLeft(clock::now() - min)
	{
	};

	void addLostPiece(PName piece)
	{
		int i = static_cast<int>(piece);
		++LostPieces[i];
	};
};


struct Game{
	std::array<Square, 64>   Board;
	int                      TurnNumber;
	Colour                    PlayerTurn;
	std::array<Player, 2>     Players;
	std::vector<std::string>  LossBoard = {
		"                Lost Pieces       ",
        "      ___________________________ " ,         
        "      |            ||            |" ,
        "      |   White    ||   Black    |" ,
        "      |____________||____________|",
        "      |            ||            |",
        "      | Pawn   X 0 || Pawn   X 0 |", 
        "      |            ||            |",
        "      | Knight X 0 || Knight X 0 |",
        "      |            ||            |",
        "      | Queen  X 0 || Queen  X 0 |",
        "      |            ||            |",
        "      | Bishop X 0 || Bishop X 0 |",
        "      |            ||            |",
        "      | Rook   X 0 || Rook   X 0 |",
        "      |____________||____________|"};



	Game() : TurnNumber(0), PlayerTurn(Colour::White), Players({Player(Colour::White,
			 std::chrono::minutes(30)), Player(Colour::Black, std::chrono::minutes(30))})
	{
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 8; j++)
			{
			    if(j % 2 == 0)
			    {
			    	Board[2 * i + j * 8] = Square(Colour::White);
			    	Board[2 * i + j * 8 + 1] = Square(Colour::Black);
			    }
			    else
			    {
			    	Board[2 * i + j * 8] = Square(Colour::Black);
			    	Board[2 * i + j * 8 + 1] = Square(Colour::White);
			    }
			}
	
		}
		// Set starting Pieces
		for(int i = 0; i < 8; i++)
		{
			Board[8 + i].addPiece(makePawn(Colour::Black));
			Board[63 - 8 - i].addPiece(makePawn(Colour::White));
		}
		Board[0].addPiece(makeRook(Colour::Black));
		Board[7].addPiece(makeRook(Colour::Black));

		Board[1].addPiece(makeKnight(Colour::Black));
		Board[6].addPiece(makeKnight(Colour::Black));

		Board[2].addPiece(makeBishop(Colour::Black));
		Board[5].addPiece(makeBishop(Colour::Black));

		Board[3].addPiece(makeQueen(Colour::Black));
		Board[4].addPiece(makeKing(Colour::Black));

		Board[63].addPiece(makeRook(Colour::White));
		Board[56].addPiece(makeRook(Colour::White));

		Board[62].addPiece(makeKnight(Colour::White));
		Board[57].addPiece(makeKnight(Colour::White));

		Board[61].addPiece(makeBishop(Colour::White));
		Board[58].addPiece(makeBishop(Colour::White));

		Board[60].addPiece(makeKing(Colour::White));
		Board[59].addPiece(makeQueen(Colour::White));

		this->updateLossBoard();
	}

	void losePiece(Colour c, PName piece)
	{
		Players[static_cast<int>(c)].addLostPiece(piece);
		
		this->updateLossBoard();


	};

	void updateLossBoard()
	{
		for(int i = 0 ; i < 5; ++i)
		{
			LossBoard[6 + 2 *i].replace(17, 1, std::to_string(Players[0].LostPieces[i]));
			LossBoard[6 + 2 *i].replace(31, 1,std::to_string(Players[1].LostPieces[i]));
		}

	}
};



/*************************************************************************
 *
 *  FUNCTION NAME: PrintBoard
 *
 *  PURPOSE:       Outputs a basic board on the cammand line
 *  
 *  ARGUMENT LIST:
 *
 *  Argument        Type        IO      Description
 *
 *  i  				int 		I       Particle number to be computed for
 *   
 *										
 *
 *  RETURN VALUE: void
 *
 *************************************************************************/
void printGame(Game *game, bool tick);

};

#endif