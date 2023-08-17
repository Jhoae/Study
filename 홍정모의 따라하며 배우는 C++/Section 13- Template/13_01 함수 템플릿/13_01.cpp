#include <iostream>
#include "Cents.h"

using namespace std;

template<typename T> // template<class T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{

/* #1 template ����� */
	cout << getMax(1, 2) << endl;
	cout << getMax(3.14, 1.592) << endl;
	cout << getMax(1.0f, 3.4f) << endl;
	cout << getMax('a', 'c') << endl;


	printf("\n#2 user-defined data type (class)�� T�ڸ��� ���� �� �ִ�. \n");
/* #2 user-defined data type (class)�� T�ڸ��� ���� �� �ִ�. */
	cout << getMax(Cents(5), Cents(9)) << endl;



	return 0;
}