#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		:m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived :public Base
{
private:
	double m_d;

public:
	Derived(int value)
		:Base(value)
	{}
	
/* #1 m_i�� Derived�ȿ��� public���� �ٲٱ� */
	using Base::m_i;

/* #2 Derived���� print�� private�� �ٲپ� �����ϰ� �����  */
private:
	using Base::print; // do not add ()

/* #3 delete�Ͽ� �������� ���ϰ� �ϴ� ��� */
private:
	void print() = delete;
};


int main()
{
	Base base(5);
	Derived derived(7);

/* #1 m_i�� Derived�ȿ��� public���� �ٲٱ� */
	derived.m_i = 1024;

/* #2, #3 Derived���� print�� �����ϰ� �����  */
	base.print();
	// derived.print();

	return 0;
}