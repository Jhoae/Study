#include <iostream>

int main()
{
	using namespace std;

	bool bValue = false;

	char chValue = 'A';
	char chValueNum = 65;

	float fValue = 3.141592f;
	double dValue = 3.141592;

	auto aValue = 3.141592;	// 자동 double
	auto aValue2 = 3.141592f;	// 자동 float

	int a = 123;
	int b(123); // 위와 같음. direct initialization
	int c{ 123 }; // uniform initialization

	int d = (int)3.1415;	// copy initialization
	int e((int)3.14);

	int k = 0, l(456), m{ 123 };


	/*			cout	코드							*/	



	cout << bValue << endl;				// 0
	cout << (bValue ? 1 : 0) << endl;	// 0

	cout << chValue << endl;			// A
	cout << (int)chValue << endl;		// 65
	cout << chValueNum << endl;			// A

	cout << fValue << endl;				// cout 때문에 짤림
	cout << dValue << endl;				//

	cout << aValue << endl;				// double
	cout << aValue2 << endl;			// float
	
	cout << sizeof(aValue) << endl;		// 8
	cout << sizeof(aValue2) << endl;	// 4
	cout << sizeof(bool) << endl;		// 1
	cout << sizeof(char) << endl;		// 1


	return 0;
}