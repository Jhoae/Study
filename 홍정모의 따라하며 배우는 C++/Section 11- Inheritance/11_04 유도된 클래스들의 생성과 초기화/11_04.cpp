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
/* #1 sizeof -> padding�� �߻��� 
   - �߿��Ѱ� Child class���� �޸� �Ҵ��Ҷ�, Mother class�� ����ִ°͵� 
     ��� ������ŭ, �޸� ����� ũ�� �Ҵ� �޴´ٴ� ��� */

	Child c1;

	cout << "sizeof(Mother):\t" << sizeof(Mother) << endl; // int�� 4 ����Ʈ
	cout << "sizeof(Child):\t" << sizeof(Child) << endl;   // 4(int)+4(float) = 8 



/* #2 �����ڿ� �Ҹ����� ���� */

	C c(1024, 3.14, 'a');

	// ������ : A -> B -> C
	// �Ҹ��� : C -> B -> A


	return 0;
}

