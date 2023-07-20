#include <iostream>

using namespace std;

int foo(int x, int y);

int foo(int x, int y)
{
	return x + y;
// 지역변수 
// : 함수가 끝남과 동시에 x와 y의 메모리가 OS(운영체제)에 반납된다,

} 

int main() 
{
	int x = 1, y = 2;

	foo(6, 7); // 6,7 : 인자(arguments) (actual parameters == 실 매개변수, 실 인자)
	foo(x, y + 1);

	return 0;
}