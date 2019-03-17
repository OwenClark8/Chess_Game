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

 	clock::time_point tp = clock::now();

//	Main game while loop
 	auto delta_time = clock::now() - clock::now();


 	sf::RenderWindow window(sf::VideoMode(800, 600), "Chess Game");


 	ImageBoard ib;
 	//ib.newGame();

 	std::array<std::array<int, 8>, 8> p ={{{{4, 3, 2, 0, 1, 2, 3, 4}},
 											 {{5, 5, 5, 5, 5, 5, 5, 5}},
 										 {{-1, -1, -1, -1, -1, -1, -1, -1}},
 											{{-1, -1, -1, -1, -1, -1, -1, -1}},
 											  {{-1, -1, -1, -1, -1, -1, -1, -1}},
 											  {{-1, -1, -1, -1, -1, -1, -1, -1}},
 											      {{11, 11, 11, 11, 11, 11, 11, 11}},
							                     {{10, 8, 8, 6, 7, 8, 9, 10}}}};


 	if(!ib.load("chess2.png", p))
 	{

 	}

 

 	//window.draw(ib);



 	// sf::RectangleShape (sf::Vector2f(120.f, 50.f));

 	

 	bool black = false;

 	sf::VertexArray board;

 	board.resize(64 * 4);
 	board.setPrimitiveType(sf::Quads);

 	for(int i = 0 ; i < 8; ++i){
 		
 		for(int j = 0; j < 8; ++j){

 			sf::Vertex* square = &board[((i * 8) + j) * 4];

 			square[0].position = sf::Vector2f(100.f + 50.f * i, 100.f + 50.f * j);
 			square[1].position = sf::Vector2f(100.f + 50.f * (i + 1), 100.f + 50.f * j);
 			square[2].position = sf::Vector2f(100.f + 50.f * (i + 1), 100.f + 50.f * (j+1));
 			square[3].position = sf::Vector2f(100.f + 50.f * i , 100.f + 50.f * (j + 1));

 			if(black)
 			{
 				square[0].color = sf::Color::Black;
	 			square[1].color = sf::Color::Black; 
	 			square[2].color = sf::Color::Black; 
	 			square[3].color = sf::Color::Black; 
 			}
 			else
 			{
 				square[0].color = sf::Color::White;
 				square[1].color = sf::Color::White; 
 				square[2].color = sf::Color::White; 
 				square[3].color = sf::Color::White; 
 			}
 			black = !black;
 		}
 		black = !black;
 	}



	sf::VertexArray frame;
 	frame.resize(16);
 	frame.setPrimitiveType(sf::Quads);

 	for(int i = 0; i < 2; ++i)
 	{
 

		sf::Vertex* square = &frame[i* 4];

	 	square[0].position = sf::Vector2f(90.f + 410.f * i, 90.f);
		square[1].position = sf::Vector2f(100.f + 410.f * i, 90.f);
		square[2].position = sf::Vector2f(100.f + 410.f * i, 510.f );
		square[3].position = sf::Vector2f(90.f + 410.f * i, 510.f);

		square[0].color = sf::Color(165, 42, 42);
		square[1].color = sf::Color(165, 42, 42);
		square[2].color = sf::Color(165, 42, 42); 
		square[3].color = sf::Color(165, 42, 42);

 	
 		
 	} 

	for(int i = 0; i < 2; ++i)
 	{


		sf::Vertex* square = &frame[8 + i* 4];

	 	square[0].position = sf::Vector2f(100.f , 90.f + 410.f * i);
		square[1].position = sf::Vector2f(500.f , 90.f + 410.f * i);
		square[2].position = sf::Vector2f(500.f, 100.f + 410.f * i);
		square[3].position = sf::Vector2f(100.f, 100.f+ 410.f * i);

		square[0].color = sf::Color(165, 42, 42);
		square[1].color = sf::Color(165, 42, 42);
		square[2].color = sf::Color(165, 42, 42); 
		square[3].color = sf::Color(165, 42, 42);



 	}

 	// sf::Texture text;
 	// if(!text.loadFromFile("chesspieces.png"))
 	// 	std::cout<<"failed";




 	//  	std::array<std::array<int, 8>, 8> tiles ={{{{0, 0, 0, 0, 0, 0, 0, 0}},
 	// 										 {{0, 0, 0, 0, 0, 0, 0, 0}},
 	// 									 {{0, 0, 0, 0, 0, 0, 0, 0}},
 	// 										  {{0, 0, 0, 0, 0, 0, 0, 0}},
 	// 										   {{0, 0, 0, 0, 0, 0, 0, 0}},
 	// 										   {{0, 0, 0, 0, 0, 0, 0, 0}},
 	// 										      {{0, 0, 0, 0, 0, 0, 0, 0}},
		// 					                     {{1, 1, 1, 1, 1, 1, 1, 1}}}};
  //   // populate the vertex array, with one quad per tile
  //   for (unsigned int i = 0; i < 8; ++i)
  //   {
  //       for (unsigned int j = 0; j < 8; ++j)
  //       {
  //           //get the current tile number
  //           int tileNumber = tiles[i][j];

  //           // find its position in the tileset texture


  //           auto tileSizex =  text.getSize().x / 6;
  //           auto tileSizey = text.getSize().y / 2;


  //           int tu = (tileNumber % 6);
  //           int tv = (tileNumber / 6);

  //           // get a pointer to the current tile's quad
  //           sf::Vertex* quad = &board[(i * 8 + j ) * 4];

  //           if(tileNumber == -1)
  //           {
  //           	continue;
  //           }
  //           else if(tileNumber > 12 || tileNumber < -1)
  //           	throw "invalid tile board";
  //           // define its 4 texture coordinates
  //           quad[0].texCoords = sf::Vector2f(tu * tileSizex, tv * tileSizey);
  //           quad[1].texCoords = sf::Vector2f((tu + 1) * tileSizex, tv * tileSizey);
  //           quad[2].texCoords = sf::Vector2f((tu + 1) * tileSizex, (tv + 1) * tileSizey);
  //           quad[3].texCoords = sf::Vector2f(tu * tileSizex, (tv + 1) * tileSizey);
  //       }
  //   }

 		//return -1;



 	// sf::Texture text2;
 	// if(!text2.loadFromFile("chess.png"))
 	// 	std::cout<<"failed";
  //   sf::RectangleShape rect(sf::Vector2f(100.f, 100.f));
  //   rect.setPosition(0.f,0.f);
  //   rect.setTexture(&text2);




            // auto tileSizex =  text.getSize().x / 6;
            // auto tileSizey = text.getSize().y / 2;
    //rect.setTextureRect(sf::IntRect(tileSizex * 2, tileSizey * 2, tileSizex, tileSizey));


 	//window.draw(text);
 	//window.draw(rect);
 	//window.draw(frame);


 	bool unclick = true;
 	while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }



        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && unclick)
        {
        	unclick = false;
        	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        	std::cout <<ib.clickSquare(localPosition.x, localPosition.y);
        }
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        	unclick = true;
        }
        // clear the window with black color
       // window.clear(sf::Color::Black);

    

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.clear();
        window.draw(ib);
        //window.draw(board);
        window.draw(frame);
        window.display();
    }

 	

 	//std::cout<<"seconds"<< tp;

 // 	newGame.draw();
	// while( !quit_game )
	// {
	// 	delta_time += clock::now() - time_start;
	// 	time_start = clock::now();
	// 	// Process input
	// 	std::string userin;
	// 	std::getline(std::cin, userin);
	// 	if (userin == "Quit" || userin == "quit")
	// 	{
	// 		quit_game = true;
	// 	}
	// 	try
	// 	{
	// 		auto com = makeCommand(userin);
	// 		newGame.implementCommand(*com.get());
	// 	}
	// 	catch(const char* e)
	// 	{
	// 		std::cerr << e;
	// 	}
	

	// 	if(delta_time > std::chrono::seconds(1))
	// 	{
	// 		delta_time = std::chrono::seconds(0);
	// 		for(int i = 0 ; i < 30; ++i)
	// 			std::cout<< std::endl;
	// 		newGame.draw();
	// 		newGame.tick();
	// 	}
	// }

	return 0;
}



