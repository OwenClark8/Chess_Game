#include "../include/SFMLEventHandler.h"
#include <SFML/Graphics.hpp>



void SFMLEventHandler::checkForEvents() 
{
	if(!mp_window->isOpen())
		return;

    sf::Event event;
    while (mp_window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            mp_window->close();
    }

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_unclick)
    {
    	m_unclick = false;
    	sf::Vector2i localPosition = sf::Mouse::getPosition(*mp_window);
    	try
		{
			auto com = makeCommand(mp_printGame->clickSquare(localPosition.x, localPosition.y));
			mp_game->implementCommand(*com.get());
		}
		catch(const char* e)
		{
			std::cerr << e;
		}
    }
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
    	m_unclick = true;
    }

    mp_game->draw();
    mp_printGame->display();

}

bool SFMLEventHandler::checkContinue() const
{
	return mp_window->isOpen();
}