#include <iostream>

namespace a
{
	int my_var(10);
	int my_a(123);
}

namespace b
{
	int my_var(20);
	int my_b(123);
}

namespace c
{
	int my_val(10);
	int my_c(123);
}

namespace d
{
	int my_val(20);
	int my_d(123);
	int count(123123);
}


int main()
{
	using namespace std;
	/* 	
	using std::cout;
	using std::endl; 	*/

	using namespace a;
	using namespace b;

	cout << my_a << endl;
	cout << my_b << endl;

	cout << a::my_var << endl; 
	cout << b::my_var << endl;


	/*	또는  */

	{
		using namespace c;
		cout << my_val << endl;
	}

	{
		using namespace d;
		cout << my_val << endl;
		// cout << count << endl; // 모호성 ambiguous
		cout << d::count << endl;
	}

	return 0;
}