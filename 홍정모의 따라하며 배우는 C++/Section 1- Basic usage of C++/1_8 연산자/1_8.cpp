/*
	리터럴 Literal
	피연산자 Operand
	단항 unary, 이항 binary, 삼항 ternary
*/

#include <iostream>

using namespace std;

int main() 
{
	int x = 2; // x는 변수, 2는 리터럴

	cout << x + 2 << endl; // x와 2는 피연산자
	cout << "Hello, World" << endl;

	/*
		조건연산자(Conditional operator)는
		C++ 언어의 유일한 삼항 연산자(Ternary operator)입니다.
	*/
	int y = (x > 0) ? 1 : 2;
	cout << y << endl;


	return 0;
}