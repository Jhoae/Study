#include <iostream>

using namespace std;

/* �Լ� �����ε��� ��� - �Ű������� �޶�� �Ѵ�. returnŸ�����δ� ������ �ȵȴ�.
	-> ������ �Ҷ� ��� �Լ��� ������� �����ȴ� */

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

/* reference�� ����Ͽ� ȸ���ϴ� ��� */
void getRandom(int &x) {}
void getRandom(double &x) {}



/* typedef�� ������ �������� �Ҽ� ���� */
typedef int my_int;

void print(int x) {}
// == void print(my_int x) {}



/* match�� ��Ȯ�� �ȵɶ� -1 */
void print_m(const char* value) {}
void print_m(int value) {}


/* match�� ��Ȯ�� �ȵɶ� -2 */
void print_f(unsigned int value){}
void print_f(float value) {}

int main()
{

/* �Լ� �����ε��� ��� 
	-> ������ �Ҷ� ��� �Լ��� ������� �����ȴ� */
	add(1, 2);
	add(3.1, 4.2);


/* reference�� ����Ͽ� ȸ���ϴ� ��� */
	int x;
	getRandom(x);
	// int x = getRandomInt(x);  // �Լ��� ����
	// int x = getRandom(int()); // returnŸ�����δ� ������ �ȵȴ�.


/* match�� ��Ȯ�� �ȵɶ� - 1 :: ��ġ�� �ȵɶ� */
	print_m(0);	  // print_m(int)
	print_m('a'); // print_m(int)
	print_m("a"); // print_m(const char*)
	// ���� print_m�� (const�� �ƴ϶� char *)�̶��
	// print_m("a"); -> Error


/* match�� ��Ȯ�� �ȵɶ� -2 :: �Ѵ� ����(��ȣ�ҋ�) */
	// print_f('a');		// ambiguous Error
	// print_f(0);			// ambiguous Error
	// print_f(3.141592);	// ambiguous Error

	print_f((unsigned int)'a');
	print_f(0u);
	print_f(3.141592f);

	return 0;
}