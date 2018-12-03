// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ABSTRACTPIECE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ABSTRACTPIECE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ABSTRACTPIECE_EXPORTS
#define ABSTRACTPIECE_API __declspec(dllexport)
#else
#define ABSTRACTPIECE_API __declspec(dllimport)
#endif

#ifndef ABSTRACTPIECEDEF
#define ABSTRACTPIECEDEF
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "..\Board\Board.h"
using namespace std;
// This class is exported from the AbstractPiece.dll
class ABSTRACTPIECE_API CAbstractPiece {

protected:
	//Eg 
	int* m_position;
	//Eg pawn quenn etc...
	string m_name;
	//0 for white 1 for black
	int m_colour;
	CBoard* mp_gameboard;


public:
	
	
	virtual int* GetPosition() const=0 ;
	virtual void MovePiece(string position);
	virtual vector<string> GetMovementOptions() const=0;
	virtual void LosePiece();

	

};

extern string findcolour(string loc);

extern ABSTRACTPIECE_API int nAbstractPiece;

ABSTRACTPIECE_API int fnAbstractPiece(void);

#endif