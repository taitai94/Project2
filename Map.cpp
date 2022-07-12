#include "Map.h"
#include <stdlib.h>
#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#define _getch() getch()
#endif
Map::Map()
{
}
Map::~Map()
{
}
void Map::map_begin(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{
	v_monster.clear();
	vec_map.clear();//everytime you comeback here, vec_map need to be clear or it will print double time
	isDone = false;//because isDone = true in the option "`" get back to menu, we need set it false again
	setMap("Map.txt");
	setPosition(player, v_monster);
	//add player items
	player.clearItem();
	for (int j = 0; j < v_monster.size(); j++)
	{
		v_monster[j].clearItem();
	}
	for (int j = 0; j < v_item.size(); j++)
	{
		v_item[j].getItemName();
	}

	//for player
	for (int i = 0; i < v_item.size(); i++)
	{
		player.addItem(v_item[i]);
	}
	//for monsterh
	for (int k = 0; k < v_item.size(); k++)
	{
		for (int j = 0; j < v_monster.size(); j++)
		{
			v_monster[j].addItem(v_item[k]);
		}
	}

	while (!(isDone))
	{
		checkgotobattle = 0;
		printMap(player, v_monster);
		moveInput(player, v_monster, v_item, v_class);
		
	}

}
void Map::map_final(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{
	std::cout << std::string(100, '\n');
	vec_map.clear();//everytime you comeback here, vec_map need to be clear or it will print double time
	isDone = false;//because isDone = true in the option "`" get back to menu, we need set it false again
	setMap("Map2.txt");
	setPosition(player, v_monster);
	//add player items
	for (int j = 0; j < v_monster.size(); j++)
	{
		v_monster[j].clearItem();
	}
	for (int j = 0; j < v_item.size(); j++)
	{
		v_item[j].getItemName();
	}

	//for monster
	for (int k = 0; k < v_item.size(); k++)
	{
		for (int j = 0; j < v_monster.size(); j++)
		{
			v_monster[j].addItem(v_item[k]);
		}
	}

	while (!(isDone))
	{
		checkgotobattle = 0;
		printMap(player, v_monster);
		moveInput(player, v_monster, v_item, v_class);
	}
}
void Map::map_continue(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{
	load("Save1.txt", player, v_monster, v_item, v_class);
	isDone = false;//because isDone = true in the option "`" get back to menu, we need set it false again
		//add monster item
	for (int k = 0; k < v_item.size(); k++)
	{
		for (int j = 0; j < v_monster.size(); j++)
		{
			v_monster[j].addItem(v_item[k]);
		}
	}
	while (!(isDone))
	{
		checkgotobattle = 0;
		printMap(player, v_monster);
		moveInput(player, v_monster, v_item, v_class);
	}
}
void Map::setMap(std::string fileName)
{
	std::ifstream MapFile;
	MapFile.open(fileName);
	if (MapFile.fail())
	{
		perror(fileName.c_str());
	}
	std::string line;
	while (std::getline(MapFile, line))
	{
		vec_map.push_back(line);
	}
}
void Map::printMap(Player& player, std::vector<Monster_base>& v_monster)
{
#ifdef _WIN32
	CLEAR;
	for (int i = 0; i < vec_map.size(); i++)
	{

		std::cout << vec_map[i];
		std::cout << "         ";
		player.printelement(i);
		if (!(isDone) && checkgotobattle == 1 && printmonsternum > -1)
		{
			v_monster[printmonsternum].printelement(i);
		}
		std::cout << '\n';
	}
#else
	CLEAR;
	for (int i = 0; i < vec_map.size(); i++)
	{
		std::cout << vec_map[i];
		std::cout << '\n';
	}	
	player.printele();
	std::cout << '\n';
	if (!(isDone) && checkgotobattle == 1 && printmonsternum > -1)
	{
		v_monster[printmonsternum].printele();
		std::cout << '\n';
	}
#endif
}
void Map::info(Player& player, std::vector<Monster_base>& v_monster, int &i) //set player, v_monster info
{
	player.printelement(i);
	if (!(isDone) && checkgotobattle == 1 && printmonsternum > -1)
	{
		v_monster[printmonsternum].printelement(i);
	}
}


void Map::setPosition(Player& player, std::vector<Monster_base>& v_monster) //set player, v_monster position 
{
	//set player position
	char Tile;
	for (int y = 0; y < vec_map.size(); y++)
	{
		for (int x = 0; x < vec_map[y].size(); x++)
		{
			Tile = vec_map[y][x];
			switch (Tile)
			{
			case 'P':
				player.setPosition(x, y);
				break;
			case 'D':
				v_monster.push_back(Monster_Elculus());
				v_monster.back().setPosition(x, y);
				break;
			case 's':
				v_monster.push_back(Monster_Skeleton());
				v_monster.back().setPosition(x, y);
				break;
			case '%':
				v_monster.push_back(Monster_Mosquitoes());
				v_monster.back().setPosition(x, y);
				break;
			}
		}
	}
}

void Map::moveInput(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{

	int inX, inY, inXm = 0, inYm = 0;
	char input;
	player.getPosition(inX, inY);
	input = _getch();


	switch (input)
	{
	case 'W':
	case 'w':
		movePlayer(player, inX, inY - 1, v_monster, v_item, v_class);
		moveMonster(player, v_monster, v_item, inX, inY);
		break;
	case 'S':
	case 's':
		movePlayer(player, inX, inY + 1, v_monster, v_item, v_class);
		moveMonster(player, v_monster, v_item, inX, inY);
		break;
	case 'A':
	case 'a':
		movePlayer(player, inX - 1, inY, v_monster, v_item, v_class);
		moveMonster(player, v_monster, v_item, inX, inY);
		break;
	case 'D':
	case 'd':
		movePlayer(player, inX + 1, inY, v_monster, v_item, v_class);
		moveMonster(player, v_monster, v_item, inX, inY);
		break;
	case 'q':
		printf("You go to item option!\n");
		player.useItem();
		moveMonster(player, v_monster, v_item, inX, inY);
		break;
	case 'i':
		save("Save1.txt", player, v_monster, v_item);
		break;
	case 'o':
		load("Save1.txt", player, v_monster, v_item, v_class);
		break;
	case'`':
		isDone = true;
	}

}

char Map::getTile(int i, int k)
{
	return vec_map[k][i];
}
void Map::setTile(int i, int k, char a)
{
	vec_map[k][i] = a;
}
void Map::movePlayer(Player& player, int getX, int getY, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{
	switch (getTile(getX, getY))
	{
	case '#':
		printf("Dafuq you ran into a wall. Really my fen?\n");
		break;
	case '.':
		int x, y;
		player.getPosition(x, y);
		setTile(x, y, '.');
		player.setPosition(getX, getY);
		setTile(getX, getY, 'P');
		printf("\n");
		break;
	default:
		checkgotobattle = 1;
		map_fight(player, v_monster, getX, getY, v_item, v_class);
		break;
	}
}
void Map::moveMonster(Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, int inX, int inY)
{
	int xtarget = 0;
	int ytarget = 0;
	int xcheck = 0;
	int ycheck = 0;
	int xmove, ymove;
	for (int a = 0; a < v_monster.size(); a++)
	{
		v_monster[a].getPosition(xmove, ymove);
		char Tile = getTile(xmove, ymove);
		//std::cout << "this is tile: "<< a <<". "<<Tile << '\n';
		xcheck = abs(inX - xmove);
		ycheck = abs(inY - ymove);

		if (xcheck <= 1 || ycheck <= 1)
		{
			if (xcheck > ycheck)
			{
				if (inX >= xmove)
				{
					xtarget = xmove + 1;
					ytarget = ymove;
				}
				else
				{
					xtarget = xmove - 1;
					ytarget = ymove;
				}
			}
			else
			{
				if (inY >= ymove)
				{
					ytarget = ymove + 1;
					xtarget = xmove;
				}
				else
				{
					ytarget = ymove - 1;
					xtarget = xmove;
				}
			}
		}
		else
		{
			if (randomChance() > 0.5)
				if (randomChance() > 0.5)
				{
					xtarget = xmove + randomMove();
					ytarget = ymove;
				}
				else
				{
					ytarget = ymove + randomMove();
					xtarget = xmove;
				}
			else
			{
				xtarget = xmove;
				ytarget = ymove;
			}
		}

		switch (getTile(xtarget, ytarget))
		{
		case '.':
			setTile(xtarget, ytarget, Tile);
			v_monster[a].setPosition(xtarget, ytarget);
			setTile(xmove, ymove, '.');
			break;
		case 'P':
			std::cout << "monster found player but it let you escapse\n";
			break;
		default:
			break;
		}
	}
}
////////////////////////////

void Map::map_fight(Player& player, std::vector<Monster_base>& v_monster, int getX, int getY, std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{

	checkgotobattle = 1;
	int mX, mY;
	for (int i = 0; i < v_monster.size(); i++)
	{
		printmonsternum = -1;
		printmonsternum = i;
		v_monster[i].getPosition(mX, mY);

		if (getX == mX && getY == mY)
		{
			bool fight_end = false;
			while (!(fight_end) && !(isDone))
			{
				printMap(player, v_monster);
				int turn = 1;

				std::cout << std::string(10, '-') << "\n";
				std::cout << "Player turn\n";
				std::cout << std::string(10, '-') << "\n";
				std::cout << "This is player option you can choose:\n";
				std::cout << "Press (q) to use item\n";
				std::cout << "Press (f) to use skill\n";
				char choose;

				choose = _getch();

				int temp = 0;

				switch (choose)
				{
				case 'q':
					player.useItem();
					break;
				case 'f':
					temp = player.useSkill();
					break;
				default:
					break;
				}
				if (temp == 1)
				{
			
					v_monster[i].takeDmg(player.skillgiveDmg());
					pause();
				}
				else if (temp == 2)
				{
					fight_end = true;
				}
				else
				{
					v_monster[i].takeDmg(player.giveDmg());
					pause();
					CLEAR;
					printMap(player, v_monster);
				}

				if (v_monster[i].checkDead() == 20)
				{
					player.addItem(v_monster[i].dropItem());
					player.clearItemTai();
					v_monster[i].removeDropItem();
					int amountexp = v_monster[i].returnExp();
					player.gainExp(amountexp);
					//set tile when v_monster died
					int x, y;
					v_monster[i].getPosition(x, y);
					//std::cout << "This is get tile of v_monster[i]" << Map::getTile(x, y) << "\n";
					setTile(x, y, '.');
					v_monster.erase(v_monster.begin() + i);
					pause();
					fight_end = true;
					break;
				}
				std::cout << "Monster turn\n";
				std::cout << std::string(10, '-') << "\n";
				player.takeDmg(v_monster[i].giveDmg());
				pause();
				CLEAR;
				if (player.checkDead() == 20)
				{
					int x, y;
					player.getPosition(x, y);
					setTile(x, y, 'x');
					printMap(player, v_monster);
					std::cout << "You died!\n";
					v_monster[i].addItem(player.dropItem());
					player.removeDropItem();
					pause();
					isDone = true;
				}
			}
		}
	}
	if (v_monster.size() == 0)
	{
		std::cout << "Congratulation, you will go to another stage.\n";
		pause();
		map_final(player, v_monster, v_item, v_class);
	}
}

void Map::save(std::string saveName, Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item)
{
	std::ofstream MapFile;
	MapFile.open(saveName);
	if (MapFile.fail())
	{
		perror(saveName.c_str());
	}

	std::string line;
	for (int i = 0; i < vec_map.size(); i++)
	{
		MapFile << vec_map[i] << "\n";
	}
	MapFile.close();
	player.write_xml();
	std::cout << "Your saved game has been done!\n";
}
void Map::load(std::string fileName, Player& player, std::vector<Monster_base>& v_monster, std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{

	v_monster.clear();
	std::ifstream MapFile;
	MapFile.open(fileName);
	if (MapFile.fail())
	{
		perror(fileName.c_str());
		std::cout << "That mean you don't have any " << fileName << " to continue!\n";
	}
	else
	{
		if (vec_map.size() > 0)
		{
			vec_map.clear();// need to clear the vector 
		}
		std::string line;
		while (std::getline(MapFile, line))
		{
			vec_map.push_back(line);
		}
		// load player monster position.. i mean set position again hehe

		setPosition(player, v_monster);
		player.loadFromxml(v_item, v_class);
	}
	std::cout << "Load game has been done!\n";
}
