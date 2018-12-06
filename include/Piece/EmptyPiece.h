#ifndef EMPTYPIECEDEF
#define EMPTYPIECEDEF


#include "AbstractPiece.h"
class ABSTRACTPIECE_API EmptyPiece :
	public CAbstractPiece
{
public:
	EmptyPiece(int* position = { 0});
	~EmptyPiece();
	int* GetPosition() const;
};
#endif
