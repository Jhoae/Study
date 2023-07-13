#include <iostream>

using namespace std;

// void doSomething(int n) -> main에 영향X
// void doSomething(const int& n) // -> main에 영향X
void doSomething(int& n) // -> main에 영향O
{
	n = 10;
	cout << "In doSomething n: " << n << endl;
	cout << "In doSomething &n: " << &n << endl;
}

// void printElements(const int(&arr)[5]) // []안에 반드시 숫자를 넣어야 한다
void printElements(int (&arr)[5]) // []안에 반드시 숫자를 넣어야 한다
{
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int value = 5;

	/* pointer를 사용하는 코드 */
	int* ptr = nullptr;
	ptr = &value;

	/* ref를 사용하는 코드 */
	int& ref = value;

	cout << "ref:\t" << ref << endl;

	ref = 10;
	cout << "value:\t" << value << endl;
	cout << "ref:\t" << ref << endl;

	printf("\n");
	cout << "&value\t" << &value << endl;
	cout << "&ref\t" << &ref << endl;
	cout << "ptr\t" << ptr << endl;
	cout << "&ptr\t" << &ptr << endl;


	/* 참조의 특징    */
	// Error: int& ref; -> 반드시 초기화되어야한다.
	// int& ref = 104; -> literal이 할당될수없다

	// 1
	int x = 5;
	int& ref_x = x;


	// 2
	const int y = 8;
	// Error: int& ref_y = y; -> const를 할당할수 없다
	const int& ref_y = y; // OK



	// 3
	printf("\n");
	int value_1 = 5;
	int value_2 = 10;

	int& ref_1 = value_1;

	cout << "ref_1== value_1\t" << ref_1 << endl;

	ref_1 = value_2;

	cout << "ref_1== value_2\t" << ref_1 << endl;

	printf("\n");
	/* 함수의 매개변수에 ref가 들어가는 경우 */
	int n = 5;
	cout << "n: " << n << endl;

	doSomething(n);
	cout << "main의 n: " << n << endl;
	cout << "main의 &n: " << &n << endl;



	/*  Array를 함수에 넣어줄때도 ref를 사용 가능	 */
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElements(arr);


	printf("\n");
	/*  struct에서도 ref를 사용 가능	 */
	struct Something
	{
		int v1;
		float v2;
	};
	struct Other
	{
		Something st;
	};

	Other ot;
	ot.st.v1 = 1;

	// ref를 사용한다면
	int& v1 = ot.st.v1;
	v1 = 1;


	/* ref와 pointer 비교			   */


	int value_a = 5;

	// 아래 2방식이 동일하다.
	int* const ptr_a = &value_a;
	int& ref_a = value_a;
	
	// 아래 2방식이 동일하다.
	*ptr_a = 10;
	ref_a = 10;

	return 0;
}