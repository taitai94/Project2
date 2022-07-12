#include "Player.h"
#include "Item_hp.h"
#include "System.h"
/*
* int increase damage for magic strenght
save game
load game
*/

Player::Player()
{
	//position
	m_x = 0;
	m_y = 0;

}

Player::~Player()
{
}
void Player::chooseClass(std::vector<Class_base>& v_class, int& choose)
{
	if (choose == 1)
	{
		m_v_class.push_back(Class_Knight());
	}
	else
	{
		int choice;
		m_v_class.clear();
		std::cout << "Please select Class you want to get. Here is the list of class:\n";
		for (int a = 0; a < v_class.size(); a++)
		{
			std::cout << a + 1 << ". " << v_class[a].getcname() << '\n';
		}
		bool isDone = false;
		while (!(isDone))
		{
			std::cout << "Your choice: ";
			check_int(choice);
			if (choice > v_class.size())
			{
				std::cout << "Invalid choice, try again!\n";
			}
			else
			{
				m_v_class.push_back(v_class[choice - 1]);
				isDone = true;
			}
		}
	}
	setClass();
}

void Player::setClass()
{
	m_cname = m_v_class.back().getcname();
	m_location = m_v_class.back().getlocation();
	m_skill = m_v_class.back().getskill();
	m_hp = m_v_class.back().gethp();
	m_str = m_v_class.back().getstr();
	m_def = m_v_class.back().getdef();
	m_agi = m_v_class.back().getagi();
	m_dmg = m_v_class.back().getdmg();
	m_mp = m_v_class.back().getmp();
	m_int = m_v_class.back().getint();
	m_lv = m_v_class.back().getlv();
	m_exp = m_v_class.back().getexp();

	currenthp = m_hp;
	currentmp = m_mp;
	//set skill from class
	m_v_skill.clear();
	for (int a = 0; a < m_v_class.back().m_v_skill.size(); a++)
	{
		m_v_skill.push_back(m_v_class.back().m_v_skill[a]);
	}

}

void Player::setChar(Char charr)
{
	m_name = charr.getName();
	m_age = charr.getAge();
}
std::string Player::getName()
{
	return m_name;
}

void Player::setItem(Item item)
{
	m_v_item.push_back(item);
}

Item Player::dropItem()
{
	if (m_v_item.size() > 0)
	{
		//random engine
		static std::default_random_engine generator(time(0));
		std::uniform_int_distribution<int> distribution(1, m_v_item.size());
		int dropItem = distribution(generator);
		dropItem--;
		numberremoveitem = dropItem;
		std::cout << "Player drop item \n" << m_v_item[dropItem].getItemName() << "\n";
		return m_v_item[dropItem];
	}
	else
	{
		std::cout << "Player did not drop items\n";
		return item23;
	}
}


void Player::addItem(Item item)
{
	m_v_item.push_back(item);
}
void Player::clearItem()
{
	m_v_item.clear();
}

void Player::clearItemTai()
{
	for (int a = 0; a < m_v_item.size(); a++)
	{
		if (m_v_item[a].getItemName() == "Tai")
		{
			m_v_item[a] = m_v_item.back();
			m_v_item.pop_back();
		}
	}
}


void Player::removeDropItem()
{
	if (m_v_item.size() > 0)
	{
		m_v_item.erase(m_v_item.begin() + numberremoveitem);
	}
}

std::string Player::getItemName()
{
	return m_itemName;
}

int Player::getItemPrice()
{
	return m_itemPrice;
}


