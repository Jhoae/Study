#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int getValue(int x)
{
	int value = x * 2;
	return value;
}

int* getValue_pointer(int x)
{
	int value = x * 2;
	return &value;
}

int& getValue_reference(int x)
{
	int value = x * 2;
	return value;
}


int* allocateMemory(int size)
{
	return new int[size];
}

int& get(std::array<int, 100>& my_array, int index)
{
	return my_array[index];
}

/* 여러개를 return 받기 - 구조체로 받기 */
struct S
{
	int a, b, c, d;
};
S getStruct()
{
	S my_s{ 1,2,3,4 };
	my_s.b = 3;

	return my_s;
}

/* 여러개를 return 받기 - 튜플 */
std::tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;

	return std::make_tuple(a, d);
}


// main
int main()
{
	int value = getValue(3);
	int *value_pointer = getValue_pointer(3);


/* design pattern */
	int* array = allocateMemory(1024);
	delete[] array;


/* return by reference */
	int value_ref = getValue_reference(5);
	cout << "value_ref: " << value_ref << endl;




/* return by reference의 쓰임 */
	std::array<int, 100> my_array;
	my_array[30] = 10;

	get(my_array, 30) = 1024;
	cout << "my_array[30]" << my_array[30] << endl;


/* 여러개를 return 받기 - 구조체 */
	S my_s = getStruct();


/* 여러개를 return 받기 - 튜플 */
	std::tuple<int, double> my_tp = getTuple();
	std::get<0>(my_tp); // a = 10
	std::get<1>(my_tp); // d = 3.14

	cout << "std::get<0>(my_tp): " << std::get<0>(my_tp) << endl;
	cout << "std::get<1>(my_tp): " << std::get<1>(my_tp) << endl;
	
	/* C++17
	auto [a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;	*/


	return 0;
}