#include <iostream>
#include <cstdarg> // ellipsis

using namespace std;

/* ellipsis를 사용하는 함수 작성 */
double findAverage(int count, ...)
{
	double sum = 0;

	va_list list; // char* : 문자열로 받음

	va_start(list, count); // count : 문자열의 개수

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int);

	va_end(list);

	return sum / count;
}

int main()
{

	// count == 1 :: 1만 적용되고 나머지 무시
	cout << "findAverage(1, 1, 2, 3, \"Hello\", 'c'):\t\t" << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;

	// count == 3 :: 1, 2, 3의 평균값이 나옴
	cout << "findAverage(3, 1, 2, 3):\t\t\t" << findAverage(3, 1, 2, 3) << endl;

	// count == 5 :: 1, 2, 3, 4, 5의 평균값이 나옴
	cout << "findAverage(5, 1, 2, 3, 4, 5):\t\t\t" << findAverage(5, 1, 2, 3, 4, 5) << endl;

	// count == 10 :: 넣어준숫자가 5개밖에 안되므로 쓰레기값이 나온다.(오류 발생)
	cout << "findAverage(10, 1, 2, 3, 4, 5):\t\t\t" << findAverage(10, 1, 2, 3, 4, 5) << endl;


	return 0;
}