void Player::print()
{
	std::cout << "******************Player information******************\n\n";

	printf("Name: %s\n", m_name.c_str());
	printf("Age: %d\n", m_age);
	printf("Class: %s\n", m_cname.c_str());
	printf("Location: %s\n", m_location.c_str());
	printf("Skill: %s\n", m_skill.c_str());
	printf("Heath: %d\n", m_hp);
	printf("Strenght: %d\n", m_str);
	printf("Defense: %d\n", m_def);
	printf("Agi: %d\n", m_agi);
	printf("Damge: %d\n", m_dmg);
	printf("Mana: %d\n", m_mp);
	printf("Int: %d\n", m_int);
	printf("Level: %d\n", m_lv);
	printf("Experience: %d\n", m_exp);

	for (int a = 0; a < m_v_skill.size(); a++)
	{
		printf("Skill: %s\n", m_v_skill[a].getSname().c_str());
	}
	std::cout << std::string(20, '-') << "\n";
	std::cout << "Player Inventory\n";
	if (m_v_item.size() > 0)
	{
		for (int i = 0; i < m_v_item.size(); i++)
		{
			std::cout << i + 1 << ". " << m_v_item[i].getItemName() << "\n";
		}
	}
	std::cout << "\n" << std::string(64, '*') << "\n";
}

void Player::printelement(int& i)
{
	if (i == 0)
	{
		std::cout<<" Player";
	}
	else if (i == 1)
	{
		std::cout<<" Name: " << m_name;
		std::cout<<" Class: " << m_cname;
	}
	else if (i == 2)
	{
		std::cout<<" Heath: " << m_hp;
		std::cout<<" Mana: " << m_mp;
	}
	else if (i == 3)
	{
		std::cout<<" Level: " << m_lv;
		std::cout<<" Experience: " << m_exp;
	}
}

