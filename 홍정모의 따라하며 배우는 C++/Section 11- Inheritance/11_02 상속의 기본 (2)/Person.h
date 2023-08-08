#pragma once

#include <iostream>
#include <string>

/* #1 Teacher class와 Student class의 중복 부분을 Person class로 만들기 */
class Person
{
private:
	std::string m_name;

public:
/*#3 Person에서 m_name을 초기화하는 생성자를 만들고 자식 class에서 간접 사용 */
	Person(const std::string & name_in = "No Name")
		:m_name(name_in)
	{}


	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName() const
	{
		return m_name;
	}

	void doNothing() const 
	{
		std::cout << m_name << " is doing nothing " << std::endl;
	}
};