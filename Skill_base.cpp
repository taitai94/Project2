#include "Skill_base.h"
Skill_base::Skill_base()
{
}

std::string Skill_base::getStype()
{
	return m_type;
}
std::string Skill_base::getSname()
{
	return m_name;
}
int Skill_base::getSstr()
{
	return m_str;
}
int Skill_base::getSagi()
{
	return m_agi;
}
int Skill_base::getSint()
{
	return m_int;
}
int Skill_base::getShp()
{
	return m_hp;
}
int Skill_base::getSdmg()
{
	return m_dmg;
}
int Skill_base::getSmp()
{
	return m_mp;
}


