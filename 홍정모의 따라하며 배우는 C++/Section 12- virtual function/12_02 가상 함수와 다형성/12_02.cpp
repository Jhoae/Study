#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }

/* #1 pointer �ٲ��ֱ� -> overriding�� ������� */
	virtual void print_virt() { cout << "A_virt" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }

	void print_virt() { cout << "B_virt" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }

	void print_virt() { cout << "C_virt" << endl; }

};

class D : public C
{
public:
	void print() { cout << "D" << endl; }

/* #3 overriding�� �Ҷ� return Ÿ���� �ٸ� ��� 
      -> �� �� class�� �Լ� ��ȯ Ÿ�԰� ��ġ���� �ʴ´ٸ� ERROR�� �߻� */

	void print_virt() { cout << "D_virt" << endl; }
	// int print_virt() { cout << "D_virt" << endl; return 0; }
};



int main()
{
	A a;
	B b;
	C c;
	D d;

	a.print();
	b.print();
	c.print();
	d.print();

	printf("\n#1 pointer �ٲ��ֱ� \n");
/* #1 pointer �ٲ��ֱ� -> overriding�� ������� */

	A& ref = b;
	ref.print(); // A�� reference -> "A"
	
	ref.print_virt(); // virtual -> B���� overriding�� �Լ��� �״�� ��� -> "B_virt"

	A& ref_2 = c;
	ref_2.print_virt(); // "C_virt"

/* #2 ���� ���� class�� virtual�� �Ǹ� ���� class�� virtualó�� �ൿ�Ѵ� */

	B& ref = c; // B�� print_virt �Լ��� virtual�� �ƴ�
	ref.print_virt(); // "C_virt"

	return 0;
}