#include <iostream>

using namespace std;

class B; /* #2 전방 선언 forward declaration */
class C; /* #4 */




/* #1 friend function 선언 방법 
      -> 특정 class의 private member에 접근 가능 */
class A
{
private:
	int m_value = 1;

	friend void doSomething(A& a);
	friend void doSomething_2(A& a, B& b);
};

void doSomething(A& a) 
{
	cout << "A의 doSomething의 a.m_value:\t" << a.m_value << endl;
}




/* #2 외부 함수에서 2개의 class member 사용하기 */
class B
{
private:
	int m_value = 2;

	friend void doSomething_2(A& a, B& b);
	friend class C; /* #3 */
};

void doSomething_2(A&a, B&b)
{
	cout << "B의 doSomething_2의 a.m_value:\t" << a.m_value << endl;
	cout << "B의 doSomething_2의 b.m_value:\t" << b.m_value << endl;
}






/* #4 class의 특정 function만 friend 하기 - friend member function
	  -> 선언과 정의 분리 */
class D
{
private:
	int m_value = 4;

public:
	void doSomething(C& c);
};







/* #3 다른 class가 private에 접근하는 방법 */
class C
{
private:
	int m_value = 3;

	friend void D::doSomething(C& c);/* #4 class의 특정 function"만" friend 하기 */

public:
	void doSomething(B& b)
	{
		cout << "C의 b.m_value:\t\t\t" << b.m_value << endl;
	}
};





/* #4 class의 특정 function"만" friend 하기 - friend member function
	  -> 선언과 정의 분리 */
void D::doSomething(C& c)
{
	cout << "D의 doSomething의 c.m_value:\t" << c.m_value << endl;
}

// 
int main()
{
	A a;
	B b;
	C c;
	D d;

	doSomething(a); // #1

	doSomething_2(a, b); // #2

	c.doSomething(b); // #3

	d.doSomething(c); // #4

	return 0;
}