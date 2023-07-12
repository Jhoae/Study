// 쓰레기 주소값을 de-referencing 하게되면
// 엉뚱한 값을 찾기 때문에 발생하는 문제를 방지하기위해
// NULL Pointer를 사용한다

#include <iostream>
#include <cstddef>

using namespace std;


void doSomething(double* ptr)
{

	cout << "address of pointer value in doSomething()" << &ptr << endl;


	if (ptr != nullptr)
	{
		// do something with *ptr
		cout << *ptr << endl;
	}
	else
	{
		// do nothing with ptr
		cout << "NULL ptr, do nothing" << endl;
	}
}

int main()
{

	/* NULL pointer를 정의하는 방법   */
	double* ptr = nullptr; // modern c++
	// double *ptr = NULL;
	// double *ptr{ nullptr }

	doSomething(ptr);
	doSomething(nullptr);

	double d = 123.4;

	doSomething(&d);

	double* ptr2 = &d;
	doSomething(ptr2);


	/*   std::nullptr_t       */
	std::nullptr_t nptr; // NULL pointer밖에 할당못함

	/*	pointer의 주소값	  */
	cout << "address of pointer value in main()" << &ptr << endl;

	return 0;
}