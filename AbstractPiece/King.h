#ifndef KINGDEF
#define KINGDEF
#include "AbstractPiece.h"
class ABSTRACTPIECE_API King :
	public CAbstractPiece
{
public:
	King(void);
	King(const int colour, int* position, CBoard& gameboard);
	~King();
	int* GetPosition() const;
	vector<string> GetMovementOptions() const;
};
#endif
