/*
	지역 변수는 영역을 벗어나면 사용할 수 없게 됩니다. 
	지역 변수가 차지하고 있던 메모리는 그 지역변수가 영역을 벗어날 때 
	'스택(stack)' 메모리로 반납됩니다.

	반납된 메모리는 다음 지역 변수가 사용할 수 있도록 대기합니다. 
	'스택과 힙'에서 더 자세히 다룹니다.
	(적어둔 주소값은 매번 바뀔수 있음.)
*/

#include <iostream>
void doSomething(int x);

using namespace std;

int main()
{
	int x = 0;

	cout << x << " " << &x << endl;     // 0 00AFF784

	{
		int x = 1;

		cout << x << " " << &x << endl; // 1 00AFF778
			
	}

	{
		int x = 2;
		
		cout << x << " " << &x << endl; // 2 00AFF76C
	}

	///////
	cout << "doSomething 확인" << endl;
	cout << x << " " << &x << endl; // #1 0 00AFF784
	doSomething(x);					//    123
	cout << x << " " << &x << endl; // #3 0 00AFF784

	return 0;
}

void doSomething(int x) 
{
	x = 123;
	cout << x << endl;
}

