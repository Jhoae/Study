/*
	�Լ�
	���ϰ�
	�Ű�����
	�μ�
*/


#include <iostream>

using namespace std;

int addTwoNumbers(int num_a, int num_b)
{
	int sum = num_a + num_b;

	return sum;
}

void printHelloWorld()
{
	cout << "Hello World " << endl;
}

int main()
{
	cout << addTwoNumbers(1, 2) << endl;
	addTwoNumbers(8, 13);
	int k = addTwoNumbers(3, 14);

	printHelloWorld();

	return 0;
}