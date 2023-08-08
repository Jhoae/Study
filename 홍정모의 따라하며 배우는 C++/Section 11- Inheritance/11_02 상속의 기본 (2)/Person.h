#pragma once

#include <iostream>
#include <string>

/* #1 Teacher class�� Student class�� �ߺ� �κ��� Person class�� ����� */
class Person
{
private:
	std::string m_name;

public:
/*#3 Person���� m_name�� �ʱ�ȭ�ϴ� �����ڸ� ����� �ڽ� class���� ���� ��� */
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