#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;

	short s = 1;		// 2 bytes = 2 * 8 bits = 16 bits
	int i = 1;
	long l = 1;
	long long ll = 1;

	cout << sizeof(short) << endl;		// 2
	cout << sizeof(int) << endl;		// 4
	cout << sizeof(long) << endl;		// 4
	cout << sizeof(long long) << endl;	// 8

	// (signed 의 부호표현용 괄호 안 -1 // , 0을 표현하는 부분을 뺀 괄호 밖 -1
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl; // 2^16 = 32767
	cout << std::numeric_limits<short>::max() << endl;		// +32767
	cout << std::numeric_limits<short>::min() << endl;		// -32768   //0표현때문에 -1
	cout << std::numeric_limits<short>::lowest() << endl;	// -32768



	/*			OverFlow 오버 플로우 발생 예시			*/

	s = 32767;
	s = s + 1; // 32768
	cout << "32768? " << s << endl;	// -32768:: overflow오버 플로우 발생 


	short k = std::numeric_limits<short>::min();
	cout << "short min() ? " << k << endl;	// -32768
	k = k - 1;
	cout << "min() -1 ? " << k << endl;	// 32767:: overflow오버 플로우 발생 


	// unsigned int 오버플로우


	unsigned int m = std::numeric_limits<unsigned int>::min();
	cout << "unsigned int min() ? " << m << endl;	// 0
	m = m - 1;
	cout << "min() -1 ? " << m << endl;	//  4294967295:: overflow오버 플로우 발생


	// signed int 오버플로우

	signed int n = std::numeric_limits<signed int>::min();
	cout << "unsigned int min() ? " << n << endl;	// -2147483648
	n = n - 1;
	cout << "min() -1 ? " << n << endl;	//  2147483647:: overflow오버 플로우 발생


	// long 오버플로우

	long p = std::numeric_limits<long>::min();
	cout << "long int min() ? " << p << endl;	// -2147483648
	p = p - 1;
	cout << "min() -1 ? " << p << endl;	//  2147483647:: overflow오버 플로우 발생


	// long long 오버플로우

	long long q = std::numeric_limits<long long>::min();
	cout << "long long int min() ? " << q << endl;	// -9223372036854775808
	q = q - 1;
	cout << "min() -1 ? " << q << endl;	//  9223372036854775807 overflow오버 플로우 발생


	//  unsigned int z = -1 의 overflow

	unsigned int z = -1;
	cout << z << endl; // 4294967295:: overflow오버 플로우 발생


	// int끼리 & flaot를 포함한 계산의 결과값 차이
	int a = 22 / 4;
	cout << a << endl;					// 5   :: int 끼리의 계산은 결과도 int
	cout << 22 / 4 << endl;				// 5
	cout << (float)22 / 4 << endl;		// 5.5 :: 둘중 하나가 float이라면 결과값도 float


	return 0;
}