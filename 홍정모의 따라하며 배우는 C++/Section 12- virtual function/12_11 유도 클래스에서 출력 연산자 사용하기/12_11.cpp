// 다형성은 모든 경우에 사용할수는 없다. - 대표적으로 출력 연산자
// 출력 연산자를 다형성과 함께 사용하는 방법

#include <iostream>
using namespace std;


class Base
{
public:
	Base() {}


// frined function은 member가 아니다
// -> override 불가능
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

// print함수를 override
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
/* #1 실제로는 아니지만, 마치 output operator를 overriding한것처럼 작동 */

	Base b;
	cout << "Base b:\t" << b << endl; // Base

	Derived d;
	cout << "Derived d:\t" << d << endl; // Derived
	// note that this works even with no operator << that expli

	Base& bref = d;
	cout << "Base& bref:\t " << bref << endl; // Derived

	return 0;
}