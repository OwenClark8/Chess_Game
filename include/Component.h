#ifndef COMPONENTDEF
#define COMPONENTDEF

#include "PrintImpl.h"



class Component
{
protected:
	PrintImpl* mp_Imp;

public:
	Component(PrintImpl* i) : mp_Imp(i)
	{};
	
	virtual ~Component() = default;

	Component(const Component&) = delete;
	Component(Component&&)      = delete;

	Component& operator=(const Component&) = delete;
	Component& operator=(Component&&)      = delete;

	virtual void draw() const = 0;

};

#endif