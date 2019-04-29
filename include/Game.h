#ifndef GAME
#define GAME

#include "Component.h"
#include "Board.h"



class GameBuilder;

enum class ComponentType{Board, Timer, LossBoard, Info};

enum class State{Resign, Restart, Undo, Redo};

enum class CommandType{Movement, Selection, Info, StateChange};

union Action{
	std::pair<Location, Location> move;
	Location					  select;
	Component* 					  infoPointer;
	State                         changeState;
};

struct Command{
	CommandType m_comType;
	Action      m_action;
};

class Game : public Component
{
protected:

	std::map<ComponentType, std::unique_ptr<Component>> m_Comps;

	std::vector<Move> m_moves = {};

	int m_currentmove = 0;

	Colour m_playerTurn = Colour::White;

	bool m_tick = true;

	std::pair<Location, bool> m_lastClick = std::make_pair(Location(), false); 

public:
	Game(PrintImpl* pi) : Component(pi) {};
	~Game()    = default;

	//void AddBoard(std::unique_ptr<Board> comp);
	//void RemoveBoard();
	void createNewGame(const GameBuilder& builder);
	void deleteGame();

	void implementCommand(const Command& com);

	//void AddTimer(std::unique_ptr<Timer> time);
	//void RemoveTimer();

	void draw() const override;

	void storeMove(Move m);

	void tick(){
		m_tick = !m_tick;
	};




private:
	void addComponent(ComponentType ct, std::unique_ptr<Component> comp);
	void removeComponent(ComponentType ct);

	void turnSwitch();

	void implementStateChange(const State& s);
	void resign(){};
	void restart();
	void undo();
	void redo();
};

Location strToLoc(const std::string& str);

std::unique_ptr<Command> makeCommand(const std::string& s);

#endif



// _____
// |    \  |
// |    |  |
// |____/  |
// |    \  |
// |    |  |
// |____/  |_____ 