#ifndef EVENTHANDLERDEF
#define EVENTHANDLERDEF

#include "Game.h"

class EventHandler
{
public:

	EventHandler(Game* g) : mp_game(g)
	{};

	~EventHandler() = default; 

	virtual void checkForEvents() = 0;

	virtual bool continue() const = 0;

private:
	Game* mp_game;

};


#endif