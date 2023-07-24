#include <iostream>

using namespace std;

/* #1 */
class Something
{
public:
	static int s_value; // 모든 instance에서 접근가능. 한개의 주소값을 가짐
	int m_value;

public:
/* #2 static member function에선 this 키워드 사용불가 */
	static int getValue()
	{
		// ERROR :: return this->s_value; OR return s_value;
		// ERROR :: return this->m_value; OR return m_value;

		return s_value;
	}

	int get_this()
	{
		// this :: 특정 instance의 속한 member를 사용하는 것
		return this->s_value;
	}
};

// 정적 멤버 변수 초기화
int Something::s_value = 77;




/* #4 class안에 static member 변수를 초기화 하는법 */
class Class4
{
/* #4 Inner class 사용하여 static member variable 초기화*/
public:
	class _init
	{
	public:
		_init()
		{
			sc_value = 9999;
		}
	};

private:
	static int sc_value; // 모든 instance에서 접근가능. 한개의 주소값을 가짐
	int mc_value;

	static _init sc_initializer;


	/* #4 static member variable을 Constructor에선 초기화 불가능 */
public:
	Class4()
		: mc_value(123)
		// ERROR :: ,sc_value(1024),
		// -> 다른 방식(Inner class)으로 초기화 
	{}

	static int getValue()
	{
		// ERROR :: return this->s_value; OR return s_value;
		// ERROR :: return this->m_value; OR return m_value;

		return sc_value;
	}

	int get_this()
	{
		// this :: 특정 instance의 속한 member를 사용하는 것
		return this->sc_value;
	}
};

int Class4::sc_value = 1111;
Class4::_init Class4::sc_initializer;


int main()
{
	/* #1 특정 instance와 상관없이 실행시킬수 있다. */
	cout << "Something::s_value:\t" << Something::getValue() << endl;

	Something s1, s2;

	cout << "s1.getValue():\t" << s1.getValue() << endl;
	// cout << "s1.s_value" << s1.s_value << endl;


	printf("\n#3 member function의 pointer 가져오기\n");
/* #3 member function의 pointer 가져오기
	-> member function은 하나의 주소값을 갖는다 */

/* #3-1 일반 멤버 함수의 pointer */
	// ERROR :: int (Something:: * fptr1)() = s2.get_this;
	int (Something:: * fptr1)() = &Something::get_this;

	// ERROR :: cout << "(*fptr1)():\t" << (*fptr1)() << endl;
	
	// instance에 member function pointer를 넘겨주어 사용할 수 있다.
	// -> (instance에 종속되어있다.)
	cout << "(s2.*fptr1)():\t" << (s2.*fptr1)() << endl;

/* #3-2 static 멤버 함수의 pointer 
		-> 특정 instance와 상관없이 실행시킬수 있다. */

	// ERRROR :: int (Something:: * fptr2)() = &Something::getValue;

	// 특정 instance와 상관없이 실행시킬수 있다.
	int (* fptr2)() = &Something::getValue;

	cout << "fptr2():\t" << fptr2() << endl;




	printf("\n#4\n");
/* #4 static member variable을 Constructor에서 초기화 불가능 */

	Class4 c1, c2;
	cout << "c1.getValue():\t" << c1.getValue() << endl;

	return 0;
}