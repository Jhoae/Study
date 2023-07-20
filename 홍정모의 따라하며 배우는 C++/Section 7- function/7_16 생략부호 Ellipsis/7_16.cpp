#include <iostream>
#include <cstdarg> // ellipsis

using namespace std;

/* ellipsis�� ����ϴ� �Լ� �ۼ� */
double findAverage(int count, ...)
{
	double sum = 0;

	va_list list; // char* : ���ڿ��� ����

	va_start(list, count); // count : ���ڿ��� ����

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int);

	va_end(list);

	return sum / count;
}

int main()
{

	// count == 1 :: 1�� ����ǰ� ������ ����
	cout << "findAverage(1, 1, 2, 3, \"Hello\", 'c'):\t\t" << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;

	// count == 3 :: 1, 2, 3�� ��հ��� ����
	cout << "findAverage(3, 1, 2, 3):\t\t\t" << findAverage(3, 1, 2, 3) << endl;

	// count == 5 :: 1, 2, 3, 4, 5�� ��հ��� ����
	cout << "findAverage(5, 1, 2, 3, 4, 5):\t\t\t" << findAverage(5, 1, 2, 3, 4, 5) << endl;

	// count == 10 :: �־��ؼ��ڰ� 5���ۿ� �ȵǹǷ� �����Ⱚ�� ���´�.(���� �߻�)
	cout << "findAverage(10, 1, 2, 3, 4, 5):\t\t\t" << findAverage(10, 1, 2, 3, 4, 5) << endl;


	return 0;
}