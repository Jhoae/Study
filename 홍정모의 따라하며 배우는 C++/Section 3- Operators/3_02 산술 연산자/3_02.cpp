#include <iostream>

int main()
{
	using namespace std;

	int x = 7;
	int y = 2;
	int z = x % y; // % : ������ ������

	cout << x / y << " " << z << endl;

	/*	���� ������� �Ǽ� �������� ������� �ٸ���.		 */

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