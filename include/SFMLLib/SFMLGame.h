#ifndef SFMLGAMEDEF
#define SFMLGAMEDEF


#include "ImageBoard.h"

#include "SFMLLossBoard.h"
#include "Button.h"
#include <chrono>
#include <array>
#include <vector>
#include <memory>
#include <string>



namespace SFMLLib
{


class SFMLGame
{
public:
	using clock = std::chrono::high_resolution_clock;

	SFMLGame(sf::RenderWindow* wind, std::string file = "chessPieces.png"):
		mp_window(wind), m_chessfile(file), mp_imageBoard(new ImageBoard()),
		mp_lossBoard(new SFMLLossBoard())
	{
		this->makeButtons();
	};

	~SFMLGame() = default;

	void updateTimer(const std::array<clock::time_point, 2>& t);

	void loadImageBoard(const std::array<std::array<int, 8>, 8> tiles);

	void loadLossBoard(const std::array<std::array<int,6>, 2>& lb);

	void selectSquares(const std::array<std::array<bool, 8>, 8> tiles);

	void display() const;

	ImageBoard* getPTImageBoard() const;

	void changeFileLoc(std::string newFile);

	std::string clickSquare(float x, float y) const;

	void updatePlayerTurn(int no);

	void updateTurnNo(int no);

	void updateCheck(Colour c, bool b);

	void lossMessage(Colour c);




protected:

	sf::RenderWindow*  mp_window;

	std::unique_ptr<ImageBoard> mp_imageBoard;

	std::unique_ptr<SFMLLossBoard> mp_lossBoard;

	std::vector<std::unique_ptr<Button>> m_buttons;

	std::string m_chessfile;

	int m_turnNo = 0;

	int m_playerTurn = 0;

private:

	void makeButtons();

};


}
#endif