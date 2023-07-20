#include <iostream>
#include <string>

using namespace std;

int main()
{

/* syntax error */
	// int x :: ;를 까먹는것


/* semantic error */
	int x;
	cin >> x;
	if (x >= 5)
		cout << "x > 5 " << endl; // 5일경우도 실행되는 의미 오류


/* violated assumption 가정 위반 - 사용자가 다른 방식으로 사용한다. */
	string hello = "Hello, my name is jackjack";

	cout << "Input from 0 to " << hello.size() << endl;
	
	int index;
	cin >> index;

	while (true)
	{
		if (index >= 0 && index <= hello.size() - 1)
		{
			cout << hello[index] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}