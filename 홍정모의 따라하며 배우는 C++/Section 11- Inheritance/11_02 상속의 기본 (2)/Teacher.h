#pragma once

#include "Person.h"

class Teacher
{
private:
	std::string m_name;
	// Todo: �� �ּ� ���� ���ް� ���� member �߰�

public:
	Teacher(const std::string& name_input = "No Name")
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






/* #2 Person class ��ӹޱ� */
class Teacher_per : public Person
{
private:

public:
	Teacher_per(const std::string& name_input = "No Name")
		:Person(name_input)
	{}
/* 
* #4 ��ġ�� �κ��� �θ� class�� �������� 
	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}
*/

	void teach()
	{
		std::cout << getName() << " is teaching " << std::endl;
	}


	friend std::ostream& operator << (std::ostream& out, const Teacher_per& teacher)
	{
		// out << teacher.m_name;
		out << teacher.getName();
		return out;
	}
};