#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0)
	{
		m_cents = cents;
	}

	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	/* #1 Error:: printInt(cents);
		-> 가능하게 만들기 위해선 typecasts를 overloading 해야한다.
	*/
	operator int()
	{
		cout << "cast operator" << endl;
		return m_cents;
	}
};

void printInt(const int& value)
{
	cout << "value" << value << endl;
}


int main()
{
	Cents cents(7);
	printInt(cents); // cast overloading후에 ERROR가 사라진다


	printf("\n#2\n");

	Cents cents2(7);
	/* 위와 같은 행동 */
	int value = (int)cents2;
	value = int(cents2);
	value = static_cast<int>(cents2);

	printInt(cents2);


	printf("\n#3 예제 - Dollar -> Cents\n");
	/* #3 예제 - Dollar -> Cents */
	class Dollar
	{
	private:
		int m_dollars = 0;

	public:
		Dollar(const int& input) : m_dollars(input) {}

		operator Cents()
		{
			return Cents(m_dollars * 100); // 1달러 = 100센트
		}
	};

	Dollar dol(2);

	Cents cents_3 = dol;

	printInt(cents_3);


	return 0;
}