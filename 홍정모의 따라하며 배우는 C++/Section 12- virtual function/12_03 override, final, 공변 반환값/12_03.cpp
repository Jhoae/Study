#include <iostream>
using namespace std;

class A
{
public:
	virtual void print_virt(int x) { cout << "A_virt" << endl; }

/* #1 parameter�� �ٸ��� overriding�Ҽ��� ����*/
	virtual void print_override(int x) { cout << "A" << endl; }

/* #2 final Ű���� -> �� �̻� �ؿ��� override �Ұ��� */
	virtual void print_override2() { cout << "A" << endl; }

/* #3 ���� ��ȯ�� covariant return type */
	void print() { cout << "A" << endl; }
	virtual A* getThis() { cout << "A getThis" << endl; return this; }
};

class B : public A
{
public:

/* #1 parameter�� �ٸ��� overriding�Ҽ��� ����*/
	void print_virt(short x) { cout << "B" << endl; }

	void print_override(int x) override { cout << "B" << endl; }

/* #2 final Ű���� -> �� �̻� �ؿ��� override �Ұ��� */
	void print_override2() final { cout << "B" << endl; }

/* #3 ���� ��ȯ�� covariant return type
	-> �Ϲ������� return Ÿ���� �ٸ��� override�� �ȵ�����
	   A�� B�� �θ��ڽ� �����̱� ������, overriding�� �ȴ�. 	*/

	void print() { cout << "B" << endl; }
	virtual B* getThis() { cout << "B getThis" << endl; return this; }
};


class C : public B
{
public:
	virtual void print() { cout << "C" << endl; }

/* #2 final Ű���� -> �� �̻� �ؿ��� override �Ұ��� */
// Error: void print_override2() { cout << "C" << endl; }
};


int main()
{
	A a;
	B b;
//	C c;

/* #1 parameter�� �ٸ��� overriding�Ҽ��� ����*/
	A& ref = b;
	ref.print_virt(1); // �Լ��� parameter�� �ٸ��� overriding�Ҽ��� ����

/* #3 ���� ��ȯ�� covariant return type 
    -> �Ϲ������� return Ÿ���� �ٸ��� override�� �ȵ����� 
	   A�� B�� �θ��ڽ� �����̱� ������, overriding�� �ȴ�. 	*/
	A& ref2 = b;
	b.getThis()->print();   // *B->print();
	ref.getThis()->print(); 

	cout << "typeid(b.getThis()).name() :\t" 
		<< typeid(b.getThis()).name() << endl; 
	// "B getThis"
	// class B *

	cout << "typeid(ref.getThis()).name() :\t" 
		<< typeid(ref.getThis()).name() << endl; 
	// "B getThis"
	// class A *

	// -> ref�� A�̱⶧����, ref.getThis���� B�� pointer�� return���൵ �װ� �ٽ� A�� pointer�� 
	//    ���������� �ٲ۴����� print�� ȣ���ϴ� �����̴�.

	return 0;
}