// Symbolic Constants
#include <iostream>
using namespace std;

void printNum(const int my_num)
{
	// 만약 값을 바꾸고 싶다면 이런식으로 ...
	int n = my_num;
	n = 456; 

	cout << my_num << endl;
}

int main()
{

	const double gravity{ 9.8 }; // const 로 고정
	// double const gravity{ 9.8 }; // 이 방식도 가능. 의미가 달라지는 경우도 있음
	// gravity = 1.2 // Error

	//
	// const double gravity; // const로 선언하면 반드시 초기화해주어야함 

/*	매개변수에 const가 들어가는 함수	*/
	printNum(123);	


/*	Compile time에 결정되는 상수 & Runtime에 결정되는 상수	*/
	const int my_const(123);		// Compile time에 결정되는 상수

	int number;
	cin >> number;
	const int special_number(number);	// Runtime에 결정되는 상수
	number = 123;
	//	special_number = 123 // Error


/*	constexpr::compile타임에 결정되는 상수		*/
	constexpr int compile_time_number(123);
	//	constexpr int compile_time_number(number); // Error


/*	Header파일 생성 :: 프로그램에 필요한 상수들을 모아서 정의 
					  -> 유지보수와 재사용성↑ */
#include "MY_CONSTANTS.h"
	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;


	return 0;
}