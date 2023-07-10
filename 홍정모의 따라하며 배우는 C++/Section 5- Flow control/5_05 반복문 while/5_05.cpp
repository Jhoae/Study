#include <iostream>

using namespace std;

int main()
{
	/* �ݺ��� ����		*/
	cout << 1 << endl;
	cout << 2 << endl;
	// ...
	cout << 9 << endl;


	
	printf("\n");
	/* �ݺ��� ���		*/
	int count = 1;
	while (count < 10)
	{
		cout << "While-loop test " << count << endl;
		count++;
	}


	printf("\n");
	/* ���� ������ while�� �ȿ� �ϴ� ��	 */
	while (count < 10)
	{
		static int count2 = 1;
		cout << "Static While-loop test " << count << endl;
		count++;
	}

	/*	while������ break���		*/
	int c = 1;
	while (1)
	{
		cout << c << endl;
		++c;

		if (c == 10) 
			break;
	}

	/* 
	unsigned�� ����ϸ� ������ ���� �� �ִ�. 
	
	unsigned int d = 10;
	while (d >= 0)
	{
		if (d == 0) cout << "Zero" << endl;
		else cout << d << " " << endl;

		d--;
	}
	*/

	printf("\n");
	unsigned int e = 10;
	while (e < 0)
	{
		if (e % 5 == 0) cout <<  "Hello" << e << endl;
		e++;
	}


	// while�� �ȿ� while��
	

	int outer_count = 1;
	
	while (outer_count <= 5)
	{
		int inner_count = 1;
		while (inner_count <= outer_count)
		{
			cout << inner_count++ << " ";
		}

		cout << endl;
		++outer_count;
	}

	return 0;
}