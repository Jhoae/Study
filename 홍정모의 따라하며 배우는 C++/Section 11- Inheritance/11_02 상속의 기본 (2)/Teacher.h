#pragma once

#include "Person.h"

class Teacher
{
private:
	std::string m_name;
	// Todo: 집 주소 나이 월급과 같은 member 추가

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






/* #2 Person class 상속받기 */
class Teacher_per : public Person
{
private:

public:
	Teacher_per(const std::string& name_input = "No Name")
		:Person(name_input)
	{}
/* 
* #4 겹치는 부분을 부모 class로 빼버리기 
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