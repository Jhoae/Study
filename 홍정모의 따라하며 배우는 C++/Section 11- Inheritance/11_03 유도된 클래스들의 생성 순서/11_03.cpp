#include <iostream>
using namespace std;

/* # 1 클래스들의 생성자 호출 순서 */
class Mother
{
public:
	int m_i;
	
	Mother(const int& i_in = 22)
		:m_i(i_in)
	{
		cout << "Mother constructor" << endl;
	}

};

class Child :public Mother{
public:
	double m_d;

public:
	Child()
		:m_d(22.22) //, m_i(22)

/*#2 내부적으로 Mother의 기본 constructor가 초기화되고 있는것.
		: Mother(), m_d(22.22)	 	*/  

	{
		m_i = 22;
		cout << "Child constructor" << endl;
	}
};



/* #3 class가 여러번 상속하는 경우  */
class A
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}
};

class B :public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
};

class C :public B
{
public:
	C()
	{
		cout << "C constructor" << endl;
	}
};


int main()
{
	Child c1; // Mother constructor -> Child constructor


	printf("\n#3 class가 여러번 상속하는 경우\n");

	C c; // A constructor -> B constructor -> C constructor


	return 0;
}