void Player::printele()
{
		std::cout << "Player" << ' ';
		std::cout << "Name: " << m_name<< ' ';
		std::cout << "Class: " << m_cname << ' ';
		std::cout << "Heath: " << m_hp << ' ';
		std::cout << "Mana: " << m_mp << ' ';
		std::cout << "Level: " << m_lv << ' ';
		std::cout << "Experience: " << m_exp << ' ';
}
void Player::write_xml()
{
	std::string* xmlEverything;
	xml_document <>doc;
	xml_node<>* declare = doc.allocate_node(node_declaration);
	declare->append_attribute(doc.allocate_attribute("version", "1.0"));
	doc.append_node(declare);

	xml_node<>* Player_node = doc.allocate_node(node_element, "Player");
	doc.append_node(Player_node);


	//node 2 and so on
	xml_node<>* Player_detail = doc.allocate_node(node_element, "Player_detail");
	Player_detail->append_attribute(doc.allocate_attribute("xml_name", m_name.c_str()));
	xmlEverything = new std::string(std::to_string(m_age));
	Player_detail->append_attribute(doc.allocate_attribute("xml_age", xmlEverything->c_str()));
	Player_detail->append_attribute(doc.allocate_attribute("xml_classname", m_cname.c_str()));
	Player_detail->append_attribute(doc.allocate_attribute("xml_location", m_location.c_str()));
	xmlEverything = new std::string(std::to_string(m_hp));
	Player_detail->append_attribute(doc.allocate_attribute("xml_hp", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_str));
	Player_detail->append_attribute(doc.allocate_attribute("xml_str", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_def));
	Player_detail->append_attribute(doc.allocate_attribute("xml_def", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_agi));
	Player_detail->append_attribute(doc.allocate_attribute("xml_agi", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_dmg));
	Player_detail->append_attribute(doc.allocate_attribute("xml_dmg", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_mp));
	Player_detail->append_attribute(doc.allocate_attribute("xml_mp", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_int));
	Player_detail->append_attribute(doc.allocate_attribute("xml_int", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_lv));
	Player_detail->append_attribute(doc.allocate_attribute("xml_lv", xmlEverything->c_str()));
	xmlEverything = new std::string(std::to_string(m_exp));
	Player_detail->append_attribute(doc.allocate_attribute("xml_exp", xmlEverything->c_str()));
	std::cout << "\n";
	Player_node->append_node(Player_detail);

	xml_node<>* Player_item_list = doc.allocate_node(node_element, "Player_item_list");
	Player_item_list->append_attribute(doc.allocate_attribute("xml_player_item_list", "This is player item list"));
	std::cout << "\n";
	Player_detail->append_node(Player_item_list);

	if (m_v_item.size() > 0)
	{
		for (int i = 0; i < m_v_item.size(); i++)
		{
			xml_node<>* Player_item = doc.allocate_node(node_element, "Player_item");
			xmlEverything = new std::string(m_v_item[i].getItemName());
			Player_item->append_attribute(doc.allocate_attribute("xml_item_name", xmlEverything->c_str()));
			xmlEverything = new std::string(std::to_string(m_v_item[i].getItemPrice()));
			Player_item->append_attribute(doc.allocate_attribute("xml_item_price", xmlEverything->c_str()));
			std::cout << "\n";
			Player_item_list->append_node(Player_item);
		}

	}
	xmlEverything = nullptr;
	// Save to file
	std::ofstream file_stored("Player.xml");
	file_stored << doc;
	file_stored.close();
	doc.clear();

	// Read xml file =================================

	std::ifstream file("Player.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

}
void Player::print_xml()
{
	std::cout << "***********************This is Player Print XML***********************\n\n";
	xml_document<> doc;
	xml_node<>* root_node;
	// Read the xml file into a vector
	std::ifstream theFile("Player.xml");
	std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Player");
	if (root_node)
	{
		// Iterate over the touhou
		for (xml_node<>* Player_node = root_node->first_node("Player_detail"); Player_node; Player_node = Player_node->next_sibling())
		{
			printf("Player name: %s\nAge is: %s\nClass name: %s \nLocation: %s\nHeath: %s\nStrenght: %s\nDefense: %s\nAgi: %s\nDamage: %s\nMana: %s\nInt: %s\nLevel: %s\nExperience: %s\n",
				Player_node->first_attribute("xml_name")->value(),
				Player_node->first_attribute("xml_age")->value(),
				Player_node->first_attribute("xml_classname")->value(),
				Player_node->first_attribute("xml_location")->value(),
				Player_node->first_attribute("xml_hp")->value(),
				Player_node->first_attribute("xml_str")->value(),
				Player_node->first_attribute("xml_def")->value(),
				Player_node->first_attribute("xml_agi")->value(),
				Player_node->first_attribute("xml_dmg")->value(),
				Player_node->first_attribute("xml_mp")->value(),
				Player_node->first_attribute("xml_int")->value(),
				Player_node->first_attribute("xml_lv")->value(),
				Player_node->first_attribute("xml_exp")->value());

			for (xml_node<>* Player_item_list = Player_node->first_node("Player_item_list"); Player_item_list; Player_item_list = Player_item_list->next_sibling())
			{
				printf("Player list:  %s\n",
					Player_item_list->first_attribute("xml_player_item_list")->value());
				if (m_v_item.size() > 0)
				{
					for (xml_node<>* Player_item = Player_item_list->first_node("Player_item"); Player_item; Player_item = Player_item->next_sibling())
					{
						printf("\nItem name: %s Item price: %s",
							Player_item->first_attribute("xml_item_name")->value(),
							Player_item->first_attribute("xml_item_price")->value());
					}
				}
			}
		}
	}
	std::cout << "\n" << std::string(64, '*');
}


void Player::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}
void Player::getPosition(int& x, int& y)
{
	x = m_x;
	y = m_y;
}




void Player::takeDmg(int takedamage)
{
	int def = 0, avoidchance = 0, hp = 0;
	avoidchance = m_agi * randomChance(); //
	def = m_def + avoidchance;

	if (takedamage > def)
	{
		takedamage -= def;
		std::cout << "You lost : " << takedamage << " HP\n";
		m_hp -= takedamage;
	}
	else
	{
		std::cout << "You avoided monster attack!\n";
	}
}
int Player::giveDmg()
{
	int dmgplus = m_str * randomChance();
	int newdmg = m_dmg + dmgplus;
	std::cout << "You give " << newdmg << " damage to monster\n";
	return newdmg;
}
int Player::checkDead()
{
	if (m_hp < 0)
	{
		return 20;
	}
	else
	{
		return 0;
	}
}

void Player::gainExp(int& amountexp)
{
	m_exp += amountexp;
	std::cout << "Player gain " << amountexp << " exp!\n";
	std::cout << "Your exp right now is: " << m_exp << " exp!\n";
	if (amountexp > 0)
	{
		checkLevelUp();
	}
	else
	{
		std::cout << "You did not gain any exp!\n";
	}
}

