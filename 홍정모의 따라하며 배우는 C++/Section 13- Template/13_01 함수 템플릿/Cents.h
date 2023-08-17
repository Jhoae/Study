#pragma once

#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents)
		:m_cents(cents)
	{}

// #2 �ε�ȣ operator overloading ����
	friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return (c1.m_cents > c2.m_cents);
	}

// #2 output operator overloading ����
	friend std::ostream& operator << (std::ostream& out, const Cents&cents)
	{
		out << cents.m_cents << " cents ";
		return out;
	}
};