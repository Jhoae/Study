/*
	���� ������ ������ ����� ����� �� ���� �˴ϴ�. 
	���� ������ �����ϰ� �ִ� �޸𸮴� �� ���������� ������ ��� �� 
	'����(stack)' �޸𸮷� �ݳ��˴ϴ�.

	�ݳ��� �޸𸮴� ���� ���� ������ ����� �� �ֵ��� ����մϴ�. 
	'���ð� ��'���� �� �ڼ��� �ٷ�ϴ�.
	(����� �ּҰ��� �Ź� �ٲ�� ����.)
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
	cout << "doSomething Ȯ��" << endl;
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

