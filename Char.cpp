#include "Char.h"
Char::Char()
{
}

Char::~Char()
{
}
std::string Char::getName()
{
	return m_name;
}
int Char::getAge()
{
	return m_age;
}

void Char::setName(int &choose)
{
	switch (choose)
	{
	case 1:
		m_name = "Dafuq";
		m_age = 20;
		break;
	default:
		std::cout << "Enter name: ";
		std::cin >> m_name;
		std::cout << "Enter age: ";
		check_int(m_age);
		break;
	}
}