#include <iostream> // cout, cin, endl ...
#include <cstdio> // printf

int main()
{
	int x=1024;
	double pi = 3.141592;

	// std::endl 과 /n 의 유무
	std::cout << "Hello, World!1" << std::endl;
	std::cout << "Hello, World!2\n";
	std::cout << "Hello, World!3"; // << std::endl;
	std::cout << "x is" << x << "pi is" << pi << std::endl;

	// \t를 이용하면 자동 줄맞춤
	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	// 짧게 사용하기
	using namespace std;
	cout << "Hello, World!1" << endl;
	cout << "x is" << x << "pi is" << pi << endl;

	cout << "\a"; // 띵동
//	printf("Hello, World!")

	// 입력을 받는 방법
	using namespace std;

	int y;
	cin >> y;
	cout << "Your input is " << y << endl;


	int z = 1;
	cout << "Before your input, z was " << z << endl;

	// z에 1000000000000000000000000을 입력해보기 -> 2147483647 로 출력됨 (int 변수가 가질수 있는 가장 큰 숫자)
	cin >> z; 	
	cout << "Your input is " << z << endl;


	return 0;
}