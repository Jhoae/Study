#include <iostream>

using namespace std;

int main()
{

	class Fraction
	{
	private:
		int m_default; 
		int m_numerator;   // 분자 
		int m_denominator; // 분모

	public: 

/* 생성자 Constructor->선언과 동시에 실행된다. 
         - default 생성자 : 기본값이 설정된 생성자 */
		Fraction(const int& num_input = 1, const int& den_input = 3) // 기본값 할당 방법 1
		{
			m_default = 1; // 기본값 할당 방법 2
			m_numerator = num_input;
			m_denominator = den_input;

			cout << "Fraction() Constructor" << endl;
		}

		void print()
		{
			cout << "m_numerator / m_denominator: " 
				<< m_numerator << " / " << m_denominator << endl;
		}
	};


/* 생성자를 정의하면 기본 생성자가 생성되지 않는다. 
   대신 매개변수 선언에서 기본값을 설정할 수 있다. */

	Fraction one_thirds;
	one_thirds.print();


/* copy initialization - 권장X */
	Fraction one_forth = Fraction{ 1,4 }; // 복사 된다
	one_forth.print();

/* (), {} 정의 차이점 
   - {}는 멤버들이 public일 경우 생성자 없이 사용 가능 
     & 생성자를 이용하더라도 타입에 좀더 엄격하다 */
	Fraction one_fifth1{ 1,3 };
	Fraction one_fifth2( 1,3 );

	/* 타입에 엄격하다
	   Error:  Fraction one_fifth1{ 1.0, 3 };
	      OK:  Fraction one_fifth2(1.0, 3); */


		  
	printf("\n");
/* class가 여러개 있을 경우*/

	class Second
	{
	public:
		Second()
		{
			cout << "Class Second" << endl;
		}
	};
	class First
	{
	private:
		Second sec;

	public:
		First()
		{
			cout << "Class First" << endl;
		}
	};

	First fir;
	// Debug시 "Class Second"가 "Class First" 보다 먼저 출력됨
	// -> second가 first의 멤버로 들어있기 때문에, 멤버를 먼저 초기화해줘야
	//    first를 작업 가능하기 때문에

	return 0;
}