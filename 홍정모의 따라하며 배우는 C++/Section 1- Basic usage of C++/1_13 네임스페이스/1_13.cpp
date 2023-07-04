#include <iostream>
using namespace std;

namespace MySpace1 
{
	int doSomething(int a, int b)
	{
		return a + b;
	}
}

namespace MySpace2
{
	int doSomething(int a, int b)
	{
		return a * b;
	}
}

int main()
{
	using namespace MySpace1;
	doSomething(3, 4);

	//cout << MySpace1::doSomething(3, 4) << endl;
	//cout << MySpace2::doSomething(3, 4) << endl;


	return 0;
}