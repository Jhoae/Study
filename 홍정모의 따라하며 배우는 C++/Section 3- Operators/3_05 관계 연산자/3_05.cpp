#include <iostream>
#include <cmath>

/* 관계 연산자	> < == != 	 */


int main()
{
	using namespace std;

	/*	cin 관계연산자	*/
	while (true)
	{

	int x, y;
	cin >> x >> y;
	cout << "Your input values are " << x << " " << y << endl;

	if (x == y)
		cout << "equal" << endl;
	if (x != y)
		cout << "Not equal" << endl;

	if (x > y)
		cout << "X is greater than Y" << endl;
	if(x < y)
		cout << "X is less than Y" << endl;
	if (x >= y)
		cout << "X is greater than Y or equal to Y" << endl;
	if (x <= y)
		cout << "X is less than Y or equal to Y" << endl;
	
	if (x == 1234)
		break;
	}



	/*	주의사항	:: 부동소수점 비교	 */

	double d1(100 - 99.99); // 0.001
	double d2(10 - 9.99);	// 0.001

	cout << d1 << endl;
	cout << d2 << endl;

	if (d1 == d2)
		cout << "equal" << endl;
	else
	{
		cout << "Not equal" << endl;
		if (d1 > d2)
			cout << " d1 > d2 " << endl; // V
		else
			cout << " d1 < d2 " << endl;		
	}


	// 오차의 한계를 미리 정의하는 법
	cout << std::abs(d1 - d2) << endl;	// 절대값 차이 : 5.32907e-15
	const double epsilon = 1e-10;

	if (std::abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}