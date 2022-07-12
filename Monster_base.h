#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Extern_void.h"
#include <algorithm>
#include "rapidxml-1.13/rapidxml_ext.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include <fstream>
#include <cstdio>
#include <sstream> //buffer#
#include "Item.h"

using namespace rapidxml;

class Monster_base
{
public:
	Monster_base();

	void defaultmonster();

	virtual void print();
	virtual void printelement(int& i);
	virtual void printele();// print for ubuntu

	virtual std::string getName();
	//xml
	void write_xml();
	void print_xml();

	//battle fight
	virtual void takeDmg(int takedamage);
	virtual int giveDmg();
	virtual int checkDead();
	virtual int returnExp();
	//Items
	virtual void addItem(Item item);
	virtual void removeDropItem();
	int numberremoveitem;
	virtual Item dropItem();
	virtual std::string getItemName();
	virtual int getItemPrice();
	virtual void clearItem();


	//monster position
	virtual void setPosition(int x, int y);
	virtual void getPosition(int& x, int& y);
	virtual void getX(int& x);
	virtual void getY(int& y);

protected:
	//Monster_base description
	std::string m_name;
	std::string m_type;
	int m_hp;
	int m_str;
	int m_def;
	int m_agi;
	int m_dmg;
	int m_lv;
	int m_returnExp;
	//Monster_base position
	int m_x;
	int m_y;
	//monter items
	std::vector<Item> m_v_item;
	std::string m_itemName;
	int m_itemPrice;
	//monster skill


};

