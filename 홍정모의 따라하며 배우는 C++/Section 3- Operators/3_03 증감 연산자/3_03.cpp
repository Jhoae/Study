#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	using namespace std;

	int x = 5;
	int y = --x;
	int z = x--;

	cout << y << endl;
	cout << z << endl;


	/*				*/
	int a = 6, b = 6;
	cout << a << " " << b << endl;		// 6 6
	cout << ++a << " " << --b << endl;	// 7 5

	a = 6, b = 6;
	cout << a++ << " " << b-- << endl;	// 6 6

	a = 6, b = 6;
	cout << a << " " << b << endl;		// 6 6
	cout << ++a << " " << --b << endl;	// 7 5
	cout << a << " " << b << endl;		// 7 5
	cout << a++ << " " << b-- << endl;	// 7 5
	cout << a << " " << b << endl;		// 8 4


	int v = 1;
	int s = 2;
	int e = 3;
	cout << add(v, ++v) << endl;		// 4 <--- ?? do not use
	cout << add(e, ++s) << endl;		// 6

	return 0;
}