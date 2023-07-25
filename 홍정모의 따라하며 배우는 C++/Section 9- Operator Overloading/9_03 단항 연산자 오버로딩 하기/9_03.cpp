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

/* #2 단항 연산자 - */
	Cents operator -() const
	{
		return Cents(-m_cents);
	}
/* #3 단항 연산자 ! */
	bool operator ! () const
	{
		// 예시 :: 0 이면 true 반환하도록 설정
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

/* #1 단항 연산자란 */
	int a = 3;
	cout << "-a:\t" << -a << endl;
	cout << "!a:\t" << !a << endl;


	printf("\n#2 단항 연산자 -\n");
/* #2 단항 연산자 - */
	cout << "-cents1:\t" << -cents1 << endl;
	cout << "-Cents(-10):\t" << -Cents(-10)<< endl;


	printf("\n#3 단항 연산자 !\n");
/* #3 단항 연산자 ! */

	auto temp = !cents1;

	// ! 예시 :: 0 이면 true( == 1) 반환하도록 설정
	cout << "!cents1:\t" << !cents1 << endl;
	cout << "!cents2:\t" << !cents2 << endl;


}