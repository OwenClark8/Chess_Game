
#include "../include/CommandLinePrintLib.h"


using namespace CommandLinePrintLib;

Piece* CommandLinePrintLib::makePawn(Colour C)
{
	std::vector<std::string> I = {" _ ",
	     " / \\ ",  
	     " \\_/ ",
	     " /   \\ ",
	 	 " \\   / ",
	 	 " /___\\ "};

    std::vector<std::array<int,2>> L = {{5, 3}, {4, 5}, {4, 5}, {3, 7}, {3, 7}, {3, 7}};

    return new Piece(C, PName::Pawn, I, L);
}

Piece* CommandLinePrintLib::makeKing(Colour C)
{
	std::vector<std::string> I = {" _ | _ ",
	     " |-\\-/-| ",  
	     " \\ | / ",
	     " |___| ",
	 	 " / \\ ",
	 	 " |___| "};

	std::vector<std::array<int,2>> L = {{3, 7}, {2, 9}, {3, 7}, {3,7}, {4, 5}, {3, 7}};

    return new Piece(C, PName::King, I, L);

}

Piece* CommandLinePrintLib::makeQueen(Colour C)
{
	std::vector<std::string> I = {" |\\/_\\/| ",
	     " |_____| ",  
	     " \\   / ",
	     " | | ",
	 	 " /___\\ "};

	std::vector<std::array<int,2>> L = {{2, 9}, {2, 9}, {3, 7}, {4, 5}, {3, 7}};

    return new Piece(C, PName::Queen, I, L);

}

Piece* CommandLinePrintLib::makeRook(Colour C)
{
	std::vector<std::string> I = {" ||_|| ",
	     " |   | ",  
	     " |   | ",
	     " \\ / ",
	     " /___\\ "};

	std::vector<std::array<int,2>> L = {{3, 7}, {3, 7}, {3, 7}, {4, 5}, {3, 7}};

    return new Piece(C, PName::Rook, I, L);

}

Piece* CommandLinePrintLib::makeBishop(Colour C)
{
	std::vector<std::string> I = {" . ",
	     " / \\ ",  
	     " / + \\ ",
	     " \\ _ / ",
	 	 " |_| ",
	 	 " _\\_/_ "};

	std::vector<std::array<int,2>> L = {{5, 3}, {4, 5}, {3, 7}, {3, 7}, {4, 5}, {3, 7}};

    return new Piece(C, PName::Bishop, I, L);

}


Piece* CommandLinePrintLib::makeKnight(Colour C)
{
	std::vector<std::string> I = {" |_| ",
	     " /   | ",  
	     " |_/| | ",
	     " | | ",
	 	 " /___\\ "};

	std::vector<std::array<int,2>> L = {{4, 5}, {3, 7}, {2, 8}, {5, 5}, {4, 7}};

    return new Piece(C, PName::Knight, I, L);

}

void CommandLinePrintLib::printGame(Game *game, bool tick)
{
	using clock = std::chrono::high_resolution_clock;
	auto CurrentPlayerTurn = game->PlayerTurn == Colour::White ? "White" : "Black";
	//	auto BlackTime = std::chrono::duration_cast<std::chrono::minutes>(clock::now() - game->Players[0].TimeLeft).count;
	std::cout<<std::endl;
	
	std::cout << "   Turn number: " << game->TurnNumber
				<< "              " << "Current Player Move: "
				<< CurrentPlayerTurn
				<< "                " << "Timer: Black: "
				<< std::chrono::duration_cast<std::chrono::minutes>(game->Players[0].TimeLeft - clock::now()).count()
			    << ":"
			    << std::chrono::duration_cast<std::chrono::seconds>(game->Players[0].TimeLeft - clock::now()).count() % 60
				<< "   White: "
				<< std::chrono::duration_cast<std::chrono::minutes>( game->Players[1].TimeLeft - clock::now()).count()
			    << ":"
			    << std::chrono::duration_cast<std::chrono::seconds>(game->Players[1].TimeLeft - clock::now()).count() % 60
				<< std::endl;

	//std::vector<char> alphabet(8);
    //std::iota(alphabet.begin(), alphabet.end(), 'A');
    
    		std::cout << "   |      A      |"
			<<	"      B      |"
			<<  "      C      |"
			<<	"      D      |"
			<<	"      E      |"
			<<	"      F      |"
			<<	"      G      |"
			<<	"      H      |" << game->LossBoard[0] << std::endl;
	std::string line = {"   *-------------*"
						"-------------*"
					    "-------------*"
						"-------------*"
						"-------------*"
						"-------------*"
						"-------------*"
						"-------------*"};
	std::string linetop = {"   *-------------*"
						"-------------*"
					    "-------------*"
						"-------------*"
						"-------------*"
						"-------------*"
						"-------------*"
						"-------------*"};

	int num = 0; 
	int count = 0;
	for(int i = 0; i < 8; ++i)
	{
		std::string linetemp = line;
		for(int j = 0 ; j < 8; ++j)
		{
			
			//std::cout<<"Selcted="<<game->Board[j + i * 8].Selected;
			if(i > 0)
			{
				if(tick && (game->Board[j + i * 8].Selected || game->Board[j + (i -1) * 8].Selected))
					linetemp.replace(j * 13 + 4 + j, 13, "             ");
			}

			if(i == 0)
			{
				if(tick && game->Board[j + i * 8].Selected )
					linetemp.replace(j * 13 + 4 + j, 13, "             ");
			}
		}
		std::cout << linetemp;
		if(count < game->LossBoard.size() - 1)
		{
			std::cout << game->LossBoard[++count];
		}
		std::cout << std::endl;
		
		for(int k = 0; k < 6; k++)
		{
			std::string temp = " |";
			if(tick && game->Board[i * 8].Selected)
					temp = "  ";

			if(k == 2)
				std::cout << " " << ++num <<temp;
			else
				std::cout << "  " <<temp;

			for (int j = 0; j < 8; ++j)
			{
				//
				game->Board[j + i * 8].drawLine(k);


				if(j < 7)
				{
					if(tick && (game->Board[j + i * 8].Selected || game->Board[j + 1 + i * 8].Selected))
						std::cout << " ";
					else
						std::cout << "|";
				}

				if(j == 7)
				{
					if(tick && game->Board[j + i * 8].Selected )
						std::cout << " ";
					else
						std::cout << "|";
						
				}
			}
			if(count < game->LossBoard.size() - 2)
			{
				std::cout << game->LossBoard[++count];
			}
			std::cout << std::endl;
		}
		
	}
	
	std::cout << line << std::endl;

	std::cout << "Select a tile (E.g Type 'A1') / Move a piece (E.g Type 'A1->C1') / Instructions (Type 'info') / Resign (Type 'Resign')" 
				<< std::endl;

}

