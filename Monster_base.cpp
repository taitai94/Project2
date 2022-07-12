#include "Monster_base.h"

Monster_base::Monster_base()
{
}

std::string Monster_base::getName()
{
	return m_name;
}
void Monster_base::defaultmonster()
{
	m_type = "Default monster type";
	m_name = "Default monster name";
	m_hp = 300;
	m_str = 100;
	m_def = 100;
	m_agi = 100;
	m_dmg = 100;
	m_lv = 1;
	m_returnExp = 200;
}

void Monster_base::print()
{
	std::cout << "\nThis is Monster\n\n";
	std::cout << "Type: " << m_type << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Heath: " << m_hp << std::endl;
	std::cout << "Strenght: " << m_str << std::endl;
	std::cout << "Defense: " << m_def << std::endl;
	std::cout << "Agi: " << m_agi << std::endl;
	std::cout << "Damage: " << m_dmg << std::endl;
	std::cout << "Level: " << m_lv << std::endl;
	std::cout << "Return experience: " << m_returnExp << std::endl;
	std::cout << std::string(10, '-') << "\n";
	std::cout << std::string(64, '*') << "\n" << std::endl;
	std::cout << "Monster Inventory\n";
	if (m_v_item.size() > 0)
	{
		for (int i = 0; i < m_v_item.size(); i++)
		{
			std::cout << i + 1 << ". " << m_v_item[i].getItemName() << "\n";
		}
	}
	std::cout << "\n" << std::string(64, '*') << "\n";
}
void Monster_base::printelement(int& i)
{
	if (i == 7)
	{
		printf(" Monster");
		
		std::cout << " Name: " << m_name;
		std::cout << " Type: " << m_type;
	}
	else if (i == 8)
	{
		std::cout << " Heath: " << m_hp;
		std::cout << " Level: " << m_lv;
	}
}
void Monster_base::printele()
{

		printf("Monster");
		std::cout << "Name: " << m_name << ' ';
		std::cout << "Type: " << m_type << ' ';
		std::cout << "Heath: " << m_hp << ' ';
		std::cout << "Level: " << m_lv << ' ';
}

//void Monster_base::addMonster_base()
//{
//	std::cout << "***************Fill the information to add class***************\n";
//	std::string add_type,add_classname, add_location, add_skill;
//	int add_heath, add_strenght, add_defense, add_agi, add_dmg,add_lv, add_returnexp;
//
//	//check duplicate type
//	std::cout << "Enter the type: ";
//	std::cin.clear();
//	std::cin.ignore();
//	std::getline(std::cin, add_type);
//	for (int i = 0; i < vec_Monster_bases.size(); i++)
//	{
//		while (add_type == m_type)
//		{
//			std::cout << "This type has existed, please try another one: ";
//			std::cin.clear();
//
//			std::getline(std::cin, add_type);
//		}
//	}//check duplicate type: done
//
//	//check duplicate name
//	std::cout << "Enter the name: ";
//	std::cin.clear();
//	std::getline(std::cin, add_classname);
//	for (int i = 0; i < vec_Monster_bases.size(); i++)
//	{
//		while (add_classname == vec_Monster_bases[i].m_name)
//		{
//			std::cout << "This name has existed, please try another one: ";
//			std::cin.clear();
//
//			std::getline(std::cin, add_classname);
//		}
//	}//check duplicate name: done
//
//
//	std::cout << "Enter the heath: ";
//	check_int(add_heath);
//	std::cout << "Enter the strenght: ";
//	check_int(add_strenght);
//	std::cout << "Enter the defense: ";
//	check_int(add_defense);
//	std::cout << "Enter the agi: ";
//	check_int(add_agi);
//	std::cout << "Enter the damage: ";
//	check_int(add_dmg);
//	std::cout << "Enter the level: ";
//	check_int(add_lv);
//	std::cout << "Enter the return experience: ";
//	check_int(add_returnexp);
//	vec_Monster_bases.push_back(Monster_base(add_type,  add_classname, add_heath, add_strenght, add_defense, add_agi, add_dmg, add_lv,add_returnexp));
//
//	std::cout << std::string(64, '*');
//}
//
//void Monster_base::removeMonster_base()
//{
//	if (vec_Monster_bases.size() > 0)
//	{
//		std::cout << "***************This is a list of class***************\n";
//		printMonster_base();
//		std::cout << "Please enther the number you want to remove class: (1) to (" << vec_Monster_bases.size() << ")\n";
//		std::cout << std::string(64, '*') << std::endl;
//		std::cout << "Your input: ";
//		int a = 0;
//		check_int(a);
//		std::cout << std::string(64, '*') << std::endl;
//		std::cout << "You removed Monster_base type :" << vec_Monster_bases[a - 1].m_type <<"name: " << vec_Monster_bases[a - 1].m_name << std::endl;
//		vec_Monster_bases.erase(vec_Monster_bases.begin() + a - 1);
//		std::cout << std::string(64, '*') << std::endl;
//	}
//	else
//	{
//		std::cout << "\nBitch! I know you wanna try this but there was no Monster_base to remove! And don't try again please\n";
//	}
//}


