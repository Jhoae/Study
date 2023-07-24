#include <iostream>

using namespace std;

class B; /* #2 ���� ���� forward declaration */
class C; /* #4 */




/* #1 friend function ���� ��� 
      -> Ư�� class�� private member�� ���� ���� */
class A
{
private:
	int m_value = 1;

	friend void doSomething(A& a);
	friend void doSomething_2(A& a, B& b);
};

void doSomething(A& a) 
{
	cout << "A�� doSomething�� a.m_value:\t" << a.m_value << endl;
}




/* #2 �ܺ� �Լ����� 2���� class member ����ϱ� */
class B
{
private:
	int m_value = 2;

	friend void doSomething_2(A& a, B& b);
	friend class C; /* #3 */
};

void doSomething_2(A&a, B&b)
{
	cout << "B�� doSomething_2�� a.m_value:\t" << a.m_value << endl;
	cout << "B�� doSomething_2�� b.m_value:\t" << b.m_value << endl;
}






/* #4 class�� Ư�� function�� friend �ϱ� - friend member function
	  -> ����� ���� �и� */
class D
{
private:
	int m_value = 4;

public:
	void doSomething(C& c);
};







/* #3 �ٸ� class�� private�� �����ϴ� ��� */
class C
{
private:
	int m_value = 3;

	friend void D::doSomething(C& c);/* #4 class�� Ư�� function"��" friend �ϱ� */

public:
	void doSomething(B& b)
	{
		cout << "C�� b.m_value:\t\t\t" << b.m_value << endl;
	}
};





/* #4 class�� Ư�� function"��" friend �ϱ� - friend member function
	  -> ����� ���� �и� */
void D::doSomething(C& c)
{
	cout << "D�� doSomething�� c.m_value:\t" << c.m_value << endl;
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