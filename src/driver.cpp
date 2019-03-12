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
#include <functional>
#include <memory>




#include "../include/CommandLinePrinter.h"
#include "../include/Game.h"
#include "../include/GameBuilder.h"




int main(int argc, char *argv[])
{
	using clock = std::chrono::high_resolution_clock;
		
	bool quit_game(false);
//	char userin[20];
	auto time_start = clock::now();

 	CommandLinePrinter print(std::unique_ptr<CommandLinePrintLib::Game>(new CommandLinePrintLib::Game));

	Game newGame(&print);
 	
 	GameBuilder builder(&newGame, &print);
 
 	newGame.createNewGame(builder);

 // std::cout<<"draw";
 // 	newGame.draw();

 // 	auto com = makeCommand("A2->A4");
 // 	newGame.implementCommand(*com.get());


 // 	newGame.draw();
 // 	// auto com2 = makeCommand("A1");
 // 	// newGame.implementCommand(*com2.get());

 // 	std::vector<int> test{};

 // 	//auto w = test.cbegin();

 // 	// test.push_back(5);
 // 	// test.push_back(6);
 // 	// // ++w;
 // 	// // w = test.cbegin();
 	

 // 	// std::cout<<"test="<<(w != test.cend());



 // 	  	auto com5 = makeCommand("A4->A5");
 // 	 newGame.implementCommand(*com5.get());


 // 	  	auto com3 = makeCommand("A5");
 // 	newGame.implementCommand(*com3.get());

 // 	 	newGame.draw();

 // 	 auto com6 = makeCommand("A5->A6");
 // 	newGame.implementCommand(*com6.get());



 // 	 	newGame.draw();

 	// // auto com4 = makeCommand("A6");
 	// // newGame.implementCommand(*com4.get());
 	// // newGame.tick();
 	//  newGame.draw();
 	// // newGame.tick();


 	//  auto com7 = makeCommand("B7->A6");
 	// newGame.implementCommand(*com7.get());
 	// // auto com8 = makeCommand("Undo");
 	// // newGame.implementCommand(*com8.get());

 	// newGame.draw();


 	// auto com9 = makeCommand("Undo");
 	// newGame.implementCommand(*com9.get());

 	// newGame.draw();
 	//  	auto com10 = makeCommand("Undo");
 	// newGame.implementCommand(*com10.get());

 	// newGame.draw();

 	//  	auto com11 = makeCommand("Undo");
 	// newGame.implementCommand(*com11.get());

 	// newGame.draw();
	// gamestate current_state{};
	// gamestate new_state{};


 	clock::time_point tp = clock::now();

//	Main game while loop
 	auto delta_time = clock::now() - clock::now();

 	

 	//std::cout<<"seconds"<< tp;

 	newGame.draw();
	while( !quit_game )
	{
		delta_time += clock::now() - time_start;
		time_start = clock::now();
		// Process input
		std::string userin;
		std::getline(std::cin, userin);
		if (userin == "Quit" || userin == "quit")
		{
			quit_game = true;
		}
		try
		{
			auto com = makeCommand(userin);
			newGame.implementCommand(*com.get());
		}
		catch(const char* e)
		{
			std::cerr << e;
		}
	

		if(delta_time > std::chrono::seconds(1))
		{
			delta_time = std::chrono::seconds(0);
			for(int i = 0 ; i < 30; ++i)
				std::cout<< std::endl;
			newGame.draw();
			newGame.tick();
		}
	}

	return 0;
}



