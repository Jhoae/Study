// ������ �ּҰ��� de-referencing �ϰԵǸ�
// ������ ���� ã�� ������ �߻��ϴ� ������ �����ϱ�����
// NULL Pointer�� ����Ѵ�

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

	/* NULL pointer�� �����ϴ� ���   */
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
	std::nullptr_t nptr; // NULL pointer�ۿ� �Ҵ����

	/*	pointer�� �ּҰ�	  */
	cout << "address of pointer value in main()" << &ptr << endl;

	return 0;
}