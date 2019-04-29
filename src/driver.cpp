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
#include "../include/SFMLPrintLib.h"
#include "../include/SFMLPrinter.h"
#include "../include/SFMLEventHandler.h"

#include <SFML/Graphics.hpp>


int main(int argc, char *argv[])
{

	using clock = std::chrono::high_resolution_clock;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Chess Game");

 	SFMLLib::SFMLGame newSFMLGame(&window, "chess3.png");

 	SFMLPrinter print(&newSFMLGame);

	Game newGame(&print);
 	
 	GameBuilder builder(&newGame, &print);
 
 	newGame.createNewGame(builder);

 	SFMLEventHandler eHandler(&newGame, &window, &newSFMLGame);

 	// clock::time_point tp = clock::now();

 	// auto delta_time = clock::now() - clock::now();

 	while(eHandler.checkContinue())
 	{
 		eHandler.checkForEvents();

 	}

	return 0;
}



