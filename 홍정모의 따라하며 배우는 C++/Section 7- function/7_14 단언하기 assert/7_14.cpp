#include <iostream>
#include <cassert> // assert
#include <array>

using namespace std;

void printValue(const std::array<int, 5>&my_arr, const int &ix)
{
	assert(ix >= 0);
	assert(ix <= my_arr.size() - 1);

	cout << my_arr[ix] << endl;
}

int main()
{


/* assert는 runtime에 동작하며,
	Debug모드에서만 동작하고, Release모드에서는 작동하지 않는다. */
	int number = 5;

	// ... 
	// number가 5여야 한다

	assert(number == 5);


/* array를 사용하는 함수에서 assert를 사용하는 경우  */
	std::array<int, 5>my_arr{ 1,2,3,4,5 };
	printValue(my_arr, 2);
	


/* compile time에 동작하는 static assert 
   - 컴파일러를 이용해서 프로그램에서 생길 문제를  미리 차단 */
	int k = 5;
	assert(k == 5);

	// compile time에 결정되는것만 사용가능
	// k = 10; 처럼 도중에 바뀔수 있기 때문에 에러발생
	// static_assert(k == 5);  :: ERROR	

	const int c = 5;
	static_assert(c == 5, "c should be 5");



	return 0;
}