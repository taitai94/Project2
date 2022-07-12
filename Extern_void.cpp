#include "Extern_void.h"
#include <stdio.h>
#ifdef _WIN32
#define CLEAR system("cls")
#include <conio.h>
#else
#define CLEAR system("clear")
#define _getch() getch()
#include "conio-linux.h"
#endif
void check_int(int& num)
{
	std::string string_check;
	std::cin >> string_check;
	while (loop_checkint(string_check) == 1)
	{
		std::cout << "The input is invalid. Try again: ";
		std::cin >> string_check;
		loop_checkint(string_check);
	}
	num = stoi(string_check);
}
//loop check_int
int loop_checkint(std::string& string_loop)
{
	int numbers = 0;
	int characters = 0;
	int others = 0;

	for (int i = 0; i < string_loop.size(); i++)
	{
		if (isdigit(string_loop[i]))
		{
			++numbers;
		}
		else if (isalpha(string_loop[i]))
		{
			++characters;
		}
		else
		{
			++others;
		}
	}
	if (characters > 0 || others > 0 || string_loop == "0")
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

void lower(std::string& l_string)
{
	std::transform(l_string.begin(), l_string.end(), l_string.begin(), ::tolower);
}

float randomChance()
{
	//random engine
	static std::default_random_engine generator(time(0));
	std::uniform_int_distribution<int> distribution(0, 100);
	int randomnumber = distribution(generator);
	return  (float)randomnumber / 100;
}

int randomMove()
{
	static std::default_random_engine generator(time(0));
	std::uniform_int_distribution<int> distribution(-1, 1);
	int randommove =  distribution(generator);
	return randommove;
}

bool alert(std::string currentstate, std::string destinationstate)
{
	std::cout << "Do you want to escapse " << currentstate << " to get back to "<<destinationstate<< " (Yes/No): ";
	std::string input;
	std::cin >> input;
	if (input == "yes")
	{
		return true;
	}
	else
	{
		return false;
	}
}


void pause()
{
	std::cout << "Press any key to continue!\n";
	char a;
	a = _getch();
}