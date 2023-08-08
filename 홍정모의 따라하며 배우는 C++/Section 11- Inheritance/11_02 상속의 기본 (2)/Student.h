#pragma once

#include "Person.h"

class Student
{
private:
	std::string m_name;
	int m_intel; // 지능

	// Todo: 주소 번호 나이 등등 member 추가

public:
	Student(const std::string& name_input = "No Name", const int& intel_inptu = 0)
		:m_name(name_input), m_intel(intel_inptu)
	{}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	int getIntel()
	{
		return m_intel;
	}

	friend std::ostream& operator << (std::ostream& out, const Student& student)
	{
		out << student.m_name << " " << student.m_intel;
		return out;
	}
};





/* #2 Person class 상속받기 */
class Student_per : public Person
{
private:
	int m_intel; 

public:

/*#3 Person에서 m_name을 초기화하는 생성자를 만듬
     -> 자식 class에서 간접적으로 사용 */

	Student_per(const std::string& name_input = "No Name", const int& intel_inptu = 0)
		// :m_name(name_input), m_intel(intel_inptu) // Error :: #3
		:Person(name_input), m_intel(intel_inptu)
	{}


/* #4 겹치는 부분을 부모 class로 빼버리기 
	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}
	std::string getName()
	{
		return m_name;
	}
*/
	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	int getIntel()
	{
		return m_intel;
	}

	void study()
	{
		std::cout << getName() << " is studying " << std::endl;
	}


	friend std::ostream& operator << (std::ostream& out, const Student_per& student)
	{
		out << student.getName() << " " << student.m_intel;
		return out;
	}
};