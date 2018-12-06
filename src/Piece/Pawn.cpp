#include "stdafx.h"
#include "Pawn.h"
//NEED TO CODE ENPOISSANT REQUIRES PREV MOVE

Pawn::Pawn(void)
{
	m_colour = 0;
	m_position = new int[2];
	m_position[0] =1;
	m_position[1] = 1;
	m_name = "Pawn";
	return;
}

Pawn::Pawn(const int colour,int* position,CBoard& gameboard)
{
	m_colour = colour;
	m_position = position;
	m_name = "Pawn";
	mp_gameboard = new CBoard(gameboard);
	return;
}


Pawn::~Pawn()
{
	delete m_position;
}

int* Pawn::GetPosition() const
{
	return m_position;
}

vector<string> Pawn::GetMovementOptions() const
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
	
	if (y == 8 && m_colour==0)
	{
		output.at(0) = "No Moves";
		return output;
	}
	if (y == 1 && m_colour == 1)
	{
		output.at(0) = "No Moves";
		return output;
	}
	else if (m_colour == 0)
	{
		//Forward move 1
		m = mov;
		m[1] = y + 1;
		ispiece = mp_gameboard->GetPiece(m);
		if (ispiece == "E" || findcolour(ispiece) == "B")
		{
			output.push_back(to_string(m[0]) + "," + to_string(m[1]));
		}
		//Can move 2 if in stating place
		if (y == 2)
		{
			m = mov;
			m[1] = y + 2;
			ispiece = mp_gameboard->GetPiece(m);
			if (ispiece == "E" || findcolour(ispiece) == "B")
			{
				output.push_back(to_string(m[0]) + "," + to_string(m[1]));
			}

		}
		//Now look at options to take a piece
		//Take piece to the right
		if (x != 8)
		{
			m = mov;
			m[0] = x + 1;
			m[1] = y + 1;
			ispiece = mp_gameboard->GetPiece(m);
			if (findcolour(ispiece) == "B")
			{
				output.push_back(to_string(m[0]) + "," + to_string(m[1]));
			}
		}
		//Take piece to the left
		if (x != 1)
		{
			m = mov;
			m[0] = x - 1;
			m[1] = y + 1;
			ispiece = mp_gameboard->GetPiece(m);
			if (findcolour(ispiece) == "B")
			{
				output.push_back(to_string(m[0]) + "," + to_string(m[1]));
			}
		}

	}
	//Now for whites moves 
	else if (m_colour == 1)
	{
		//Forward move 1
		m = mov;
		m[1] = y -1;
		ispiece = mp_gameboard->GetPiece(m);
		if (ispiece == "E" || findcolour(ispiece) == "W")
		{
			output.push_back(to_string(m[0]) + "," + to_string(m[1]));
		}
		//Can move 2 if in stating place
		if (y == 7)
		{
			m = mov;
			m[1] = y - 2;
			ispiece = mp_gameboard->GetPiece(m);
			if (ispiece == "E" || findcolour(ispiece) == "W")
			{
				output.push_back(to_string(m[0]) + "," + to_string(m[1]));
			}

		}
		//Now look at options to take a piece
		//Take piece to the right
		if (x != 8)
		{
			m = mov;
			m[0] = x + 1;
			m[1] = y - 1;
			ispiece = mp_gameboard->GetPiece(m);
			if (findcolour(ispiece) == "W")
			{
				output.push_back(to_string(m[0]) + "," + to_string(m[1]));
			}
		}
		//Take piece to the left
		if (x != 1)
		{
			m = mov;
			m[0] = x - 1;
			m[1] = y - 1;
			ispiece = mp_gameboard->GetPiece(m);
			if (findcolour(ispiece) == "W")
			{
				output.push_back(to_string(m[0]) + "," + to_string(m[1]));
			}
		}
		return output;
	}
	else
	{
		output.at(0) = "Error";
		return output;
	}

	
	
	//Dealicate memory used
	delete[] mov;
	delete[] m;
	
}

void Pawn::MovePiece(string position)
{
	int* movefrom = m_position;
	int q = position.find(",");
	string a, b;
	a = position.substr(0, q);
	b = position.substr(q, q + 1);
	m_position[0] = atoi(a.c_str());
	m_position[1] = atoi(b.c_str());
	mp_gameboard->UpdateBoard(movefrom,m_position);

}

void Pawn::LosePiece()
{

}
