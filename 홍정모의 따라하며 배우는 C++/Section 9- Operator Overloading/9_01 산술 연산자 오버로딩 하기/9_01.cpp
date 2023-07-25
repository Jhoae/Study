#include <iostream>
using namespace std;

/* #1 불편한 방법으로 class 산술연산 */
class Cents
{
private:
	int m_cents;

public:

	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	
	int& getCents() { return m_cents; } 
	// 멤버 변수 m_cents에 대한 참조를 반환하므로, 
	//객체의 내부 상태를 수정할 수 있습니다. 

/* #4 연산자 overloading을 member function으로 구현
	  -> getCents없이도 출력가능하게 만듦 
	  -> friend 키워드 사용 */
	Cents operator +(const Cents& c2)
	{
		return Cents(this->m_cents + c2.m_cents);
	}


/* #5 member function으로만 overloading이 가능한 연산자들 
* =, [index], (), -> 
*/
};

void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.getCents() = c1.getCents() + c2.getCents();
}


/* #2 산술연산자 있는 버젼의 add function*/
Cents add_2(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

/* #3 operator +를 이용한 add */
Cents operator +(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}




int main()
{
/* #1 불편한 방법으로 class 산술연산 */
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	add(cents1, cents2, sum);

	cout << "sum.getCents():\t" << sum.getCents() << endl;
	
	//  ?:  ::  sizeof  .  .*



/* #2 산술연산자 있는 버젼의 add function*/
	cout << "add_2(cents1, cents2).getCents():\t" 
		<< add_2(cents1, cents2).getCents() << endl;




/* #3 operator +를 이용한 add */
	cout << "(cents1 + cents2 + Cents(6)).getCents():\t" 
		<< (cents1 + cents2 + Cents(6)).getCents() << endl;



/* #4 friend 키워드 사용*/
	cout << "(cents1 + cents2 + Cents(6) + Cents(100)):\t"
		<< (cents1 + cents2 + Cents(6) + Cents(100)).getCents() << endl;

	return 0;
}