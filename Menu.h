#pragma once
#include "System.h"
#include "Extern_void.h"

class Menu
{
public:
	Menu();
	~Menu();

	enum class GameState {CONTINUE, PLAY, MENU, PLAYER_OPTION,MONSTER_OPTION ,EXIT};

	void Start();
	void menustart(GameState &gamestate);
	void play(GameState& gamestate);
	void continue_game(GameState& gamestate);
	void monster_option(GameState& gamestate);
	void player_option(GameState& gamestate);
	int a = 0;
	void addone() { a++; std::cout << a << '\n'; };

private:
	System system1;

};

