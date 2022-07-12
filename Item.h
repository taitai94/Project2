#pragma once
#include <string>
#include <vector>
#include <iostream>

class Item
{
public:
	Item();
	void setItem(std::string name, int price);
	void setItemHp(std::string name, int price, int hp);
	std::string getItemName();
	int getItemPrice();
	virtual int addHp();
	virtual int addMp();

protected:
	std::string m_name;
	int m_price;
	int m_hp = 0;
	int m_mp = 0;

	
};

