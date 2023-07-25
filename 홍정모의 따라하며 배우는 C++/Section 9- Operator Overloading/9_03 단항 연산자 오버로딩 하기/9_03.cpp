#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:

	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

/* #2 ���� ������ - */
	Cents operator -() const
	{
		return Cents(-m_cents);
	}
/* #3 ���� ������ ! */
	bool operator ! () const
	{
		// ���� :: 0 �̸� true ��ȯ�ϵ��� ����
		return (m_cents == 0) ? true : false;
	}


	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;

		return out;
	}
};

int main()
{
	Cents cents1(6);
	Cents cents2(0);

/* #1 ���� �����ڶ� */
	int a = 3;
	cout << "-a:\t" << -a << endl;
	cout << "!a:\t" << !a << endl;


	printf("\n#2 ���� ������ -\n");
/* #2 ���� ������ - */
	cout << "-cents1:\t" << -cents1 << endl;
	cout << "-Cents(-10):\t" << -Cents(-10)<< endl;


	printf("\n#3 ���� ������ !\n");
/* #3 ���� ������ ! */

	auto temp = !cents1;

	// ! ���� :: 0 �̸� true( == 1) ��ȯ�ϵ��� ����
	cout << "!cents1:\t" << !cents1 << endl;
	cout << "!cents2:\t" << !cents2 << endl;


}