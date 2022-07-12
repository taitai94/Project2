#include "Class_base.h"

Class_base::Class_base()
{
}


Class_base::~Class_base()
{
}


std::string Class_base::getcname()
{
	return m_cname;
}
std::string Class_base::getlocation()
{
	return m_location;
}
std::string Class_base::getskill()
{
	return m_skill;
}
int Class_base::gethp()
{
	return m_hp;
}
int Class_base::getstr()
{
	return m_str;
}
int Class_base::getdef()
{
	return m_def;
}
int Class_base::getagi()
{
	return m_agi;
}
int Class_base::getdmg()
{
	return m_dmg;
}
int Class_base::getmp()
{
	return m_mp;
}
int Class_base::getint()
{
	return m_int;
}
int Class_base::getlv()
{
	return m_lv;
}
int Class_base::getexp()
{
	return m_exp;
}
void Class_base::addSkill()
{
}

void Class_base::showSkill()
{
	for (int a = 0; a < m_v_skill.size(); a++)
	{
		std::cout << m_v_skill[a].getSname();
	}
}


