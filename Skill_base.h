#pragma once
#include <string>
class Skill_base
{
public:
	Skill_base();
	virtual std::string getStype();
	virtual std::string getSname();
	virtual int getSstr();
	virtual int getSagi();
	virtual int getSint();
	virtual int getShp();
	virtual int getSdmg();
	virtual int getSmp();
protected:
	std::string m_type;
	std::string m_name;
	int m_str = 0;
	int m_agi = 0;
	int m_int = 0;
	int m_hp = 0;
	int m_dmg = 0;
	int m_mp = 0;
};

