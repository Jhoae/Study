// 증감 연산자 ::  ++, --
#include <iostream>
using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit=0) : m_digit(digit){}


/* #1 prefix 증감 연산자 */ 
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


/* #2 postfix 증감 연산자 */
	Digit operator ++(int) // 매개변수에 아무거나 넣으면 post로 실행
	{
		Digit temp(m_digit); // 현재 값을 임시 저장

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

	printf("\n#1 prefix 증감 연산자\n");
/* #1 prefix 증감 연산자 */
	Digit d(5);

	cout << "++d:\t" << ++d << endl;
	cout << "d:\t" << d << endl;

	cout << "--d:\t" << --d << endl;
	cout << "d:\t" << d << endl;


	printf("\n#2 postfix 증감 연산자\n");
/* #2 postfix 증감 연산자 */
	cout << "d++:\t" << d++ << endl;
	cout << "d:\t" << d << endl;

	cout << "d--:\t" << d-- << endl;
	cout << "d:\t" << d << endl;

	return 0;
}