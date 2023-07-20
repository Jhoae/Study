#include <iostream>

using namespace std;

/* 재귀적 함수 작성 - 함수를 호출할때는, 메모리의 주소를 이용해서 호출한다. */ 
void countDown(int count) 
{
	cout << count << endl;

// 재귀적 함수 사용을 할때는, 반드시 종료조건을 작성해야 한다.
	if (count > 0)
		countDown(count - 1);
}

/* 재귀적 함수 예제 -2*/
int sumTo(int sumto)
{
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
		return sumTo(sumto - 1) + sumto;
}

/* 재귀적 함수 예제 -3 피보나치 수열
1 1 2 3 5 8 13 21 ...
*/
int fibonaci(int count) 
{
	if (count == 1 || count == 2)
		return 1;
	else
		return fibonaci(count - 2) + fibonaci(count - 1);
}

//
int main()
{
	/* 재귀적 함수 예제 -1 */
	countDown(2);



	printf("\n재귀적 함수 예제 -2\n");
	/* 재귀적 함수 예제 -2*/
	cout << "sumTo(10): " << sumTo(10) << endl;


	printf("\n재귀적 함수 예제 -3: 피보나치 수열\n");
	/* 재귀적 함수 예제 -3 피보나치 수열*/
	cout << fibonaci(1) << endl;
	cout << fibonaci(2) << endl;
	cout << fibonaci(3) << endl;
	cout << fibonaci(4) << endl;
	cout << fibonaci(5) << endl;
	cout << fibonaci(6) << endl;
	cout << fibonaci(7) << endl;
	cout << fibonaci(8) << endl;
	cout << fibonaci(9) << endl;
	cout << fibonaci(10) << endl;
	cout << fibonaci(11) << endl;
	cout << fibonaci(12) << endl;
	cout << fibonaci(13) << endl;

	return 0;
}