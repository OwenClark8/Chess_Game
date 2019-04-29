#include "../../include/SFMLLib/SFMLGame.h"
#include "../../include/GameCommand.h"


void SFMLLib::SFMLGame::updateTimer(const std::array<clock::time_point, 2>& t)
{

}

void SFMLLib::SFMLGame::loadImageBoard(const std::array<std::array<int, 8>, 8> tiles)
{
	if(!mp_imageBoard->load(m_chessfile, tiles))
		throw "Failed to load file";

}

void SFMLLib::SFMLGame::loadLossBoard(const std::array<std::array<int,6>, 2>& lb)
{
	if(!mp_lossBoard->load(m_chessfile, lb))
		throw "Failed to load file";
}

void SFMLLib::SFMLGame::display() const
{

	mp_window->clear(sf::Color::White);
    mp_window->draw(*mp_imageBoard.get());
    mp_window->draw(*mp_lossBoard.get());

    for(auto& i : m_buttons)
    {
    	mp_window->draw(*i.get());
    }
	mp_window->display();
}

SFMLLib::ImageBoard* SFMLLib::SFMLGame::getPTImageBoard() const
{
	return mp_imageBoard.get();
}

void SFMLLib::SFMLGame::changeFileLoc(std::string newFile)
{
	m_chessfile = newFile;
}

std::string SFMLLib::SFMLGame::clickSquare(float x, float y) const
{
	for(auto& i : m_buttons)
	{
		if((i->click(x, y)) != "N")
			return i->click(x, y);
	}
	return mp_imageBoard->clickSquare(x, y);
}

void SFMLLib::SFMLGame::selectSquares(const std::array<std::array<bool, 8>, 8> tiles)
{
	mp_imageBoard->setColour(tiles);
}

void SFMLLib::SFMLGame::updatePlayerTurn(int no)
{
	mp_imageBoard->updatePlayerTurn(no);
}

void SFMLLib::SFMLGame::updateTurnNo(int no)
{
	mp_imageBoard->updateTurnNo(no);
}

void SFMLLib::SFMLGame::makeButtons()
{
	m_buttons.reserve(4);

	std::unique_ptr<GameCommand> restartCom(new GameCommand([]() -> std::string{
		// auto x = makeCommand("Restart");
		// p->implementCommand(*x.get());
		return "Restart";
	}));

	std::unique_ptr<GameCommand> resignCom(new GameCommand([]() -> std::string{
		// auto x = makeCommand("Resign");
		// p->implementCommand(*x.get());
		return "Resign";
	}));

	std::unique_ptr<GameCommand> undoCom(new GameCommand([]() -> std::string{
		// auto x = makeCommand("Undo");
		// p->implementCommand(*x.get());
		return "Undo";
	}));

	std::unique_ptr<GameCommand> redoCom(new GameCommand([]() -> std::string{
		// auto x = makeCommand("Redo");
		// p->implementCommand(*x.get());
		return "Redo";
	}));
	try{
	m_buttons.push_back(std::unique_ptr<Button>(new Button(std::move(restartCom), 50.f, 520.f, 75.f, 75.f, "Restart")));
	m_buttons.push_back(std::unique_ptr<Button>(new Button(std::move(resignCom), 200.f, 520.f, 100.f, 75.f, "Resign")));
	m_buttons.push_back(std::unique_ptr<Button>(new Button(std::move(undoCom), 440.f, 60.f, 30.f, 30.f, "undo")));
	m_buttons.push_back(std::unique_ptr<Button>(new Button(std::move(redoCom), 480.f, 60.f, 30.f, 30.f, "redo")));
	}
	catch(...)
	{

	}


}

