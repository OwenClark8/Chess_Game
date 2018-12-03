#include "stdafx.h"
#include "King.h"


King::King(void)
{
	m_colour = 0;
	m_position = new int[2];
	m_position[0] = 1;
	m_position[1] = 1;
	m_name = "King";
	return;
}

King::King(const int colour, int* position, CBoard& gameboard)
{
	m_colour = colour;
	m_position = position;
	m_name = "King";
	mp_gameboard = new CBoard(gameboard);
	return;
}

King::~King()
{
	delete m_position;
}

int* King::GetPosition() const
{
	return m_position;
}

vector<string> King::GetMovementOptions() const
{
	int x = m_position[0], y = m_position[1];
	int* mov;
	int* m;
	mov = new int[2];
	mov[0] = x;
	mov[1] = y;
	m = mov;
	vector<string> output;
	string ispiece;
	string ispiece2;
	if (m_colour == 0)
	{

	}
}


