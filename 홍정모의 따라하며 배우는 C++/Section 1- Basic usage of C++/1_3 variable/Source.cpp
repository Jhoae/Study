/*
����ü object :: �޸𸮿� ����Ǿ� �ִ� ������ ��ü�μ� �����Ѵ�.

������ variables :: ���ڷ� �� �ּ�.

��Left-values�� Right-values

���ʱ�ȭinitialization�� ����assignment

���ʱ�ȭ�� �� ���� ���� ������ - Runtime Error & �޸𸮿� �����Ⱚ�� ���� �� �ִ�.

*/

#include <iostream>

int main()
{
	// �ʱ�ȭinitialization
	int x = 123;

	// ����assignment
	int y;
	y = 123;


	std::cout << x << std::endl;
	std::cout << &x << std::endl; // x�� �ּҰ�

	return 0;
}