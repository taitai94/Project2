#include "Item.h"

Item::Item()
{
}
void Item::setItem(std::string name, int price)
{
	m_name = name;
	m_price = price;
}

void Item::setItemHp(std::string name, int price, int hp)
{
	m_name = name;
	m_price = price;
	m_hp = hp;
}


std::string Item::getItemName()
{
	return m_name;
}
int Item::getItemPrice()
{
	return m_price;
}

int Item::addHp()
{
	return m_hp;
}

int Item::addMp()
{
	return m_mp;
}