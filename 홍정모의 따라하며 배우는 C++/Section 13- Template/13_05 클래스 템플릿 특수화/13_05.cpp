#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template<typename T>
class A
{
public:
	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};


/* #1 char type에 대해서만 specialization */
template<>
class A<char>
{
public:
	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};



/* #2 생성자를 구현하여 <>사라지게 만들기 */
template<typename T_2>
class A_2
{
public:
	A_2(const T_2& input)
	{}

	void doSomething()
	{
		cout << typeid(T_2).name() << endl;
	}

	void test()
	{}
};

template<>
class A_2<char>
{
public:
	A_2(const char &temp)
	{}

	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	A<int> a_int;
	A<double> a_double;
	A<char> a_char;

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething(); // #1 

	a_int.test();
	a_double.test();
	// Error: a_char.test();  -->>  상속과 다르다.
	
	
/* #2 생성자를 구현하여 <>사라지게 만들기 -->> C++17 에서는 컴파일 오류가 발생 X */
	A_2<int> a_int_2(1);
	A_2<double> a_double_2(3.14);
	A_2<char> a_char_2('c');

	a_int_2.doSomething();
	a_double_2.doSomething();
	a_char_2.doSomething(); 
	 
	// 정수용 Storage8 정의 Define a Storage8 for integers
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		std::cout<<intStorage.get(count) <<'\n';

	cout << "Sizeof Storage8<int>" << sizeof(Storage8<int>)<< endl;

/* #3 Define a Storage8 for bool. (specialization) */
	Storage8<bool> boolStorage;
	
	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);


	for (int count = 0; count < 8; ++count)
		std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';

	cout << "Sizeof Storage8<bool>" << sizeof(Storage8<bool>) << endl;

	return 0;
}