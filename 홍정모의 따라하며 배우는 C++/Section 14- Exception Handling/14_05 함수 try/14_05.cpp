#include <iostream>

using namespace std;

class A
{
private:
	int m_x;
public:
	A(int x) :m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	/*B(int x)
		:A(x)
	{}*/

/* #2 �����ڿ��� catch�� �ϰ������, function try ������ ����Ѵ� */
	B(int x) try : A(x)
	{
		// do initialization
	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		//throw;
	}
};


void doSomething()
{
	try
	{
		throw - 1;
	}
	catch (...)
	{
		cout << "Catch in doSomething()" << endl;
	}
}

int main()
{
	try
	{
/* #1 */
		// doSomething();

/* #2 */
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}

	return 0;
}
