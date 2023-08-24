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

/* #2 생성자에서 catch를 하고싶을때, function try 문법을 사용한다 */
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
