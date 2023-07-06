#include <iostream>

int main()
{
	using namespace std;

	int x = 7;
	int y = 2;
	int z = x % y; // % : 나머지 연산자

	cout << x / y << " " << z << endl;

	/*	정수 나누기와 실수 나누기의 결과값이 다르다.		 */

	cout << x / y << endl;					// 3
	cout << float(x) / y << endl;			// 3.5
	cout << x / float(y) << endl;			// 3.5
	cout << float(x) / float(y) << endl;	// 3.5


	cout << -5 / 2 << endl; // -2
	cout << -5 % 2 << endl; // -1


	/*	 */		
	int k = x;
	k += y;		// k = k + y
	k -= y;		// k = k - y
	k /= y;		// k = k / y
	k %= y;		// k = k % y

	return 0;
}