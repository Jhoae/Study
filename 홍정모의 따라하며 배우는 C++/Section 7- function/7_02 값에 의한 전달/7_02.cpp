#include <iostream>

using namespace std;

void doSomething(int y)
{
	cout << "In func: " << y << "\n&doS������ �ּ�: " << &y << endl;
	printf("\n");
}
/*
	# literal�� ����
	->�Լ����� ����
	->�Լ� int y�� ����& �ʱ�ȭ �ȴ�
*/

int main()
{
	doSomething(5); 

/*
	# ���� ����
	- ������ ���޵Ǵ°��� x��� ������ �ƴ϶�, 
	  6�̶�� ���� parameter�μ� ���޵Ǵ� ��.
	- x + 1 ���� ������ �ƴ϶� ������ ���޵Ǵ� ��.
*/

	int x = 6;

	cout << "In main" << x << "\n&x:\t\t " << &x << endl;
	printf("\n");

	doSomething(x);
	doSomething(x + 1);


	// ���� ���� ���� ������ �ҋ�����, �ܺο� ������ ��ġ�� �ʴ´�.
	return 0;
}