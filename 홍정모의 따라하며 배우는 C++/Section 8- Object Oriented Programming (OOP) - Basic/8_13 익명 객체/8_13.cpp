#include <iostream>

using namespace std;

/* #1 ��������� Ŭ���� ����ϱ� */
class A
{
public:
	int m_value;

	A(const int& input)
		: m_value(input){}

public:
	A()
	{
		cout << "Constructor" << endl;
	}

	~A()
	{
		cout << "Destructor" << endl;
	}

public:
	void printDouble()
	{
		cout << "m_value:\t" << m_value *2 << endl;
	}
};



/* #2 �� �� ������ ��� ���� */
class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}



int main()
{
	printf("��ü a\n");
	/* #1 ��������� Ŭ���� ����ϱ� */
	A a(11);
	a.printDouble(); // ��ü a
	a.printDouble(); // ��ü a (���� ��ü)


	printf("\n�͸�ü- A()�� R-Value ó�� �۵��Ѵ�.\n");
	A(33).printDouble(); // ��ü 1
	A(33).printDouble(); // ��ü 2 (1���� �ٸ� ��ü)

	


	printf("\n#2 �� �� ������ ��� ����\n");
	/* #2 �� �� ������ ��� ���� */

	cout << "add(Cents(6), Cents(8)).getCents():\t" 
		<< add(Cents(6), Cents(8)).getCents() << endl;


	// operator overloading�� ���缺�� ������. 
	// ���� ĳ�����ΰ� ? �� �ڵ�� ���缺�� �����غ���.
	cout << int(6) + int(8) << endl;

	return 0;
}