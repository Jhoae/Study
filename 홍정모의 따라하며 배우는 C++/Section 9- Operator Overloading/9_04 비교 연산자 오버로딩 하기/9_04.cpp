// �� ������
// ==, !=, >, >= ...

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Cents
{
private:
	int m_cents;

public:

	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }	
	int& getCents() { return m_cents; }


/* #1 == ������ overloading*/
	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}


/* #2 != ������ overloading*/
	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}


/* #3 sorting -> Cents������ ũ��� �����ڰ� �ʿ���( "<"�� ����ؾ��� ) */
	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
		// return c1.m_cents > c2.m_cents; �ÿ� ������
	}


	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;

		return out;
	}
};


int main()
{

/* #1 == ������ overloading*/
	Cents cents1(6);
	Cents cents2(0);

	if (cents1 == cents2)
		cout << "Equal" << endl;


/* #2 != ������ overloading*/
	if (cents1 != cents2)
		cout << "Not equal" << endl;

/* #3 sorting -> Cents������ ũ��� �����ڰ� �ʿ��� */
	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i;

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(arr.begin(), arr.end(), g);


	for (auto& e : arr)
		cout << e << " ";
	cout << endl;


	std::sort(begin(arr), end(arr));

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	return 0;
}