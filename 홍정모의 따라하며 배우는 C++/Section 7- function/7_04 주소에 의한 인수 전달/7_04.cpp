// call by Address
// -> 주소라는 "값"에 의한 전달.

#include <iostream>

using namespace std;

// typedef int* pint;
// void foo(pint ptr){}

void foo(int* ptr)
{
	cout << "*ptr: " << *ptr << "\tptr: " << ptr << "\t&ptr: " << &ptr << endl;
}

/* # const 사용법*/
void foo_const(const int* ptr)
{
	cout << "*ptr: " << *ptr << "\tptr: " << ptr << "\t&ptr: " << &ptr << endl;

	// *ptr = 10; :: ERROR
}


/* # 주소값을 이용한 출력 */
void getSinCos(double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}

/* pointer를 이용한 전달의 쓰임 */
void foo_pointer(const int *const ptr, int* arr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << "In func: " << arr[i] << endl;

	// 메모리 주소를 찾아가서 값을 변경하므로 밖에 영향을 준다.
	arr[0] = 1.0; 

	/*
	const는 변경 불가능 ->[]는 de - referencing이다.

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



/* # 주소값을 이용한 출력(값에 의한 전달)
     -> 함수에서 바꿔준 값이 밖에서도 영향을 준다.
	 (reference가 아님 -> 주소 확인)
*/
	double degrees = 30;
	double sin, cos;
	
	getSinCos(degrees, &sin, &cos);
	cout << "sin: " << sin << "\tcos: " << cos << endl;



/* pointer를 이용한 전달의 쓰임 */
	int arr[4]{ 0,0,0,0 };
	foo_pointer(arr, 4);

	for (int i = 0; i < 4; ++i)
		cout << "In main: " << arr[i] << endl;

	return 0;
}