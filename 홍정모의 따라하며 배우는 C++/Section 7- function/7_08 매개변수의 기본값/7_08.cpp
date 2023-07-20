#include <iostream>
#include <string>

using namespace std;



void print(int x = 0) // default parameter
{
	cout << "x: " << x << endl;
}

void print_3(int x = 10, int y = 20, int z = 30)
{
	cout << "x: " << x 
		<< ", y: " << z 
		<< ", z: " << z << endl;
}

/* 선언과 정의를 분리할 경우 (Header file을 사용할 경우)
	-> 둘중에 한곳에서만 기본값을 설정해야함*/

void print_sepa(int x = 10, int y = 20, int z = 30); // 선언
void print_sepa(int x, int y, int z) {} // 정의


/* 함수 overloading과 default value */
void print_od(std::string str) {}
void print_od(char ch = ' ') {}

void print_od2(int x) {}
void print_od2(int x, int y = 10) {}

int main()
{

/* default value */
	print(10);
	print();

	print_3();
	print_3(100);
	print_3(100, 200);
	print_3(100, 200, 300);


/* 함수 overloading과 default value */
	print_od(); // print_od(char)

	// print_od2(10); // ambiguous Error

	


	return 0;
}