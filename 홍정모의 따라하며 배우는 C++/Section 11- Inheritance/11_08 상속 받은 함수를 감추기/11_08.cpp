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
	
/* #1 m_i를 Derived안에서 public으로 바꾸기 */
	using Base::m_i;

/* #2 Derived에서 print를 private로 바꾸어 사용못하게 만들기  */
private:
	using Base::print; // do not add ()

/* #3 delete하여 접근하지 못하게 하는 방법 */
private:
	void print() = delete;
};


int main()
{
	Base base(5);
	Derived derived(7);

/* #1 m_i를 Derived안에서 public으로 바꾸기 */
	derived.m_i = 1024;

/* #2, #3 Derived에서 print를 사용못하게 만들기  */
	base.print();
	// derived.print();

	return 0;
}