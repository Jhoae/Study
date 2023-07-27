#pragma once

#include <iostream>
#include <string>


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
