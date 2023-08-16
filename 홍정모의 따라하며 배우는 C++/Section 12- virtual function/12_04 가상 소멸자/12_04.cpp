#include <iostream>
using namespace std;

class Base
{
public:

/* #2 다형성을 사용하는 경우  -> ~Base만 호출됨
	-> Derived가 지워지지 않으므로 메모리 leak이 발생
	-> 해결법 : 소멸자를 virtual로 만들면 된다.
	// ~Derived -> ~Base 순서로 호출된다.
*/


	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

/* #2 
	virtual ~Derived() override 
*/
	~Derived()
	{
		cout << "~Derived" << endl;
		delete[] m_array;
	}
};

int main()
{
/*	#1 소멸자 호출 순서는 생성자 호출 순서의 반대이다. */
	// 	Derived derived(5);
	// ~Derived -> ~Base

/* #2 다형성을 사용하는 경우  -> ~Base만 호출됨 
	-> Derived가 지워지지 않으므로 메모리 leak이 발생
	-> 해결법 : 소멸자를 virtual로 만들면 된다.
	// ~Derived -> ~Base 순서로 호출된다.	
*/
	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;

	return 0;
}