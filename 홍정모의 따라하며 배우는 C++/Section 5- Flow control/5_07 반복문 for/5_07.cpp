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

	// 2��° - �ۿ��� ���� ����ϴ� ��
	int count2 = 0;
	for (; count2 < 10; count2++)
	{
		cout << count2 << endl;
	}
	cout << count2 << endl;

	printf("\n");
	// ����
	cout << pow(2, 4);


	printf("\n");
	// ���ҵǴ� ���
	for (int count3 = 9; count3 >= 0; --count3)
	{
		cout << count3 << endl;
	}

	printf("\n");
	// �������� ���� ���
	for (int i = 0, j = 0; (i + j) < 10; ++i, j += 2)
	{
		cout << "i: " << i << "j: " << j << endl;
	}


	printf("\n");
	// ���� loop ���
	for(int k=0; k<9; ++k)
		for (int m = 0; m < 9; ++m)
		{
			cout << "m: " << m << " " << "k " << k << endl;
		}


	/* 	unsigned ����
	for (unsigned int i = 9; i >= 0; --i)
		cout << i << endl;
	*/ 


	return 0;
}