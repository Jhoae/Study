#include <iostream>

using namespace std;

void doSomething(int y)
{
	cout << "In func: " << y << "\n&doS변수의 주소: " << &y << endl;
	printf("\n");
}
/*
	# literal값 전달
	->함수에서 복사
	->함수 int y가 선언& 초기화 된다
*/

int main()
{
	doSomething(5); 

/*
	# 변수 전달
	- 실제로 전달되는것은 x라는 변수가 아니라, 
	  6이라는 값만 parameter로서 전달되는 것.
	- x + 1 또한 변수가 아니라 값으로 전달되는 것.
*/

	int x = 6;

	cout << "In main" << x << "\n&x:\t\t " << &x << endl;
	printf("\n");

	doSomething(x);
	doSomething(x + 1);


	// 따라서 값에 의한 전달을 할떄에는, 외부에 영향을 끼치지 않는다.
	return 0;
}