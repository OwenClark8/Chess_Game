#ifndef LOSSBOARDDEF
#define LOSSBOARDDEF


#include "Component.h"
#include "defs.h"

class LossBoard: public Component
{
protected:
	std::array<std::array<int,6>, 2> m_pieces = {{{{0, 0, 0, 0, 0, 0}},
							                     {{0, 0, 0, 0, 0, 0}}}};
public:
	LossBoard(PrintImpl* pi): Component(pi)
	{};

	~LossBoard() = default;

	LossBoard(const LossBoard&) = delete;
	LossBoard(LossBoard&&)      = delete;

	LossBoard& operator()(const LossBoard&) = delete;
	LossBoard& operator()(LossBoard&&)      = delete;

	void logPiece(PieceType p);

	void unlogPiece(PieceType p);

	void draw() const override;

};



#endif
