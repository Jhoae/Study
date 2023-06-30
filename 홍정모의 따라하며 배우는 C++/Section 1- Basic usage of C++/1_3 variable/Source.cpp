/*
ㅁ객체 object :: 메모리에 저장되어 있는 정보가 객체로서 존재한다.

ㅁ변수 variables :: 문자로 된 주소.

ㅁLeft-values과 Right-values

ㅁ초기화initialization와 대입assignment

ㅁ초기화를 안 했을 때의 문제점 - Runtime Error & 메모리에 쓰레기값이 남을 수 있다.

*/

#include <iostream>

int main()
{
	// 초기화initialization
	int x = 123;

	// 대입assignment
	int y;
	y = 123;


	std::cout << x << std::endl;
	std::cout << &x << std::endl; // x의 주소값

	return 0;
}