void Monster_base::write_xml()
{
	xml_document <>doc;
	xml_node<>* Monster_base_node = doc.allocate_node(node_element, "Monster_base_list");
	Monster_base_node->append_attribute(doc.allocate_attribute("Version", "1.0"));
	doc.append_node(Monster_base_node);

	std::string* xmlHeath, * xmlStrenght, * xmlDefense, * xmlDamage, * xmlLv, * xmlReturnexp;

	xml_node<>* Monster_base_detail = doc.allocate_node(node_element, "Monster_base_detail");
	Monster_base_detail->append_attribute(doc.allocate_attribute("xml_mtype", m_type.c_str()));
	Monster_base_node->append_node(Monster_base_detail);
	//node 2 and so on

	xml_node<>* Monster_base_class = doc.allocate_node(node_element, "Monster_base_class");
	Monster_base_class->append_attribute(doc.allocate_attribute("xml_mname", m_name.c_str()));
	xmlHeath = new std::string(std::to_string(m_hp));
	Monster_base_class->append_attribute(doc.allocate_attribute("xml_mhp", xmlHeath
		->c_str()));
	xmlStrenght = new std::string(std::to_string(m_str));
	Monster_base_class->append_attribute(doc.allocate_attribute("xml_mstr", xmlStrenght->c_str()));
	xmlDefense = new std::string(std::to_string(m_def));
	Monster_base_class->append_attribute(doc.allocate_attribute("xml_mdef", xmlDefense->c_str()));
	xmlDamage = new std::string(std::to_string(m_str));
	Monster_base_class->append_attribute(doc.allocate_attribute("xml_mdmg", xmlDamage->c_str()));
	xmlLv = new std::string(std::to_string(m_lv));
	Monster_base_class->append_attribute(doc.allocate_attribute("xml_mlv", xmlLv->c_str()));
	xmlReturnexp = new std::string(std::to_string(m_returnExp));
	Monster_base_class->append_attribute(doc.allocate_attribute("xml_mreturnexp", xmlReturnexp->c_str()));
	std::cout << std::endl;
	Monster_base_detail->append_node(Monster_base_class);

	// Convert doc to string if needed
	std::string xml_as_string;
	rapidxml::print(std::back_inserter(xml_as_string), doc);

	// Save to file
	std::ofstream file_stored("Monster_base.xml");
	file_stored << doc;
	file_stored.close();
	doc.clear();

	// Read xml file =================================

	std::ifstream file("Monster_base.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

}
void Monster_base::print_xml()
{
	std::cout << "***********************This is Monster_base Print XML***********************\n\n";
	xml_document<> doc;
	xml_node<>* root_node;
	// Read the xml file into a vector
	std::ifstream theFile("Monster_base.xml");
	std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Monster_base_list");
	if (root_node)
	{
		// Iterate over the touhou
		for (xml_node<>* Monster_base_node = root_node->first_node("Monster_base_detail"); Monster_base_node; Monster_base_node = Monster_base_node->next_sibling())
		{
			printf("Monster_base type:  %s\n",
				Monster_base_node->first_attribute("xml_mtype")->value());
			for (xml_node<>* Monster_baseclass_node = Monster_base_node->first_node("Monster_base_class"); Monster_baseclass_node; Monster_baseclass_node = Monster_baseclass_node->next_sibling())
			{
				printf("Name: %s\nHeath: %s\nStrenght: %s\nDefense: %s\nDamage: %s\nLevel: %s\nReturn experience: %s\n ",
					Monster_baseclass_node->first_attribute("xml_mname")->value(),
					Monster_baseclass_node->first_attribute("xml_mhp")->value(),
					Monster_baseclass_node->first_attribute("xml_mstr")->value(),
					Monster_baseclass_node->first_attribute("xml_mdef")->value(),
					Monster_baseclass_node->first_attribute("xml_mdmg")->value(),
					Monster_baseclass_node->first_attribute("xml_mlv")->value(),
					Monster_baseclass_node->first_attribute("xml_mreturnexp")->value());
			}
			printf("%s", Monster_base_node->value());
			std::cout << std::string(10, '-') << std::endl;
		}
	}
	std::cout << "\n" << std::string(64, '*');
}


void Monster_base::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}
void Monster_base::getPosition(int& x, int& y)
{
	x = m_x;
	y = m_y;
}

