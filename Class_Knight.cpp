#include "Class_Knight.h"

Class_Knight::Class_Knight()
{
	m_cname = "Knight";
	m_location = "The land of Darkness";
	m_skill = "Darkness kill move!";
	m_str *= 2;
	m_v_skill.push_back(Skill_Flame());
	m_v_skill.push_back(Skill_Blood());
	m_v_skill.push_back(Skill_Craw());

}

void Class_Knight::addSkill()
{

}