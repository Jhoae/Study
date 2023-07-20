#include <iostream>
#include <array>
#include <functional>

using namespace std;

int func() { return 5; }
int goo() { return 10; }

int func_int(int x)
{
	return 5;
}


/* �Լ� pointer�� ���� */
bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}
bool isOdd(const int& number)
{
	if (number % 2 != 0) return true;
	else return false;
}

void printNumbers(const array<int, 10>& my_arr, bool print_even)
{
	for (auto element : my_arr)
	{
		if (print_even && element % 2 == 0) cout << "¦��: " << element;
		if (!print_even && element % 2 == 1) cout << "Ȧ��: " << element;
	}
	cout << endl;
}

void printNumbers_funcptr(const array<int, 10>& my_arr, bool (*check_fcn)(const int&))
{
	for (auto element : my_arr)
	{
		if (check_fcn(element) == true) cout << "_funcptr: " << element;
	}
	cout << endl;
}


void printNumbers_funcptr_default(const array<int, 10>& my_arr,
	bool (*check_fcn)(const int&) = isEven)
{
	for (auto element : my_arr)
	{
		if (check_fcn(element) == true) cout << "_funcptr_default: " << element;
	}
	cout << endl;
}

/* typedef�� Ȱ���Ͽ� ���̱� */
typedef bool (*check_fcn_t)(const int&);
void print_typedef(const array<int, 10>& my_arr,
	check_fcn_t check_fcn = isEven) {}

/* using�� Ȱ���Ͽ� ���̱� */
using check_fcn_u = bool(*)(const int&);
void print_using(const array<int, 10>& my_arr,
	check_fcn_u check_fcn = isEven) {}


/* C++11 std::functional */
void print_functional(const array<int, 10>& my_arr,
	std::function<bool(const int&)> check_fcn) 
{
	for (auto element : my_arr)
	{
		if (check_fcn(element) == true) cout << "_funcptr_functional: " << element;
	}
	cout << endl;
}


// main
int main()
{
/* �Լ� pointer */
	cout << "func�� �ּ� " << func << endl;
	func();


/* �Լ� pointer�� ��� */
	int(*fcnptr)() = func;
	cout << "fcnptr() " << fcnptr() << endl;

	fcnptr = goo;
	cout << "fcnptr() " << fcnptr() << endl;

	// �Ű������� �������
	int(*fcnptr_int)(int) = func_int;
	// fcnptr_int = goo; :: Error

	printf("\n");
/* �Լ� pointer�� ���� - �Լ� ������X */
	std::array<int, 10>my_arr = { 0,1,2,3,4,5,6,7,8,9 };

	printNumbers(my_arr, true);  // ¦��
	printNumbers(my_arr, false); // Ȧ��

	printf("\n");
/* �Լ� pointer�� ���� - 2 �Լ� ������ ��� */
	printNumbers_funcptr(my_arr, isEven);
	printNumbers_funcptr(my_arr, isOdd);


	printf("\n");
/* �Լ� pointer�� ���� - 3 �⺻�� �ֱ� */
	printNumbers_funcptr_default(my_arr);
	printNumbers_funcptr_default(my_arr, isOdd);




	printf("\n");
/* C++11 std::functional */
	std::function<bool(const int&)> fcnptr_11 = isEven;

	print_functional(my_arr, fcnptr_11);

	fcnptr_11 = isOdd;

	print_functional(my_arr, fcnptr_11);

	return 0;
}