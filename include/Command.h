#ifndef COMMANDDEF
#define COMMANDDEF

#include <string>

class CommandClass
{
public:

	virtual ~CommandClass() = default;

	virtual std::string Execute() = 0;

};


#endif