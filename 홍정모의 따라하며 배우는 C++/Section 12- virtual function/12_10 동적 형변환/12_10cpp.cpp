/* ���� ����ȯ
 �������� ����ϴٺ��� �ڽ� class�� pointer�� 
 �θ� class�� pointer�� �ٲ���ٰ�,
 �ٽ� �ڽ� class�� pointer�� �ٲ�� �� ��찡 �����.
 �̶� ����ϴ� ���� ����ȯ�̴�.
*/

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};


int main()
{
	Derived1 d1;
	d1.m_j = 2048;

	// .......

	Base* base = &d1;
	// Error: 	base->m_j;

/* #1 base�� �ٽ� Derived1���� ���� ����ȯ */
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << "base_to_d1->m_j:\t " 
		<< base_to_d1->m_j << endl;

	base_to_d1->m_j = 2222;

	cout << "d1.m_j:\t " << d1.m_j << endl;


/* #2 ������ �� - ������ �� ��� 
 - dynamic_cast�� runtime�� ��� �߻�,
 - static_cast�� ������� �о���δ�
*/

	Derived1 d1_2;
	Base* base_2 = &d1_2;

	auto* base_to_d2_d = dynamic_cast<Derived2*>(base_2);
	auto* base_to_d2_s = static_cast<Derived2*>(base_2);

	/*
	  #2-1 dynamic_cast
	   runtime���� error check�� ���־� ������ ����ش�.
	   -> "d Failed"
	*/
	if (base_to_d2_d != nullptr)
		base_to_d2_d->print();
	else
		cout << "d Failed" << endl;

	/*
	  #2-2 static_cast
	    static_cast�� runtime���� error check�� ���ϰ� �о���δ�.
        -> print()�Լ� ����
	*/
	if (base_to_d2_s != nullptr)
		base_to_d2_s->print();
	else
		cout << "s Failed" << endl;

	return 0;
}