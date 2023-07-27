#pragma once

#include <string>


class Teacher
{
private:
	std::string m_name;
	// Todo: 집 주소 나이 월급과 같은 member 추가

public:
	Teacher(const std::string &name_input = "No Name")
		:m_name(name_input)
	{}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}

	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher)
	{
		out << teacher.m_name;
		return out;
	}

};