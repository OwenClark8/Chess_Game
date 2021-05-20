#ifndef GAMECOMMANDDEF
#define GAMECOMMANDDEF

#include "Command.h"
#include "Game.h"
#include <functional>


class GameCommand : public CommandClass
{
public:

	GameCommand(const std::function<std::string()>& func) : m_com(func)
	{};

	std::string Execute() override
	{
		return m_com();
	}

protected:
	std::function<std::string()> m_com;

};


#endif