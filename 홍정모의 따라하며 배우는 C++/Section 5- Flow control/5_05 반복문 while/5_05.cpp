#include <iostream>

using namespace std;

int main()
{
	/* 반복문 이전		*/
	cout << 1 << endl;
	cout << 2 << endl;
	// ...
	cout << 9 << endl;


	
	printf("\n");
	/* 반복문 사용		*/
	int count = 1;
	while (count < 10)
	{
		cout << "While-loop test " << count << endl;
		count++;
	}


	printf("\n");
	/* 변수 선언을 while문 안에 하는 법	 */
	while (count < 10)
	{
		static int count2 = 1;
		cout << "Static While-loop test " << count << endl;
		count++;
	}

	/*	while문에서 break사용		*/
	int c = 1;
	while (1)
	{
		cout << c << endl;
		++c;

		if (c == 10) 
			break;
	}

	/* 
	unsigned를 사용하면 문제가 생길 수 있다. 
	
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


	// while문 안에 while문
	

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