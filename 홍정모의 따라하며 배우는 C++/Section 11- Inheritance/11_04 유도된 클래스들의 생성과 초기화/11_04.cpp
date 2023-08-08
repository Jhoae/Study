#include <iostream>
using namespace std;

/* #1 */
class Mother
{
private:
	int m_i;

public:
	Mother(const int& i_in = 0)
		:m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child :public Mother {
public:
	float m_d;

public:
	Child()
		:m_d(1.0f), Mother(1024)
	{
		cout << "Child construction" << endl;

	}
};


/* #2 */
class A 
{
public:
	A(int a)
	{
		cout << "A : " << a << endl;
	}

	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		:A(a)
	{
		cout << "B : " << b << endl;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		:B(a,b)
	{
		cout << "C : " << c << endl;
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};


int main()
{
/* #1 sizeof -> padding이 발생함 
   - 중요한건 Child class에서 메모리 할당할때, Mother class에 들어있는것도 
     모두 담을만큼, 메모리 사이즈를 크게 할당 받는다는 사실 */

	Child c1;

	cout << "sizeof(Mother):\t" << sizeof(Mother) << endl; // int는 4 바이트
	cout << "sizeof(Child):\t" << sizeof(Child) << endl;   // 4(int)+4(float) = 8 



/* #2 생성자와 소멸자의 순서 */

	C c(1024, 3.14, 'a');

	// 생성자 : A -> B -> C
	// 소멸자 : C -> B -> A


	return 0;
}

