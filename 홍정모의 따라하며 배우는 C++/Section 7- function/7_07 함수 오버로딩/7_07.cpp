#include <iostream>

using namespace std;

/* 함수 오버로딩의 사용 - 매개변수가 달라야 한다. return타입으로는 구분이 안된다.
	-> 컴파일 할때 어느 함수를 사용할지 결정된다 */

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

/* reference를 사용하여 회피하는 방법 */
void getRandom(int &x) {}
void getRandom(double &x) {}



/* typedef를 쓰더라도 눈속임을 할순 없다 */
typedef int my_int;

void print(int x) {}
// == void print(my_int x) {}



/* match가 정확히 안될때 -1 */
void print_m(const char* value) {}
void print_m(int value) {}


/* match가 정확히 안될때 -2 */
void print_f(unsigned int value){}
void print_f(float value) {}

int main()
{

/* 함수 오버로딩의 사용 
	-> 컴파일 할때 어느 함수를 사용할지 결정된다 */
	add(1, 2);
	add(3.1, 4.2);


/* reference를 사용하여 회피하는 방법 */
	int x;
	getRandom(x);
	// int x = getRandomInt(x);  // 함수명 변경
	// int x = getRandom(int()); // return타입으로는 구분이 안된다.


/* match가 정확히 안될때 - 1 :: 매치가 안될때 */
	print_m(0);	  // print_m(int)
	print_m('a'); // print_m(int)
	print_m("a"); // print_m(const char*)
	// 만약 print_m이 (const가 아니라 char *)이라면
	// print_m("a"); -> Error


/* match가 정확히 안될때 -2 :: 둘다 가능(모호할떄) */
	// print_f('a');		// ambiguous Error
	// print_f(0);			// ambiguous Error
	// print_f(3.141592);	// ambiguous Error

	print_f((unsigned int)'a');
	print_f(0u);
	print_f(3.141592f);

	return 0;
}