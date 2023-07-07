#include <iostream>


int add(int x, int y)
{
	return x + y;
}
auto Dadd(int x, int y)
{
	return x + (double)y;
}
auto subtract(int x, int y)
{
	return x - y;
}

// auto AutoAdd(auto x, auto y) { return a + b }; 
// parameter(매개변수) type에는 auto 키워드 사용 불가능
// 대신 template 을 사용가능


// 자취를 남긴다 - 코드 정리용 
auto Tadd(int x, int y) -> int
{
	return x + y;
}


int main()
{
	using namespace std;

	auto a = 123;	// 자료형을 추론하여 스스로 정하게 만들기.
	// auto b;		// 초기화를 하지않으면 auto 키워드 사용불가
	auto b = 123.0;
	auto c = 1 + 2.0;

	auto result = add(1, 2);		// 함수 int  , 결과 int
	auto result = Dadd(1, 2);		// 함수 auto , 결과 double
	auto result2 = subtract(3, 2);	// 함수 auto , 결과 int

	return 0;
}