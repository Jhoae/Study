#include <iostream>

using namespace std;

void breakOrReturn()
{
	char ch;
	cin >> ch;
	while (true)
	{

	if (ch == 'b')
		break;
		
	if (ch == 'r')
		return;
	}

	cout << "Hello" << endl;
}

int main()
{
	int count = 0;
	while (true)
	{
		cout << count << endl;
		if (count == 10) break;
		count++;
	}

	printf("\n");
	breakOrReturn();



	/* continue: 반복문의 처음으로 돌아가기.			*/	
	printf("\n");
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0) continue;
		
		cout << i << endl;
	}

	printf("\n");
	int count2(0);
	do {
		if (count2 == 5)
			continue;
		cout << count2 << endl;
	} while (++count2 < 10);



	printf("\n");
	int count3(0);
	bool escape_flag = false;
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'x')
			break;

		cout << ch << " " << count3++ << endl;




	}


	return 0;
}