// Literal Constants
#include <iostream>

int main()
{
	using namespace std;

	float pi = 3.14f;	// f: float  , l: long
	int i = 123424u;	// u: unsigned
					
	int ui = (unsigned)123424;	


	// 정리 (예시)
	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e-10;

	// 10진수 Decimal: 0 1 2 3 4 5 6 7 8 9 10
	// 8진수 Octal: 0 1 2 3 4 5 6 7 10 11 12 13 ...
	// 16진수 Hexa: 0 1 2 3 4 5 6 7 8 9 A B C D E F 10

	
	int x = 012; // 앞에 0 을 붙이면 8진수 -> 출력값: 10
	cout << x << endl;

	int y = 0xF; // 앞에 0x 을 붙이면 16진수-> 출력값: 15
	cout << y << endl;

	int z = 0b1010; // 앞에 0b 을 붙이면 2진수 -> 출력값: 10
	cout << z << endl;

	int q = 0b1010'1111'1010; // 길어지면 이런식으로 끊어서 적기도 가능


	// Tip: 가급적 숫자 그자체보다는 상수로 바꿔두는것이 좋다
	const int price_per_item = 10;
	int num_items = 12;
//	int price = num_items * 10;
	int price = num_items * price_per_item;

	return 0;
}