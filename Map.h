#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Monster_base.h"
#include "Monster_Elculus.h"
#include "Monster_Skeleton.h"
#include "Monster_Mosquitoes.h"
#include "Item_hp.h"
#include "Item_mp.h"

#ifdef _WIN32
#include <conio.h>
#else
#include "conio-linux.h"
#endif

class Map
{
public:
	Map();
	~Map();
	enum class GameState { PROCESS, EXIT };
	GameState gamestate = GameState::PROCESS;

	void map_begin(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class);
	void map_final(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class);
	void map_continue(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class);

	bool isDone = false;
	void setMap(std::string fileName);
	void printMap(Player& player, std::vector<Monster_base>& v_monster);
	void info(Player& player, std::vector<Monster_base>& v_monster,int &i); //set player, v_monster info
	void setPosition(Player& player, std::vector<Monster_base>& v_monster);
	void moveInput(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class);
	void movePlayer(Player& player, int inX, int intY, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class);
	void moveMonster(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, int inX, int inY);

	char getTile(int i, int k);
	void setTile(int i, int k, char a);


	void map_fight(Player& player, std::vector<Monster_base>& v_monster, int getX, int getY, std::vector<Item>& v_item, std::vector<Class_base>& v_class);
	int checkdead;
	int checkgotobattle;
	int printmonsternum;

	//Save Load
	void save(std::string saveName, Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item);
	void load(std::string fileName, Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class);

private:
	std::vector<std::string> vec_map;
	int m_monster;
	Item m_itemExchange;
	std::vector<Player> saveplayer;

};

