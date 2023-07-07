#include <iostream>
#include <stdio.h>
#include <bitset>

int main()
{
	using namespace std;

	/* 	비트단위 연산자		*/
	// << left shift
	// >> right shift
	// ~, &, |, ^


	unsigned int a = 3;
	cout << std::bitset<4>(a) << " " << a << endl;

	unsigned int b = a << 1;
	cout << std::bitset<4>(b) << " " << b << endl;
	unsigned int c = a << 2;
	cout << std::bitset<4>(c) << " " << c << endl;

	// left shift
	// *2^n (2의 제곱 곱하기 처리)
	cout << std::bitset<8>(a) << " " << a << endl;
	cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
	cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
	cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
	cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl;


	// right shift
	// % 2^n (2의 제곱 나누기 처리)
	a = 1024;
	cout << std::bitset<16>(a) << " " << a << endl;
	cout << std::bitset<16>(a >> 1) << " " << (a >> 1) << endl;
	cout << std::bitset<16>(a >> 2) << " " << (a >> 2) << endl;
	cout << std::bitset<16>(a >> 3) << " " << (a >> 3) << endl;
	cout << std::bitset<16>(a >> 4) << " " << (a >> 4) << endl;

	printf("\n");
	// bitwise NOT ( ~ ) 
	cout << std::bitset<16>(a) << endl;
	cout << std::bitset<16>(~a) << " " << (~a) << endl;


	/* 	0b : 이진수 표현
		
	- bitwise 예시
	*/
	unsigned int d = 0b1100;
	unsigned int e = 0b0110;

	cout << d << " " << e << endl;
	
	cout << std::bitset<4>(d & e) << endl;
	cout << std::bitset<4>(d | e) << endl;
	cout << std::bitset<4>(d ^ e) << endl;


	// (a = a & b;) ==  (a &= b;)

	// Quiz
	unsigned int f = 0b0110;
	unsigned int g = 5;		// 0101
	unsigned int h = 12;	// 1100

	printf("\n");
	cout << f << endl;
	cout << std::bitset<4>(g & h) << endl;	// 0100
	cout << std::bitset<4>(g | h) << endl;	// 1101
	cout << std::bitset<4>(g ^ h) << endl;	// 1001

	return 0;
}