void Player::checkLevelUp()
{
	if (m_exp >= 300 && m_lv == 1)
	{
		levelUp();
	}
	else if (m_exp >= 800 && m_lv == 2)
	{
		levelUp();
	}
	else if (m_exp >= 1200 && m_lv == 3)
	{
		levelUp();
	}
	else if (m_exp >= 2000 && m_lv == 4)
	{
		levelUp();
		std::cout << "You are max level!\n";
	}
}


void Player::levelUp()
{
	static int percentincrease = 1;
	percentincrease++;
	m_lv++;
	printf("Level up!\n");
	std::cout << "Your lv is: " << m_lv << std::endl;

	currenthp = percentincrease * m_v_class.back().gethp();
	currentmp = percentincrease * m_v_class.back().getmp();

	m_hp = percentincrease * m_v_class.back().gethp();
	m_mp = percentincrease * m_v_class.back().getmp();
	m_str = percentincrease * m_v_class.back().getstr();
	m_def = percentincrease * m_v_class.back().getdef();
	m_agi = percentincrease * m_v_class.back().getagi();
	m_dmg = percentincrease * m_v_class.back().getdmg();

	m_int = percentincrease * m_v_class.back().getint();
	m_exp = 0;
}


void Player::loadFromxml(std::vector<Item>& v_item, std::vector<Class_base>& v_class)
{
	xml_document<> doc;
	xml_node<>* root_node;
	// Read the xml file into a vector
	std::ifstream theFile("Player.xml");
	std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Player");
	if (root_node)
	{
		// Iterate over the touhou
		for (xml_node<>* Player_node = root_node->first_node("Player_detail"); Player_node; Player_node = Player_node->next_sibling())
		{
			m_name = Player_node->first_attribute("xml_name")->value(),
				m_age = atoi(Player_node->first_attribute("xml_age")->value()),
				m_cname = Player_node->first_attribute("xml_classname")->value();
			m_location = Player_node->first_attribute("xml_location")->value();
			m_hp = atoi(Player_node->first_attribute("xml_hp")->value());
			m_str = atoi(Player_node->first_attribute("xml_str")->value());
			m_def = atoi(Player_node->first_attribute("xml_def")->value());
			m_agi = atoi(Player_node->first_attribute("xml_agi")->value());
			m_dmg = atoi(Player_node->first_attribute("xml_dmg")->value());
			m_mp = atoi(Player_node->first_attribute("xml_mp")->value());
			m_int = atoi(Player_node->first_attribute("xml_int")->value());
			m_lv = atoi(Player_node->first_attribute("xml_lv")->value());
			m_exp = atoi(Player_node->first_attribute("xml_exp")->value());

			m_v_item.clear();
			for (xml_node<>* Player_item_list = Player_node->first_node("Player_item_list"); Player_item_list; Player_item_list = Player_item_list->next_sibling())
			{
				for (xml_node<>* Player_item = Player_item_list->first_node("Player_item"); Player_item; Player_item = Player_item->next_sibling())
				{
					for (int a = 0; a < v_item.size(); a++)
					{
						if (Player_item->first_attribute("xml_item_name")->value() == v_item[a].getItemName())
						{
							m_v_item.push_back(v_item[a]);
						}
					}
				}
			}
		}
	}
	m_v_class.clear();
	m_v_skill.clear();
	//set class from xml
	for (int a = 0; a < v_class.size(); a++)
	{
		if (m_cname == v_class[a].getcname())
		{
			m_v_class.push_back(v_class[a]);

			//set skill from class
			for (int c = 0; c < m_v_class.back().m_v_skill.size(); c++)
			{
				m_v_skill.push_back(m_v_class.back().m_v_skill[c]);
			}
		}
	}
	currenthp = m_hp;
	currentmp = m_mp;
}
void Player::printDistinctValues()
{
	v_num_item.clear();
	v_item_name.clear();
	for (int i = 0; i < m_v_item.size(); i++)
	{
		int j;
		for (j = 0; j < i; j++)
			if (m_v_item[i].getItemName() == m_v_item[j].getItemName())
			break;
		if (i == j)
		v_item_name.push_back(m_v_item[i].getItemName());//get distinct item
		v_num_item.push_back(0);//get distinct amount of item
	}
	//sort
	std::string temp;
	for (int i = 0; i < v_item_name.size(); i++)
	{
		for (int b = 1; b < v_item_name.size() -i ;b++)
		{
			if (v_item_name[b - 1] > v_item_name[b])
			{
				temp = v_item_name[b - 1];
				v_item_name[b - 1] = v_item_name[b];
				v_item_name[b] = temp;
			}
		}
	}
	for (int i = 0; i < m_v_item.size(); i++)
	{
		int k;
		for (k = 0; k < v_item_name.size(); k++)
		if (m_v_item[i].getItemName() == v_item_name[k])
		{
			v_num_item[k]++; //increase distinct amount of item
		}
	}
	std::cout << "This is new item: \n";
	for (int distinct = 0; distinct < v_item_name.size(); distinct++)
	{
		std::cout << distinct+1 <<". " << v_num_item[distinct] << " x " << v_item_name[distinct] << '\n';
	}
}
void Player::useItem()
{
	if (m_v_item.size() > 0)
	{
		printDistinctValues();
		std::cout << "Which item you want to use: ";
		int input;
		check_int(input);
		while (input > v_item_name.size())
		{
			std::cout << "You enter the number out of range. Try again: ";
			check_int(input);
		}
		input--;
		std::cout << "You chose item " << v_item_name[input] << "\n";
		for (int i = 0; i < m_v_item.size(); i++)
		{
			if (m_v_item[i].getItemName() == v_item_name[input])
			{
				if (m_v_item[i].addHp() > 0 && m_hp == currenthp)
				{
						std::cout << "You already max out of HP!\n";
						break;
				}
				if (m_v_item[i].addMp() > 0 && m_mp == currentmp)
				{
						std::cout << "You already max out of MP!\n";
						break;
				}
				m_hp += m_v_item[i].addHp();
				m_mp += m_v_item[i].addMp();
				if (currenthp <= m_hp)
				{
					m_hp = currenthp;
				}
				if (currentmp <= m_mp)
				{
					m_mp = currentmp;
				}
				m_v_item.erase(m_v_item.begin() + i);
				break;
			}
		}
	}
	else
	{
		std::cout << "You don't have any item at this time!\n";
	}
	pause();
}

