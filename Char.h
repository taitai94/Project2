#pragma once
#include <string>
#include <iostream>
#include "Extern_void.h"
class Char
{
public:
	Char();

	~Char();
	std::string getName();
	int getAge();
	void setName(int &choose);


private:

	//Char description
	std::string m_name ="Default Name";
	int m_age =20;


};

