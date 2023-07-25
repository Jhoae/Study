#include <iostream>

using namespace std;

/* #1 변수명없이 클래스 사용하기 */
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



/* #2 좀 더 복잡한 용법 구현 */
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
	printf("객체 a\n");
	/* #1 변수명없이 클래스 사용하기 */
	A a(11);
	a.printDouble(); // 객체 a
	a.printDouble(); // 객체 a (같은 객체)


	printf("\n익명객체- A()이 R-Value 처럼 작동한다.\n");
	A(33).printDouble(); // 객체 1
	A(33).printDouble(); // 객체 2 (1과는 다른 객체)

	


	printf("\n#2 좀 더 복잡한 용법 구현\n");
	/* #2 좀 더 복잡한 용법 구현 */

	cout << "add(Cents(6), Cents(8)).getCents():\t" 
		<< add(Cents(6), Cents(8)).getCents() << endl;


	// operator overloading과 유사성을 가진다. 
	// 과연 캐스팅인가 ? 위 코드와 유사성을 생각해보자.
	cout << int(6) + int(8) << endl;

	return 0;
}