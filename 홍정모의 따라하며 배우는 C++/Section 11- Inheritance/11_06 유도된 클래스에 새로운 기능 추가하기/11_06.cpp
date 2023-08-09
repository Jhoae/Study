#include <iostream>
using namespace std;

class Base
{
// private:
protected:
	int m_value;

public:
	Base(int value)
		:m_value(value)
	{

	}
};

class Derived : public Base
{
public:
	Derived(int value)
		:Base(value)
	{

	}

	void setValue(int value)
	{
		// Base를 private에서 protected로 변경
		Base::m_value = value; 
		
		// do some work with Derived의 변수
	}
};


int main()
{
	return 0;
}