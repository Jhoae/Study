#include <iostream>

using namespace std;

int min(int x, int y)
{
	/*
	if (x > y) 		return y;
	else 		return x;
	*/

	// 삼항 연산자
	return (x > y) ? y : x;
}

int main()
{

	/*	조건문 if 예시		*/
	int a;
	cin >> a;

	if (a > 10)
	{
		cout << a << " is greater than 10" << endl;
		cout << "Test 1" << endl;
	}
	else 
		cout << a << " is greater NOT than 10" << endl;

	/*	if문 주의	*/
	int b;
	cin >> b;

	if (0) {}  //  == if(false)
	if (1) // == if (true)
	{
		int b = 5;
	}
	else
		int b = 6;
	cout << b << endl; // 결과는 ?? ===> {}밖을 벗어나면 int b=5가 사라지므로 cin값 출력


	/*	chain		*/
	int c;
	cin >> c;


// 활용 1
	if (c > 10)
		cout << "c is greater than 10" << endl;
	else if (c < 10)
		cout << "c is less than 10" << endl;
	else if (c == 10)
		cout << "c is 10" << endl;


// 활용 2
	if (c > 10)
		cout << "c is greater than 10" << endl;
	else
	{
		if (c < 10)
			cout << "c is less than 10" << endl;
		else // if ( c== 10)
			cout << "c is 10" << endl;
	}

	
// 활용 3
	int d;
	cin >> d;
	if (d >= 10)
	{
		if (d <= 20)
			cout << "d is between 10 and 20" << endl;
	}
	else
		cout << "d is less than 10" << endl;

	/*		논리 연산자 활용			*/
	int e,f;
	cin >> e >> f;

	if (e > 0 && f > 0)
		cout << "both numbers are positive" << endl;
	else if (e > 0 || f > 0)
		cout << "one of numbers is positive" << endl;
	else 
		cout << "Neither number is positive" << endl;



	/*	if문으로 프로그램 중단 가능		*/
	int g;
	cin >> g;
	if (g > 10)
		cout << 'G' << endl;
	else if (g == -1)
		return 0; // exit(0)도 가능
	else if (g < 0)
		cout << "g" << endl;

	/*	삼항 연산자		 */
	
	min(3, 2);


	/* 주의1 :Null Statement		 */

	int h;
	cin >> h;
	if (h > 10); // ;를 실수로 친다면...
	{
		// ALLWAYS Operate
	}



	/* 주의2 :"=" 와 "==" 헷갈리지 않기	*/
	int i;
	cin >> i;

	if (i = 0) // if(i == 0) 
	//의도와 달리 0을 대입하게된다.
		cout << i << endl;


	return 0;
}