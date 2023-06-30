/*
	���ͷ� Literal
	�ǿ����� Operand
	���� unary, ���� binary, ���� ternary
*/

#include <iostream>

using namespace std;

int main() 
{
	int x = 2; // x�� ����, 2�� ���ͷ�

	cout << x + 2 << endl; // x�� 2�� �ǿ�����
	cout << "Hello, World" << endl;

	/*
		���ǿ�����(Conditional operator)��
		C++ ����� ������ ���� ������(Ternary operator)�Դϴ�.
	*/
	int y = (x > 0) ? 1 : 2;
	cout << y << endl;


	return 0;
}