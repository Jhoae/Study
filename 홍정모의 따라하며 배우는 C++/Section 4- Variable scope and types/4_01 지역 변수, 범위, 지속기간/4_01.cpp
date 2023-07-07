#include <iostream>


namespace work1
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

namespace work2
{

	int a = 3;
	void doSomething()
	{
		a += 5;
	}
}

namespace work3::work4::work5::work6
{
	int a = 6;
	void doSomething()
	{}
}

int main()
{
	using namespace std;


	/*	Scope	  */
	// apple = 1; : Error
	int apple = 5;
	apple = 1;
	cout << apple << endl;		// 1
	
	{
		apple = 3;
		cout << apple << endl;	// 3
	}

	cout << apple << endl;		// 3


	// <- 위의 상황과 다름. ->
	int banana = 5;
	cout << banana << endl;		// 5
	{	
		int banana = 3;
		cout << banana << endl;	// 3
	}
	cout << banana << endl;		// 5



	work1::a;
	work1::doSomething();


	work2::a;
	work2::doSomething();
	
	work3::work4::work5::work6::a;
	work3::work4::work5::work6::doSomething();

	return 0;
}

// apple = 3;  : Error