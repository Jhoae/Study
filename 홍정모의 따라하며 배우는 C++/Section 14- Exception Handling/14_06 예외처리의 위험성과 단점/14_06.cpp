#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
/* #2 소멸자 안에서 throw는 금지*/
		// throw "error";
	}
};

int main()
{
	try
	{
/* #1 문제점1. 메모리 처리가 안되서 메모리 누수가 발생할 수 있다.*/
		int* i = new int[1000000];

		unique_ptr<int> up_i(i); // 해결: unique pointer는 delete할 필요가 없어진다.

		// do something with i
		throw "error";

		// delete[] i;

/* #2 주의사항 : 소멸자 안에서 throw는 금지*/
		A a;
	}
	catch (...)
	{
		cout << "main() Catch" << endl;
	}

	return 0;
}