int Player::useSkill()
{
	numskill = -1;
	if (m_v_skill.size() > 0)
	{
		std::cout << "This is your skills: \n";
		for (int i = 0; i < m_v_skill.size(); i++)
		{
			std::cout << i + 1 << ". " << m_v_skill[i].getSname() << "\n";
		}
		std::cout << "Which skill you want to use: ";
		check_int(numskill);
		while (numskill > m_v_skill.size())
		{
			std::cout << "You enter the number out of range. Try again: ";
			check_int(numskill);
		}
		numskill--;
		if (m_v_skill[numskill].getSmp() > m_mp)
		{
			std::cout << "The skill need " << m_v_skill[numskill].getSmp() << " mp to active!\n";
			return 3;
		}
		else
		{
			std::cout << "You used skill " << m_v_skill[numskill].getSname() << "\n";
			m_mp -= m_v_skill[numskill].getSmp();
			if (m_v_skill[numskill].getStype() == "Attack")
			{
				return 1;
			}
			else if (m_v_skill[numskill].getStype() == "Support")
			{
				m_hp += m_v_skill[numskill].getShp();
				if (currenthp <= m_hp)
				{
					m_hp = currenthp;
				}
				return 0;
			}
			else
			{
				return 2;
			}
		}
	}
	else
	{
		std::cout << "You don't have any skill!\n";
		return 2;
	}
}

int Player::skillgiveDmg()
{
	int dmgplus = m_str * randomChance();
	int newdmg = m_dmg + m_int + dmgplus;
	int skilldmg = newdmg + m_v_skill[numskill].getSdmg();
	std::cout << "Your skill give " << skilldmg << " damage to monster\n";
	return skilldmg;
}