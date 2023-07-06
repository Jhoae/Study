#include <iostream>
#include <cmath>

/* ���� ������	> < == != 	 */


int main()
{
	using namespace std;

	/*	cin ���迬����	*/
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



	/*	���ǻ���	:: �ε��Ҽ��� ��	 */

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


	// ������ �Ѱ踦 �̸� �����ϴ� ��
	cout << std::abs(d1 - d2) << endl;	// ���밪 ���� : 5.32907e-15
	const double epsilon = 1e-10;

	if (std::abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}