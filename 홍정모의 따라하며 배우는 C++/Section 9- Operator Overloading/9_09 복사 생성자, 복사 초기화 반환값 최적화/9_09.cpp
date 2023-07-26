#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:

	// 기본 생성자	
	Fraction(int num = 0, int den = 1)
		:m_numerator(num), m_denominator(den)
	{
		cout << "Default Constructor called" << endl;
		assert(den != 0);
	}

/* #1 복사 생성자 copy Constructor */
	Fraction(const Fraction &fraction) 
		:m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy Constructor called" << endl;
	}


	friend std::ostream& operator <<(std::ostream& out, const Fraction& f)
	{
		out << "\nf.m_numerator:\t" << f.m_numerator << endl;
		out << "f.m_denominator:\t" << f.m_denominator<< endl;
		out << f.m_numerator << " / " << f.m_denominator << endl;

		return out;
	}


};

/* #4 */
Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << "&temp:\t\t" << &temp << endl;
	return temp;
}


int main()
{
	Fraction frac(3, 5); // 기본 생성자 호출
	

	printf("\n#1 복사 생성자 copy Constructor\n");
/* #1 복사 생성자 copy Constructor */
	Fraction fr_copy(frac); // 복사 생성자 호출

	cout << "frac:\t" << frac << endl;
	cout << "fr_copy:\t" << fr_copy << endl;


	printf("\n#2 copy initialization -> 사용 방법은 다르지만 copy constructor가 똑같이 호출된다\n");
/* #2 copy initialization 
      -> 사용 방법은 다르지만 copy constructor가 똑같이 호출된다 */
	Fraction fr_copy_init = frac;



	printf("\n#3 Copy Constructor가 호출되지 않는다 -> Compiler가 불필요하다고 생각하면 생략한다\n");
/* #3 Copy Constructor가 호출되지 않는다
      -> Compiler가 불필요하다고 생각하면 생략한다 */
	Fraction fr_copy_2(Fraction(3, 10)); 




	printf("\n#4 return해주는 함수\n");
/* #4 return해주는 함수 
      ->Copy Constructor가 호출되지 않는다  
	  -> &result와 &temp의 주소값이 같다 */
	Fraction result = doSomething();
	cout << "&result:\t" << &result << endl;
	cout << "result:\t" << result << endl;

	return 0;
}