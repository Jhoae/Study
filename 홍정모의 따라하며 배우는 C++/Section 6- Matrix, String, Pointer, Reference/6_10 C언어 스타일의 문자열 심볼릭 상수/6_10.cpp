#include <iostream>

using namespace std;


const char* getName()
{
	return "Jackjack";
}


int main()
{
	// char name[] = "Jack Jack"; // OK
	// char *name = "Jack Jack"; // ERROR -> const �ʿ�
	const char *name = "Jack Jack";
	const char* name2 = "Jack Jack";
	const char* name3 = "Jack Jack3";
	const char* name4 = getName();
	const char* name5 = getName();


	cout << name << endl;
	cout << name2 << endl;

	// ���� literal�� �ּҸ� �����Ѵ�.
	cout << "(uintptr_t)name: " << (uintptr_t)name << endl;
	cout << "(uintptr_t)name2: " << (uintptr_t)name2 << endl;
	cout << "(uintptr_t)name3: " << (uintptr_t)name3 << endl;
	
	printf("\ngetName\n");
	cout << "(uintptr_t)name4: " << (uintptr_t)name4 << endl;
	cout << "(uintptr_t)name5: " << (uintptr_t)name5 << endl;


	printf("\n");
	/* 	���� pointer�� Ư�� - cout ���� ���ڿ��� Ư��ó���Ѵ�.			   */
	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";
	const char* name_a = "Jack Jack";

	cout << "int_arr: " << int_arr << endl;   // �ּ�
	cout << "char_arr: " << char_arr << endl; // ���ڿ�
	cout << "name_a: " << name_a << endl;     // ���ڿ�


	/* char�� �ּ� 
	   -> ���ڿ��̶�� �����ϰ� '\0'�� ���ö����� ���	*/
	char c = 'Q';
	cout << &c << endl;
	cout << *&c << endl;

	return 0;
}