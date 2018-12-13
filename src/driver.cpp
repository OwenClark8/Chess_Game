/*************************************************************************
 *
 *  File Name:  driver.cpp
 *
 *  Purpose:    Initial driver for the chess game. Contans the main loop.
 *
 *          
 *
 *************************************************************************/
#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <vector>
#include <numeric>




enum class Colour{Black, White};
enum class PName{Pawn, King, Queen, Rook, Knight, Bishop};

struct Piece{
	Colour Player;
	std::vector<std::string>        Image;
	std::vector<std::array<int,2>>  Logic;

	Piece(Colour c, std::vector<std::string> i,
			std::vector<std::array<int,2>> l) : Player(c), Image(i), Logic(l){};
};

Piece* makePawn(Colour C)
{
	std::vector<std::string> I = {" _ ",
	     " / \\ ",  
	     " \\_/ ",
	     " /   \\ ",
	 	 " \\   / ",
	 	 " /___\\ "};

    std::vector<std::array<int,2>> L = {{5, 3}, {4, 5}, {4, 5}, {3, 7}, {3, 7}, {3, 7}};

    return new Piece(C, I, L);
}

Piece* makeKing(Colour C)
{
	std::vector<std::string> I = {" _ | _ ",
	     " |-\\-/-| ",  
	     " \\ | / ",
	     " |___| ",
	 	 " / \\ ",
	 	 " |___| "};

	std::vector<std::array<int,2>> L = {{3, 7}, {2, 9}, {3, 7}, {3,7}, {4, 5}, {3, 7}};

    return new Piece(C, I, L);

}

Piece* makeQueen(Colour C)
{
	std::vector<std::string> I = {" |\\/_\\/| ",
	     " |_____| ",  
	     " \\   / ",
	     " | | ",
	 	 " /___\\ "};

	std::vector<std::array<int,2>> L = {{2, 9}, {2, 9}, {3, 7}, {4, 5}, {3, 7}};

    return new Piece(C, I, L);

}

Piece* makeRook(Colour C)
{
	std::vector<std::string> I = {" ||_|| ",
	     " |   | ",  
	     " |   | ",
	     " \\ / ",
	     " /___\\ "};

	std::vector<std::array<int,2>> L = {{3, 7}, {3, 7}, {3, 7}, {4, 5}, {3, 7}};

    return new Piece(C, I, L);

}

Piece* makeBishop(Colour C)
{
	std::vector<std::string> I = {" . ",
	     " / \\ ",  
	     " / + \\ ",
	     " \\ _ / ",
	 	 " |_| ",
	 	 " _\\_/_ "};

	std::vector<std::array<int,2>> L = {{5, 3}, {4, 5}, {3, 7}, {3, 7}, {4, 5}, {3, 7}};

    return new Piece(C, I, L);

}


Piece* makeKnight(Colour C)
{
	std::vector<std::string> I = {" |_| ",
	     " /   | ",  
	     " |_/| | ",
	     " | | ",
	 	 " /___\\ "};

	std::vector<std::array<int,2>> L = {{4, 5}, {3, 7}, {2, 8}, {5, 5}, {4, 7}};

    return new Piece(C, I, L);

}

struct Square{
	std::vector<std::string> Image;
	Colour                   SquareColour;

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
	};

	void removePiece()
	{
		setImage();
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
	std::vector<PName>           LostPieces;
	clock::time_point      TimeLeft;

	Player(Colour C, std::chrono::minutes min) : PColour(C), TimeLeft(clock::now() - min)
	{
	};

	void addLostPiece(PName piece)
	{
		LostPieces.push_back(piece);
	};
};


struct Game{
	std::array<Square, 64>   Board;
	int                      TurnNumber;
	Colour                    PlayerTurn;
	std::array<Player, 2>     Players;


