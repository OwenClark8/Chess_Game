// Board.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Board.h"



// This is an example of an exported variable
BOARD_API int nBoard=0;

// This is an example of an exported function.
BOARD_API int fnBoard(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see Board.h for the class definition
CBoard::CBoard()
{
	m_board = new string*[8];
	for (int i = 0; i < 8; i++)
	{
		m_board[i] = new string[8];
	}
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			
			m_board[i][j] = "E";
		}
	}
	
	return;
}

CBoard::CBoard(CBoard& otherboard)
{
	m_board = new string*[8];
	for (int i = 0; i < 8; i++)
	{
		m_board[i] = new string[8];
	}

	int* m;
	m = new int[2];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m[0] = i;
			m[1] = j;
			m_board[i][j] = otherboard.GetPiece(m);
		}
	}
	delete[] m;
}

CBoard::~CBoard()
{
	for (int i = 0; i < 8; i++)
	{
		delete[] m_board[i];
	}
	delete[] m_board;
		
}

string CBoard::GetPiece(int* i)
{
	return m_board[i[0]][i[1]];
}

void CBoard::UpdateBoard(int* movefrom,int* moveto)
{
	string movingpiece = m_board[movefrom[0]][movefrom[1]];
	m_board[movefrom[0]][movefrom[1]] = "E";
	m_board[moveto[0]][moveto[1]] = movingpiece;
}

