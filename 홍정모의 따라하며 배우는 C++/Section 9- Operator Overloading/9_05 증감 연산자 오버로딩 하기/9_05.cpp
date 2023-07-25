// ���� ������ ::  ++, --
#include <iostream>
using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit=0) : m_digit(digit){}


/* #1 prefix ���� ������ */ 
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}
	Digit& operator -- ()
	{
		--m_digit;
		return *this;
	}


/* #2 postfix ���� ������ */
	Digit operator ++(int) // �Ű������� �ƹ��ų� ������ post�� ����
	{
		Digit temp(m_digit); // ���� ���� �ӽ� ����

		++(*this);

		return temp;
	}
	Digit operator --(int) 
	{
		Digit temp(m_digit); 

		--(*this);

		return temp;
	}



	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}
};

int main()
{ 

	
	int a = 10;
	cout << "++a:\t" << ++a << endl;
	cout << "a:\t" << a << endl;
	cout << "a++:\t" << a++ << endl;
	cout << "a:\t" << a << endl;

	printf("\n#1 prefix ���� ������\n");
/* #1 prefix ���� ������ */
	Digit d(5);

	cout << "++d:\t" << ++d << endl;
	cout << "d:\t" << d << endl;

	cout << "--d:\t" << --d << endl;
	cout << "d:\t" << d << endl;


	printf("\n#2 postfix ���� ������\n");
/* #2 postfix ���� ������ */
	cout << "d++:\t" << d++ << endl;
	cout << "d:\t" << d << endl;

	cout << "d--:\t" << d-- << endl;
	cout << "d:\t" << d << endl;

	return 0;
}