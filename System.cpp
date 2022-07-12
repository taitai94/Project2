#include "System.h"
#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#define _getch() getch()
#endif

void System::startBattle()
{
	setEverything();
	CLEAR;
	m_map1.map_begin(m_player1, m_v_monster, m_v_items, m_v_class);
}

void System::setEverything()
{

	m_v_monster.clear();
	m_v_items.clear();
	m_v_class.clear();
	initVecItem();
	initVecClass();
	std::cout << "Do you want create your character or play character by default?\n";
	std::cout << "Press (1) to choose create. Any key else to play by default character.\n";
	std::cout << "Enter your choice";
	char choice;
	choice = _getch();

	int choose;
	switch (choice)
	{
	case '1':
		choose = 2;
		printf("\n");
		break;
	default:
		choose = 1;
		printf("\n");
		break;
	}
	m_char1.setName(choose);
	m_player1.setChar(m_char1);
	m_player1.chooseClass(m_v_class, choose);
}

void System::continueBattle()
{
	m_v_monster.clear();
	m_v_items.clear();
	m_v_class.clear();
	initVecItem();
	initVecClass();
	m_map1.map_continue(m_player1, m_v_monster, m_v_items, m_v_class);
}

void System::initVecItem()
{
	m_v_items.push_back(Item_hp());
	m_v_items.push_back(Item_mp());
	m_v_items.push_back(Item_hp());
}

void System::initVecClass()
{
	m_v_class.push_back(Class_Knight());
	m_v_class.push_back(Class_Witch());
	for (int a = 0; a < m_v_class.size(); a++)
	{
		m_v_class[a].addSkill();
	}
}
void System::removeMonster(int number)
{
	m_v_monster.erase(m_v_monster.begin() + number - 1);
}