void Monster_base::getX(int& x)
{
	x = m_x;
}

void Monster_base::getY(int& y)
{
	y = m_y;
}


void Monster_base::takeDmg(int takedamage)
{
	int def = 0, avoidchance = 0;

	avoidchance = m_agi * randomChance(); //
	def = m_def + avoidchance;

	if (takedamage > def)
	{
		takedamage -= def;
		std::cout << "Monster lost : " << takedamage << " HP\n";
		m_hp -= takedamage;
	}
	else
	{
		std::cout << "Monster avoided player attack!\n";
	}
}
int Monster_base::giveDmg()
{
	int dmgplus = m_str * randomChance();
	int newdmg = m_dmg + dmgplus;
	std::cout << "Monster give " << newdmg << " damage to player\n";
	return newdmg;
}
int Monster_base::checkDead()
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
int Monster_base::returnExp()
{
	return m_returnExp;
}
/**********************************ITEM********************************/
void Monster_base::addItem(Item item)
{
	m_v_item.push_back(item);
}
void Monster_base::removeDropItem()
{
	if (m_v_item.size() > 0)
	{
		m_v_item.erase(m_v_item.begin() + numberremoveitem);
	}
}
Item Monster_base::dropItem()
{
	Item item23;
	Item itemreturn;
	item23.setItem("Tai", 50);
	if (m_v_item.size() > 0)
	{
		//random engine
		static std::default_random_engine generator(time(0));
		std::uniform_int_distribution<int> distribution(1, m_v_item.size());
		int dropItem = distribution(generator);
		dropItem--;
		numberremoveitem = dropItem;
		std::cout << "Monster drop item \n" << m_v_item[dropItem].getItemName() << "\n";
		itemreturn = m_v_item[dropItem];
		m_v_item[dropItem] = m_v_item.back();
		return itemreturn;
	}
	else
	{
		std::cout << "Monster did not drop items\n";
		return item23;
	}
}

std::string Monster_base::getItemName()
{
	return m_itemName;
}

int Monster_base::getItemPrice()
{
	return m_itemPrice;
}

void Monster_base::clearItem()
{
	m_v_item.clear();
}

