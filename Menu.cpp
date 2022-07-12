#include "Menu.h"
#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#define _getch() getch()
#endif
Menu::Menu()
{

}
Menu::~Menu()
{

}

void Menu::Start()
{
	GameState gamestate = GameState::MENU;
	while (gamestate != GameState::EXIT)
	{
		switch (gamestate)
		{
		case GameState::PLAYER_OPTION:
			player_option(gamestate);
			break;
		case GameState::MONSTER_OPTION:
			monster_option(gamestate);
			break;
		case GameState::PLAY:
			play(gamestate);
			break;
		case GameState::CONTINUE:
			continue_game(gamestate);
			break;
		default:
			menustart(gamestate);
			break;
		}
	}
}

void Menu::menustart(GameState& gamestate)
{
	CLEAR;
	std::cout << "****Welcome to my game***\n";
	std::cout << "Type (1) or (c) to continue\n";
	std::cout << "Type (2) or (s) to enter start game\n";
	std::cout << "Type (3) or (p) to enter player option\n";
	std::cout << "Type (4) or (x) to exit\n";
	std::cout << "Tip 1: in gameplay press (i) to savegane, (o) to loadgame\n";
	std::cout << "Tip 2: in gameplay press (q) to use item\n";
	std::cout << "Tip 3: in gameplay press (`) to get back menu instantly\n";
	std::cout << "Enter your choice \n";
	int input;
	input = _getch();
	
	switch (input)
	{
	case '1':
	case 'c':
		std::cout << std::string(20, '*') << "\n";
		gamestate = GameState::CONTINUE;
		break;
	case '2':
	case 's':
		std::cout << std::string(20, '*') << "\n";
		gamestate = GameState::PLAY;
		break;
	case '3':
	case 'p':
		std::cout << std::string(20, '*') << "\n";
		if (system1.m_player1.getName() == "noname")
		{
			std::cout << "You don't have any player yet!\n";
			pause();
			gamestate = GameState::MENU;
		}
		else
		{
			gamestate = GameState::PLAYER_OPTION;
		}
		break;
	case '4':
	case 'x':
		gamestate = GameState::EXIT;
		break;
	default:
		std::cout << "Invalid option, try again!\n";
		pause();
		gamestate = GameState::MENU;
		break;
	}
}
void Menu::player_option(GameState& gamestate)
{
	std::cout << "\nFollowing the instruction below\n";
	std::cout << "Press 1 to view Player\n";
	std::cout << "Press 2 to save Player xml file\n";
	std::cout << "Press 3 to print Player xml file\n";
	std::cout << "Press 4 to exit\n";
	std::cout << "Press any key to come back Menu\n";
	std::cout << "Enter your choice \n";
	int input;
	input = _getch();

	switch (input)
	{
	case '1':
		std::cout << std::string(20, '*') << "\n";
		system1.m_player1.print();
		gamestate = GameState::PLAYER_OPTION;
		break;
	case '2':
		std::cout << std::string(20, '\*') << "\n";
		system1.m_player1.write_xml();
		gamestate = GameState::PLAYER_OPTION;
		break;
	case '3':
		std::cout << std::string(20, '\*') << "\n";
		system1.m_player1.print_xml();
		gamestate = GameState::PLAYER_OPTION;
		break;
	case '4':
		gamestate = GameState::EXIT;
		break;
	default:
		std::cout << std::string(20, '\*') << "\n";
		gamestate = GameState::MENU;
		break;
	}
}
void Menu::monster_option(GameState& gamestate)
{
	std::cout << "\nFollowing the instruction below\n";
	std::cout << "Press 1 to view Monster_base\n";
	std::cout << "Press 2 to save Monster_base xml file\n";
	std::cout << "Press 3 to print Monster_base xml file\n";
	std::cout << "Press 4 to exit\n";
	std::cout << "Press any key to come back Menu\n";
	std::cout << "Enter your choice \n";
	int input;

	input = _getch();

	switch (input)
	{
	case '1':
		std::cout << std::string(20, '*') << "\n";
		for (int a = 0; a < system1.m_v_monster.size(); a++)
		{
			system1.m_v_monster[a].print();
		}
		gamestate = GameState::MONSTER_OPTION;
		break;
	case '2':
		std::cout << std::string(20, '*') << "\n";
		system1.m_monster1.write_xml();
		gamestate = GameState::MONSTER_OPTION;
		break;
	case '3':
		std::cout << std::string(20, '*') << "\n";
		system1.m_monster1.print_xml();
		gamestate = GameState::MONSTER_OPTION;
		break;
	case '4':
		gamestate = GameState::EXIT;
		break;
	default:
		std::cout << std::string(20, '*') << "\n";
		gamestate = GameState::MENU;
		break;
	}
}
void Menu::play(GameState& gamestate)
{
	system1.startBattle();
	gamestate = GameState::MENU;
}
void Menu::continue_game(GameState& gamestate)
{
	system1.continueBattle();
	gamestate = GameState::MENU;
}


