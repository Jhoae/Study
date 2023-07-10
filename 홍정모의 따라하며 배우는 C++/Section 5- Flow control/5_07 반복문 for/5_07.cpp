#include <iostream>

int pow(int base, int exponent)
{
	int result = 1;

	for (int count = 0; count < exponent; count++)
		result *= base;


	return result;
}


int main()
{
	using namespace std;

	for (int count = 0; count < 10; count++)
	{
		cout << count << endl;
	}
	printf("\n");

	// 2번째 - 밖에서 변수 사용하는 법
	int count2 = 0;
	for (; count2 < 10; count2++)
	{
		cout << count2 << endl;
	}
	cout << count2 << endl;

	printf("\n");
	// 제곱
	cout << pow(2, 4);


	printf("\n");
	// 감소되는 경우
	for (int count3 = 9; count3 >= 0; --count3)
	{
		cout << count3 << endl;
	}

	printf("\n");
	// 여러개의 변수 사용
	for (int i = 0, j = 0; (i + j) < 10; ++i, j += 2)
	{
		cout << "i: " << i << "j: " << j << endl;
	}


	printf("\n");
	// 이중 loop 사용
	for(int k=0; k<9; ++k)
		for (int m = 0; m < 9; ++m)
		{
			cout << "m: " << m << " " << "k " << k << endl;
		}


	/* 	unsigned 주의
	for (unsigned int i = 9; i >= 0; --i)
		cout << i << endl;
	*/ 


	return 0;
}