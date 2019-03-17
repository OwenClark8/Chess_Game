#ifndef SFMLEventHandlerDEF
#define SFMLEventHandlerDEF

#include "EventHandler.h"

class SFMLEventHandler : public EventHandler
{
public:

	SFMLEventHandler(Game* g) : EventHandler(g)
	{};

	~SFMLEventHandler() = default; 

	void checkForEvents() override;

	bool continue() const override;

private:
	

};


#endif