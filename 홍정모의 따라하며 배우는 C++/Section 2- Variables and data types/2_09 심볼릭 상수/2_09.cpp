// Symbolic Constants
#include <iostream>
using namespace std;

void printNum(const int my_num)
{
	// ���� ���� �ٲٰ� �ʹٸ� �̷������� ...
	int n = my_num;
	n = 456; 

	cout << my_num << endl;
}

int main()
{

	const double gravity{ 9.8 }; // const �� ����
	// double const gravity{ 9.8 }; // �� ��ĵ� ����. �ǹ̰� �޶����� ��쵵 ����
	// gravity = 1.2 // Error

	//
	// const double gravity; // const�� �����ϸ� �ݵ�� �ʱ�ȭ���־���� 

/*	�Ű������� const�� ���� �Լ�	*/
	printNum(123);	


/*	Compile time�� �����Ǵ� ��� & Runtime�� �����Ǵ� ���	*/
	const int my_const(123);		// Compile time�� �����Ǵ� ���

	int number;
	cin >> number;
	const int special_number(number);	// Runtime�� �����Ǵ� ���
	number = 123;
	//	special_number = 123 // Error


/*	constexpr::compileŸ�ӿ� �����Ǵ� ���		*/
	constexpr int compile_time_number(123);
	//	constexpr int compile_time_number(number); // Error


/*	Header���� ���� :: ���α׷��� �ʿ��� ������� ��Ƽ� ���� 
					  -> ���������� ���뼺�� */
#include "MY_CONSTANTS.h"
	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;


	return 0;
}