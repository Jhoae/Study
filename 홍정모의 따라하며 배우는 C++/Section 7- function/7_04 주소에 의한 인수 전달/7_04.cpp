// call by Address
// -> �ּҶ�� "��"�� ���� ����.

#include <iostream>

using namespace std;

// typedef int* pint;
// void foo(pint ptr){}

void foo(int* ptr)
{
	cout << "*ptr: " << *ptr << "\tptr: " << ptr << "\t&ptr: " << &ptr << endl;
}

/* # const ����*/
void foo_const(const int* ptr)
{
	cout << "*ptr: " << *ptr << "\tptr: " << ptr << "\t&ptr: " << &ptr << endl;

	// *ptr = 10; :: ERROR
}


/* # �ּҰ��� �̿��� ��� */
void getSinCos(double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}

/* pointer�� �̿��� ������ ���� */
void foo_pointer(const int *const ptr, int* arr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << "In func: " << arr[i] << endl;

	// �޸� �ּҸ� ã�ư��� ���� �����ϹǷ� �ۿ� ������ �ش�.
	arr[0] = 1.0; 

	/*
	const�� ���� �Ұ��� ->[]�� de - referencing�̴�.

	*ptr = 1; :: ERROR

	 int x = 1;
	 ptr = &x; :: ERROR
	*/
}

int main()
{
	int value = 5;
	cout << "value: " << value << "\t&value: " << &value << endl;

	int* ptr = &value;

	cout << "In main &ptr: " << &ptr << endl;

	foo(ptr);
	foo(&value);
	// foo(5) // :: ERROR



/* # �ּҰ��� �̿��� ���(���� ���� ����)
     -> �Լ����� �ٲ��� ���� �ۿ����� ������ �ش�.
	 (reference�� �ƴ� -> �ּ� Ȯ��)
*/
	double degrees = 30;
	double sin, cos;
	
	getSinCos(degrees, &sin, &cos);
	cout << "sin: " << sin << "\tcos: " << cos << endl;



/* pointer�� �̿��� ������ ���� */
	int arr[4]{ 0,0,0,0 };
	foo_pointer(arr, 4);

	for (int i = 0; i < 4; ++i)
		cout << "In main: " << arr[i] << endl;

	return 0;
}