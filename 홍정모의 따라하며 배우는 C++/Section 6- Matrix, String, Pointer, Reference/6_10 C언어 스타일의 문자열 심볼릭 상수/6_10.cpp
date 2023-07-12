#include <iostream>

using namespace std;


const char* getName()
{
	return "Jackjack";
}


int main()
{
	// char name[] = "Jack Jack"; // OK
	// char *name = "Jack Jack"; // ERROR -> const 필요
	const char *name = "Jack Jack";
	const char* name2 = "Jack Jack";
	const char* name3 = "Jack Jack3";
	const char* name4 = getName();
	const char* name5 = getName();


	cout << name << endl;
	cout << name2 << endl;

	// 같은 literal은 주소를 공유한다.
	cout << "(uintptr_t)name: " << (uintptr_t)name << endl;
	cout << "(uintptr_t)name2: " << (uintptr_t)name2 << endl;
	cout << "(uintptr_t)name3: " << (uintptr_t)name3 << endl;
	
	printf("\ngetName\n");
	cout << "(uintptr_t)name4: " << (uintptr_t)name4 << endl;
	cout << "(uintptr_t)name5: " << (uintptr_t)name5 << endl;


	printf("\n");
	/* 	문자 pointer의 특성 - cout 에서 문자열을 특별처리한다.			   */
	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";
	const char* name_a = "Jack Jack";

	cout << "int_arr: " << int_arr << endl;   // 주소
	cout << "char_arr: " << char_arr << endl; // 문자열
	cout << "name_a: " << name_a << endl;     // 문자열


	/* char의 주소 
	   -> 문자열이라고 가정하고 '\0'가 나올때까지 출력	*/
	char c = 'Q';
	cout << &c << endl;
	cout << *&c << endl;

	return 0;
}