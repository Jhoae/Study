#include <iostream>
using namespace std;

class Base
{
public:

/* #2 �������� ����ϴ� ���  -> ~Base�� ȣ���
	-> Derived�� �������� �����Ƿ� �޸� leak�� �߻�
	-> �ذ�� : �Ҹ��ڸ� virtual�� ����� �ȴ�.
	// ~Derived -> ~Base ������ ȣ��ȴ�.
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
/*	#1 �Ҹ��� ȣ�� ������ ������ ȣ�� ������ �ݴ��̴�. */
	// 	Derived derived(5);
	// ~Derived -> ~Base

/* #2 �������� ����ϴ� ���  -> ~Base�� ȣ��� 
	-> Derived�� �������� �����Ƿ� �޸� leak�� �߻�
	-> �ذ�� : �Ҹ��ڸ� virtual�� ����� �ȴ�.
	// ~Derived -> ~Base ������ ȣ��ȴ�.	
*/
	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;

	return 0;
}