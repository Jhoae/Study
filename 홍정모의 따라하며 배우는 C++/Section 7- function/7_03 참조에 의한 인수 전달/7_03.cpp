// ������ ���� ���� :: call by reference
// -> �Լ� �ۿ� ������ �ش�

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void addOne(int& b)
{
	cout << b << "\t&addOne: " << &b << endl;

	b = b + 1;
}

/* # �Լ��� ��� :: &�� �̿�, 
           �Է� :: �ַ� const�� �̿�(�Ǵ� const &�� �̿�) */

// void getSinCos(const double &degrees, double& sin_out, double& cos_out)
void getSinCos(const double degrees, double& sin_out, double& cos_out)
{
	static const double pi = 3.141592 / 180.0;

	const double radians = degrees * pi;

	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

/* # ���� */
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

/* # pointer�� ���� reference ������ */

// == (int*) &ptr
// typedef int * pint
// -> pint &ptr

void func_ptr(int*& ptr) 
{
	cout << "In func_ptr :: ptr: " << ptr << "\t&ptr: " << &ptr << endl;
}



/* # Array�� parameter�� �����ϴ� ��� */
void printElement(int (&arr)[4]) // �̰�쿣,�ݵ�� ������ ������
{}

// std::vector�� ����� ���
void printElement_vector(vector<int>& arr) {}

int main()
{
	int a = 5;
	cout << a << "\t & x: " << &a << endl;

	addOne(a);
	cout << a << "\t&x: " << &a << endl;


/* # �Լ��� ��� :: &�� �̿�,
	       �Է� :: �ַ� const�� �̿�(�Ǵ� const &�� �̿�) */

	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);
	cout << "\nsin: " << sin << "\t" << "cos: " << cos << endl;


/* # ���� */
	// foo_err(6) : ERROR 
	foo_fix(6);



/* # pointer�� ���� reference ������ */
	int x = 5;
	// pint ptr = &x;
	int* ptr = &x;

	func_ptr(ptr);
	cout << "In main:: ptr: " << ptr << "\t\t&ptr: " << &ptr << endl;



/* # Array�� parameter�� �����ϴ� ��� */
	int arr[]{ 1,2,3,4 };
	printElement(arr);



// std::vector�� ����� ���
	vector<int> arr_2{ 1,2,3,4 };
	printElement_vector(arr_2);

	return 0;
}