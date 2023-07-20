#include <iostream>

using namespace std;

/* ����� �Լ� �ۼ� - �Լ��� ȣ���Ҷ���, �޸��� �ּҸ� �̿��ؼ� ȣ���Ѵ�. */ 
void countDown(int count) 
{
	cout << count << endl;

// ����� �Լ� ����� �Ҷ���, �ݵ�� ���������� �ۼ��ؾ� �Ѵ�.
	if (count > 0)
		countDown(count - 1);
}

/* ����� �Լ� ���� -2*/
int sumTo(int sumto)
{
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
		return sumTo(sumto - 1) + sumto;
}

/* ����� �Լ� ���� -3 �Ǻ���ġ ����
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
	/* ����� �Լ� ���� -1 */
	countDown(2);



	printf("\n����� �Լ� ���� -2\n");
	/* ����� �Լ� ���� -2*/
	cout << "sumTo(10): " << sumTo(10) << endl;


	printf("\n����� �Լ� ���� -3: �Ǻ���ġ ����\n");
	/* ����� �Լ� ���� -3 �Ǻ���ġ ����*/
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