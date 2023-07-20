#include <iostream>

using namespace std;

/* inline 함수 정의 -> 대체로 빨라짐. compile되는 방식이 바뀜 */
inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{

	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;


	// inline함수로 작성하면 아래처럼 compile된다.
	cout << (5 > 6 ? 6 : 5) << endl;
	cout << (3 > 2 ? 2 : 3) << endl;

	return 0;
}