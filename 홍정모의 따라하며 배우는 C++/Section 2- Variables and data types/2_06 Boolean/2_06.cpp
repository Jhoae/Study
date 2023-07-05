#include <iostream>

bool isEqual(int a, int b) {
	bool result = (a == b);
	return result;
}
bool isOdd(int a) {
	if (a % 2 == 1) // 홀수
		return true;
	else 
		return false;
}

int main()
{
	using namespace std;

	bool b1 = true;		// copy initialization
	bool b2(false);		// direct initialization
	bool b3{ true };	// uniform initialization
	b3 = false;

	cout << b3 << endl;	// 0
	cout << b1 << endl;	// 1
	printf("\n");

	cout << std::boolalpha;
	cout << b3 << endl;	// false
	cout << b1 << endl;	// true
	printf("\n");

	cout << !true << endl;	// false
	cout << !false << endl;	// true
	printf("\n");

	cout << (true && true) << endl;		// t
	cout << (true && false) << endl;	// f
	cout << (false && true) << endl;	// f
	cout << (false && false) << endl;	// f
	printf("\n");

	cout << (true || true) << endl;		// t 
	cout << (true || false) << endl;	// t
	cout << (false || true) << endl;	// t
	cout << (false || false) << endl;	// f

	if (true)
	{
		cout << "This is true" << endl;
		cout << "True second line" << endl;
	}

	if (false)
		cout << "NO WORK" << endl;
	else
		cout << "This is false" << endl;
	
	if (5) // 0 이면 false, 나머지는 모두 true
	{
		cout << "True" << endl;
	}
	else cout << "False" << endl;
	
	printf("\n");


	cout << isEqual(1, 1) << endl; // t
	cout << isEqual(0, 3) << endl; // f
	printf("\n");

	cout << isOdd(1) << endl;
	cout << isOdd(2) << endl;

	return 0;
}
