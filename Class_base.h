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
#include <sstream> //buffer
#include "Skill_base.h"
#include "Skill_Blood.h"
#include "Skill_Craw.h"
#include "Skill_Flame.h"
#include "Skill_Vanish.h"

using namespace rapidxml;

class Class_base
{
public:
	Class_base();
	~Class_base();

	std::string getcname();
	std::string getlocation();
	std::string getskill();
	int gethp();
	int getstr();
	int getdef();
	int getagi();
	int getdmg();
	int getmp();
	int getint();
	int getlv();
	int getexp();

	void addClass();

	virtual void showSkill();
	virtual void addSkill();


	//Skill
	std::vector<Skill_base> m_v_skill;
protected:
	//Class_base information
	std::string m_cname ="Default class name";
	std::string m_location = "Default class location";
	std::string m_skill = "Default class skill";

	//addition
	int m_hp = 300;
	int m_str = 100;
	int m_def = 100;
	int m_agi = 100;
	int m_dmg = 100;
	int m_mp = 100;
	int m_int = 100;
	int m_lv = 1;
	int m_exp = 0;

};

