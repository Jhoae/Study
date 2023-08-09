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

/* #1 */
	void print()
	{
		cout << "I'm Base" << endl;
	}

/* #2 output operator overloading */
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		cout << "This is Base output" << endl;
		return out;
	}

};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		:Base(value)
	{}

/* #1 */
	void print()
	{
		// Base::print(); // 만약 Base의 print도 실행하고 싶다면...
		cout << "I'm Derived" << endl;
	}

/* #2 output operator overloading */
	friend std::ostream& operator << (std::ostream& out, const Derived& b)
	{
		// cout << static_cast<Base>(b);// 만약 Base의 output operator도 실행하고 싶다면...
		cout << "This is Derived output" << endl;
		return out;
	}

};

int main()
{
/* #1 */
	Base base(5);
	base.print();

	Derived derived(7);
	derived.print();


/* #2 output operator overloading */
	cout << base;
	cout << derived;




	return 0;
}