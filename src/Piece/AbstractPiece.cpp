// AbstractPiece.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "AbstractPiece.h"


// This is an example of an exported variable
ABSTRACTPIECE_API int nAbstractPiece=0;

// This is an example of an exported function.
ABSTRACTPIECE_API int fnAbstractPiece(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see AbstractPiece.h for the class definition


void CAbstractPiece::MovePiece(string position) {

}


void CAbstractPiece::LosePiece() {

}



string findcolour(string loc)
{
	int q = loc.find("/");
	return loc.substr(0, q);
}
