#include <iostream>

using namespace std;

int min(int x, int y)
{
	/*
	if (x > y) 		return y;
	else 		return x;
	*/

	// ���� ������
	return (x > y) ? y : x;
}

int main()
{

	/*	���ǹ� if ����		*/
	int a;
	cin >> a;

	if (a > 10)
	{
		cout << a << " is greater than 10" << endl;
		cout << "Test 1" << endl;
	}
	else 
		cout << a << " is greater NOT than 10" << endl;

	/*	if�� ����	*/
	int b;
	cin >> b;

	if (0) {}  //  == if(false)
	if (1) // == if (true)
	{
		int b = 5;
	}
	else
		int b = 6;
	cout << b << endl; // ����� ?? ===> {}���� ����� int b=5�� ������Ƿ� cin�� ���


	/*	chain		*/
	int c;
	cin >> c;


// Ȱ�� 1
	if (c > 10)
		cout << "c is greater than 10" << endl;
	else if (c < 10)
		cout << "c is less than 10" << endl;
	else if (c == 10)
		cout << "c is 10" << endl;


// Ȱ�� 2
	if (c > 10)
		cout << "c is greater than 10" << endl;
	else
	{
		if (c < 10)
			cout << "c is less than 10" << endl;
		else // if ( c== 10)
			cout << "c is 10" << endl;
	}

	
// Ȱ�� 3
	int d;
	cin >> d;
	if (d >= 10)
	{
		if (d <= 20)
			cout << "d is between 10 and 20" << endl;
	}
	else
		cout << "d is less than 10" << endl;

	/*		�� ������ Ȱ��			*/
	int e,f;
	cin >> e >> f;

	if (e > 0 && f > 0)
		cout << "both numbers are positive" << endl;
	else if (e > 0 || f > 0)
		cout << "one of numbers is positive" << endl;
	else 
		cout << "Neither number is positive" << endl;



	/*	if������ ���α׷� �ߴ� ����		*/
	int g;
	cin >> g;
	if (g > 10)
		cout << 'G' << endl;
	else if (g == -1)
		return 0; // exit(0)�� ����
	else if (g < 0)
		cout << "g" << endl;

	/*	���� ������		 */
	
	min(3, 2);


	/* ����1 :Null Statement		 */

	int h;
	cin >> h;
	if (h > 10); // ;�� �Ǽ��� ģ�ٸ�...
	{
		// ALLWAYS Operate
	}



	/* ����2 :"=" �� "==" �򰥸��� �ʱ�	*/
	int i;
	cin >> i;

	if (i = 0) // if(i == 0) 
	//�ǵ��� �޸� 0�� �����ϰԵȴ�.
		cout << i << endl;


	return 0;
}