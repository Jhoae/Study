// �������� ��� ��쿡 ����Ҽ��� ����. - ��ǥ������ ��� ������
// ��� �����ڸ� �������� �Բ� ����ϴ� ���

#include <iostream>
using namespace std;


class Base
{
public:
	Base() {}


// frined function�� member�� �ƴϴ�
// -> override �Ұ���
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

// print�Լ��� override
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
/* #1 �����δ� �ƴ�����, ��ġ output operator�� overriding�Ѱ�ó�� �۵� */

	Base b;
	cout << "Base b:\t" << b << endl; // Base

	Derived d;
	cout << "Derived d:\t" << d << endl; // Derived
	// note that this works even with no operator << that expli

	Base& bref = d;
	cout << "Base& bref:\t " << bref << endl; // Derived

	return 0;
}