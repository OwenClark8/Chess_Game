#ifndef PAWNDEF
#define PAWNDEF


#include "AbstractPiece.h"

class ABSTRACTPIECE_API Pawn :
	public CAbstractPiece
{
	
public:
	Pawn(void);
	Pawn(const int colour, int* position,CBoard& gameboard);
	~Pawn();
	int* GetPosition() const;
	vector<string> GetMovementOptions() const;
	void MovePiece(string position);
	void LosePiece();
};
#endif
