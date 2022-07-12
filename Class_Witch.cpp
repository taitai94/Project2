#include "Class_Witch.h"

Class_Witch::Class_Witch()
{
	m_cname = "Witch";
	m_location = "The land of Forest";
	m_skill = "Run like hell";
	m_agi *= 3;

	m_v_skill.push_back(Skill_Vanish());
	m_v_skill.push_back(Skill_Blood());
	m_v_skill.push_back(Skill_Craw());
}
void Class_Witch::addSkill()
{

}
