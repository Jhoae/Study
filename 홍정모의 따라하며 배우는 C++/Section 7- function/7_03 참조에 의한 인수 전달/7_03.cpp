// 참조에 의한 전달 :: call by reference
// -> 함수 밖에 영향을 준다

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void addOne(int& b)
{
	cout << b << "\t&addOne: " << &b << endl;

	b = b + 1;
}

/* # 함수의 출력 :: &를 이용, 
           입력 :: 주로 const를 이용(또는 const &를 이용) */

// void getSinCos(const double &degrees, double& sin_out, double& cos_out)
void getSinCos(const double degrees, double& sin_out, double& cos_out)
{
	static const double pi = 3.141592 / 180.0;

	const double radians = degrees * pi;

	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

/* # 단점 */
void foo(int x)
{
	cout << x << endl;
}
void foo_err(int& x)
{
	cout << x << endl;
}
void foo_fix(const int& x)
{
	cout << x << endl;
}

/* # pointer에 대한 reference 보내기 */

// == (int*) &ptr
// typedef int * pint
// -> pint &ptr

void func_ptr(int*& ptr) 
{
	cout << "In func_ptr :: ptr: " << ptr << "\t&ptr: " << &ptr << endl;
}



/* # Array를 parameter로 전달하는 방법 */
void printElement(int (&arr)[4]) // 이경우엔,반드시 개수가 들어가야함
{}

// std::vector를 사용할 경우
void printElement_vector(vector<int>& arr) {}

int main()
{
	int a = 5;
	cout << a << "\t & x: " << &a << endl;

	addOne(a);
	cout << a << "\t&x: " << &a << endl;


/* # 함수의 출력 :: &를 이용,
	       입력 :: 주로 const를 이용(또는 const &를 이용) */

	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);
	cout << "\nsin: " << sin << "\t" << "cos: " << cos << endl;


/* # 단점 */
	// foo_err(6) : ERROR 
	foo_fix(6);



/* # pointer에 대한 reference 보내기 */
	int x = 5;
	// pint ptr = &x;
	int* ptr = &x;

	func_ptr(ptr);
	cout << "In main:: ptr: " << ptr << "\t\t&ptr: " << &ptr << endl;



/* # Array를 parameter로 전달하는 방법 */
	int arr[]{ 1,2,3,4 };
	printElement(arr);



// std::vector를 사용할 경우
	vector<int> arr_2{ 1,2,3,4 };
	printElement_vector(arr_2);

	return 0;
}