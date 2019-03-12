#include "../include/defs.h"


Letter& operator++(Letter& l)
{
	if(l == Letter::H)
		return l = Letter::A;
	else
		return l = static_cast<Letter>(static_cast<int>(l) + 1);
}

Letter operator+(const Letter& l, int i)
{
	Letter g = l;
	for(int j = 0 ; j < i; ++j)
	{
		++g;
	}
	return g;
}

Letter operator-(const Letter& l, int i)
{
	Letter g = l;
	for(int j = 0 ; j < i; ++j)
	{
		--g;
	}
	return g;
}

Letter& operator--(Letter& l)
{
	if(l == Letter::A)
		return l = Letter::H;
	else
		return l = static_cast<Letter>(static_cast<int>(l) - 1);
}

Number& operator++(Number& l)
{
	if(l == Number::Eight)
		return l = Number::One;
	else
		return l = static_cast<Number>(static_cast<int>(l) + 1);
} 

Number operator+(const Number& l, int i)
{
		Number g = l;
	for(int j = 0 ; j < i; ++j)
	{
		++g;
	}
	return g;
} 

Number operator-(const Number& l, int i)
{
	Number g = l;
	for(int j = 0 ; j < i; ++j)
	{
		--g;
	}
	return g;
} 

Number& operator--(Number& l)
{
	if(l == Number::One)
		return l = Number::Eight;
	else
		return l = static_cast<Number>(static_cast<int>(l) - 1);
} 