	Game() : TurnNumber(0), PlayerTurn(Colour::White), Players({Player(Colour::Black, std::chrono::minutes(30)), Player(Colour::Black, std::chrono::minutes(30))})
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
void printGame(Game *game)
{
	using clock = std::chrono::high_resolution_clock;
	auto CurrentPlayerTurn = game->PlayerTurn == Colour::White ? "White" : "Black";
	//	auto BlackTime = std::chrono::duration_cast<std::chrono::minutes>(clock::now() - game->Players[0].TimeLeft).count;
	std::cout<<std::endl;
	
	std::cout << "   Turn number: " << game->TurnNumber
				<< "              " << "Current Player Move: "
				<< CurrentPlayerTurn
				<< "                " << "Timer: Black: "
				<< std::chrono::duration_cast<std::chrono::minutes>(clock::now() - game->Players[0].TimeLeft).count()
			    << ":"
			    << 60 - std::chrono::duration_cast<std::chrono::seconds>(clock::now() - game->Players[0].TimeLeft).count() % 60
				<< "   White: "
				<< std::chrono::duration_cast<std::chrono::minutes>(clock::now() - game->Players[1].TimeLeft).count()
			    << ":"
			    << 60 -std::chrono::duration_cast<std::chrono::seconds>(clock::now() - game->Players[1].TimeLeft).count() % 60
				<< std::endl;

	std::vector<char> alphabet(8);
    std::iota(alphabet.begin(), alphabet.end(), 'A');
    
    		std::cout << "   |      1      |"
			<<	"      2      |"
			<<  "      3      |"
			<<	"      4      |"
			<<	"      5      |"
			<<	"      6      |"
			<<	"      7      |"
			<<	"      8      |" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::cout << "   *-------------*"
					<<	"-------------*"
					<<  "-------------*"
					<<	"-------------*"
					<<	"-------------*"
					<<	"-------------*"
					<<	"-------------*"
					<<	"-------------*" << std::endl;
		for(int k = 0; k < 6; k++)
		{
			if(k == 2)
				std::cout << " " << alphabet[i] <<" |";
			else
				std::cout << "   |";

			for (int j = 0; j < 8; ++j)
			{
				//
				game->Board[j + i * 8].drawLine(k);
				std::cout << "|";
			}
			std::cout << std::endl;
		}
		
	}
	std::cout << "   *-------------*"
				<< "-------------*"
				<< "-------------*"
				<< "-------------*"
				<< "-------------*"
				<< "-------------*"
				<< "-------------*"
				<< "-------------*" << std::endl;

	std::cout << "Select a tile (E.g Type 'A1') / Move a piece (E.g Type 'A1->C1') / Instructions (Type 'info') / Resign (Type 'Resign')" 
				<< std::endl;

}



int main(int argc, char *argv[])
{
	using clock = std::chrono::high_resolution_clock;

	bool quit_game(false);
	char userin[20];
	Game testGame;
	auto time_start = clock::now();
	//Game testGame(Game::createGame());
	// gamestate current_state{};
	// gamestate new_state{};

	// Main game while loop
	while( !quit_game )
	{
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		// Process input

		std::cin.getline(userin, 4);
		if (userin == "Quit" || userin == "quit")
		{
			quit_game = true;
		}


		// Update board
		testGame.Players[testGame.PlayerTurn == Colour::White].TimeLeft += delta_time;

		// if(testGame.PlayerTurn == Colour::Black)
		// 	testGame.PlayerTurn = Colour::White;
		// else
		// 	testGame.PlayerTurn = Colur::Black;

		// Render board
		printGame(&testGame);

	}

	return 0;
}

/* Board layout

	Turn number: 5              Current Player: Black                     Timer:  Black 53:04  White 43:02               
                                                                                                                                    Losses
     	   1             2             3            4             5             6             7             8              Black               White    
	*-------------*-------------*-------------*-------------*-------------*-------------*-------------*-------------*
	|      .      |             |             |             |             |             |             |             |	     .
	|     / \     |
  A	|    / + \    |
	|    \ _ /    |
	|     |_|     |
	|    _\_/_    |
	*-------------*
	|***** . *****|
	|**** / \ ****|
  B	|*** / + \ ***|
	|*** \ _ / ***|
	|**** |_| ****|
	|*** _\_/_ ***|
	*-------------*
	|      .      |
	|     / \     |
  C	|    / + \    |
	|    \ _ /    |
	|     |_|     |
	|    _\_/_    |
	*-------------*
	|***** . *****|
	|**** / \ ****|
  D	|*** / + \ ***|
	|*** \ _ / ***|
	|**** |_| ****|
	|*** _\_/_ ***|
	*-------------*
	|      .      |
	|     / \     |
  E	|    / + \    |
	|    \ _ /    |
	|     |_|     |
	|    _\_/_    |
	*-------------*
	|***** . *****|
	|**** / \ ****|
  F	|*** / + \ ***|
	|*** \ _ / ***|
	|**** |_| ****|
	|*** _\_/_ ***|
	*-------------*
	|      .      |
	|     / \     |
  G	|    / + \    |
	|    \ _ /    |
	|     |_|     |
	|    _\_/_    |
	*-------------*
	|***** . *****|
	|**** / \ ****|
  H	|*** / + \ ***|
	|*** \ _ / ***|
	|**** |_| ****|
	|*** _\_/_ ***|
	*-------------*
	Select a tile (E.g Type 'A1') / Move a piece (E.g Type 'A1->C1') / Instructions (Type 'info') / Resign (Type 'Resign')
	$

*/


