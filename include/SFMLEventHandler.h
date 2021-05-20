#ifndef SFMLEventHandlerDEF
#define SFMLEventHandlerDEF

#include "EventHandler.h"
#include "SFMLPrintLib.h"

class SFMLEventHandler : public EventHandler
{
public:

	SFMLEventHandler(Game* g, sf::RenderWindow* win, SFMLLib::SFMLGame* g2) : EventHandler(g), mp_window(win),
				mp_printGame(g2)
	{};

	~SFMLEventHandler() = default; 

	void checkForEvents() override;

	bool checkContinue() const override;

private:
	bool m_unclicked = true;
 	sf::RenderWindow*  mp_window;
 	SFMLLib::SFMLGame* mp_printGame;
 	bool m_unclick = true;

};


#endif