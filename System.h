#pragma once
#include "Map.h"


class System
{
public:
	int a = 2;
	void setEverything();
	void startBattle();
	void continueBattle();
	void initVecItem();
	void initVecClass();
	void removeMonster(int number);
	Map m_map1;
	Player m_player1;
	Char m_char1;
	Class_base m_class1;
	Monster_base m_monster1;
	Item m_item1;
	Item m_item2;
	Item m_item3;


	Item m_item4;
	std::vector<Monster_base> m_v_monster;
	std::vector<Class_base> m_v_class;
	std::vector<Item> m_v_items;

};

