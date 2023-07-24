#include <iostream>

using namespace std;

/* #1 멤버 변수를 static으로 선언*/
class Something
{
public:
	// ERROR:: static int m_value = 1;
	static int s_value;
	static const int c_value = 22; // static const일 경우 이곳에서 초기화
	static constexpr int ct_value = 33; // compile time에 결정되는 경우
};

int Something::s_value = 77; // static member일 경우 헤더파일보단 cpp파일에 정의하는것이 좋음 -> compile 에러 방지

int main()
{
/* #1 멤버 변수를 static으로 선언*/
	printf("#1 멤버 변수를 static으로 선언\n");
	
	
	cout << "instance 생성전 Something::s_value:\t" << Something::s_value << endl;
	cout << "instance 생성전 &Something::s_value:\t" << &Something::s_value << endl;

	Something st1;
	Something st2;

	st1.s_value = 2;

	cout << "st1.m_value:\t" << st1.s_value << endl;
	cout << "&st1.m_value:\t" << &st1.s_value << endl;

	cout << "st2.m_value:\t" << st2.s_value << endl;
	cout << "&st2.m_value:\t" << &st2.s_value << endl;


	printf("\n");
	Something::s_value = 1024;
	cout << "Something::s_value = 1024이후 Something::s_value:\t" << Something::s_value << endl;
	cout << "Something::s_value = 1024이후 &Something::s_value:\t" << &Something::s_value << endl;


	return 0;
}