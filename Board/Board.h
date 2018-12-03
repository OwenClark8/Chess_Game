// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BOARD_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BOARD_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BOARD_EXPORTS
#define BOARD_API __declspec(dllexport)
#else
#define BOARD_API __declspec(dllimport)
#endif



#ifndef BOARDDEF
#define BOARDDEF
#include <string>
#include <iostream>



using namespace std;

// This class is exported from the Board.dll
class BOARD_API CBoard {
protected:
	 string** m_board;
public: 
	CBoard(void);
	CBoard(CBoard& otherboard);
	~CBoard();
	
	string GetPiece(int* i);
	void UpdateBoard(int* movefrom,int* moveto);
	

	// TODO: add your methods here.
};






extern BOARD_API int nBoard;

BOARD_API int fnBoard(void);

#endif