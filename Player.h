#pragma once
#include "Item.h"
#include "Char.h"
#include "Class_base.h"
#include "Extern_void.h"
#include "Class_Knight.h"
#include "Class_Witch.h"

class Player
{
public:
	Player();
	~Player();
	void chooseClass(std::vector<Class_base>& v_class, int& choose);
	void setClass();
	void setChar(Char charr);
	void setItem(Item item);
	std::string getName();

	void print();
	void printelement(int& i);
	void printele();//for ubuntu

	//Item
	void addItem(Item item);
	void clearItem();
	void removeDropItem();
	Item dropItem();
	std::string getItemName();
	void clearItemTai();
	int getItemPrice();
	void useItem();
	int useSkill();
	int numberremoveitem;
	int numskill;
	void printDistinctValues();
	std::vector<int> v_num_item;
	std::vector<std::string> v_item_name;

	void setPosition(int x, int y);
	void getPosition(int& x, int& y);


	//xml
	void write_xml();
	void print_xml();

	void loadFromxml(std::vector<Item>& v_item, std::vector<Class_base>& v_class);


	//BATTLE FIGHT
	void takeDmg(int takedamage);
	int giveDmg();
	int skillgiveDmg();
	int checkDead();

	//BATTLE LEVEL
	void gainExp(int& amountexp);
	void checkLevelUp();
	void levelUp();

private:
	//Player description
	std::string m_name = "noname", m_cname, m_location, m_skill;
	int m_age, m_hp = 100, m_str = 100, m_def = 100, m_agi = 100, m_dmg = 100, m_mp = 100
		, m_int = 100, m_lv = 1, m_exp = 0;
	//Player posistion
	int m_x, m_y;
	float  chance; //chance success
	int currenthp, currentmp;

	//Item
	std::vector<Item> m_v_item;
	std::vector<Item> m_v_item_distinct;
	std::string m_itemName;
	int m_itemPrice;
	Item item23;//return something i dont know
	//Skill
	std::vector<Skill_base> m_v_skill;
	std::vector<Class_base> m_v_class;

};

