#include <iostream>
#include <string>

using namespace std;

int main()
{

/* syntax error */
	// int x :: ;�� ��Դ°�


/* semantic error */
	int x;
	cin >> x;
	if (x >= 5)
		cout << "x > 5 " << endl; // 5�ϰ�쵵 ����Ǵ� �ǹ� ����


/* violated assumption ���� ���� - ����ڰ� �ٸ� ������� ����Ѵ�. */
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