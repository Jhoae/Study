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

	// (signed �� ��ȣǥ���� ��ȣ �� -1 // , 0�� ǥ���ϴ� �κ��� �� ��ȣ �� -1
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl; // 2^16 = 32767
	cout << std::numeric_limits<short>::max() << endl;		// +32767
	cout << std::numeric_limits<short>::min() << endl;		// -32768   //0ǥ�������� -1
	cout << std::numeric_limits<short>::lowest() << endl;	// -32768



	/*			OverFlow ���� �÷ο� �߻� ����			*/

	s = 32767;
	s = s + 1; // 32768
	cout << "32768? " << s << endl;	// -32768:: overflow���� �÷ο� �߻� 


	short k = std::numeric_limits<short>::min();
	cout << "short min() ? " << k << endl;	// -32768
	k = k - 1;
	cout << "min() -1 ? " << k << endl;	// 32767:: overflow���� �÷ο� �߻� 


	// unsigned int �����÷ο�


	unsigned int m = std::numeric_limits<unsigned int>::min();
	cout << "unsigned int min() ? " << m << endl;	// 0
	m = m - 1;
	cout << "min() -1 ? " << m << endl;	//  4294967295:: overflow���� �÷ο� �߻�


	// signed int �����÷ο�

	signed int n = std::numeric_limits<signed int>::min();
	cout << "unsigned int min() ? " << n << endl;	// -2147483648
	n = n - 1;
	cout << "min() -1 ? " << n << endl;	//  2147483647:: overflow���� �÷ο� �߻�


	// long �����÷ο�

	long p = std::numeric_limits<long>::min();
	cout << "long int min() ? " << p << endl;	// -2147483648
	p = p - 1;
	cout << "min() -1 ? " << p << endl;	//  2147483647:: overflow���� �÷ο� �߻�


	// long long �����÷ο�

	long long q = std::numeric_limits<long long>::min();
	cout << "long long int min() ? " << q << endl;	// -9223372036854775808
	q = q - 1;
	cout << "min() -1 ? " << q << endl;	//  9223372036854775807 overflow���� �÷ο� �߻�


	//  unsigned int z = -1 �� overflow

	unsigned int z = -1;
	cout << z << endl; // 4294967295:: overflow���� �÷ο� �߻�


	// int���� & flaot�� ������ ����� ����� ����
	int a = 22 / 4;
	cout << a << endl;					// 5   :: int ������ ����� ����� int
	cout << 22 / 4 << endl;				// 5
	cout << (float)22 / 4 << endl;		// 5.5 :: ���� �ϳ��� float�̶�� ������� float


	return 0;
}