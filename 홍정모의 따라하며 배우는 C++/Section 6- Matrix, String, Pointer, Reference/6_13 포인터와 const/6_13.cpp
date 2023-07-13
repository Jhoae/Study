#include <iostream>

using namespace std;

int main()
{

	/*	pointer�� value ��� const	  */
	int value = 1;
	int* ptr = &value;
	*ptr = 11;

	cout << "*ptr: " << *ptr << endl;

	const int value2 = 2;
	const int* ptr2 = &value2;
	// Error:*ptr2 = 22;
	
	cout << "*ptr2: " << *ptr << endl;


	/*	pointer�� const	
	- �������δ� ���� �Ұ���������, 
	  ������ü�� ���� ����  */
	int value3 = 3;
	const int* ptr3 = &value3;
	
	// Error: *ptr3 = 33;
	value3 = 33; // ok

	cout << "*ptr3" << *ptr3 << endl;


	/* ������ 2������ ���			  
	- const int* �� 
	  ����Ű�� �ּ��� �ش� ���� �ȹٲٰڴٴ� �ǹ�����,
	  
	  ptr�� ����Ű�� �ּҰ���
	  �ȹٲٰڴٴ� �ǹ̴� �ƴϴ�.	
	*/

	int value_1 = 5;
	const int* ptr_1 = &value_1;
	// Error: ptr_1 = 7;

	int value_2 = 6;
	ptr_1 = &value_2; // ����Ե� ����.




	printf("\npointer ��ü�� ����� ���\n");
	/* pointer ��ü�� const�� ���		  */
	int value_c = 5;
	int* const ptr_c = &value_c;

	*ptr_c = 10; // ����
	int value_c2 = 8;
	// pointer�� �ּҰ��� �ٲܼ� ����.
	// -> ��¥ �����μ� pointer�� const�� �ٴ� ���
	// Error: ptr_c = &value_c2;

	cout << "*ptr_c: " << *ptr_c << endl;


	int value_cc = 5;
	
	// const �̹Ƿ� �ʱⰪ �ʿ�
	// Error: const int* const ptr_cc; 

	const int* const ptr_cc = &value_cc;
	// const�̹Ƿ� �ּ��� �ش簪 ���� �Ұ�
	// Error: ptr_cc = 10;



	/* ����			 */
	int value_t = 5;

	/*
	1. const int* 
	 == pointer�� �ּ��� �ش簪�� const 

	- �������� ���� �Ұ��� 
	  ������ü�� ���� ����

	  // Error: *ptr_t1 = 55;
	  // OK: value_t = 55;
	  // ����Ե� ����.
	  // - OK: ptr_t1 = &value_2; 
	*/
	const int* ptr_t1 = &value_t;



	/*
	2. int* const ptr
	  == pointer ��ü�� const�� ���
	  -> pointer�� �ش�� �ּҰ��� ���� �Ұ���
		
	  // Error: ptr_t2 = &value_t2
	  // OK: *ptr_t2 = 10; 
	  
	  // const �̹Ƿ� �ʱⰪ �ʿ�
	  // - Error: const int* const ptr_t2;
	*/
	int* const ptr_t2 = &value_t; 


	/* 	3. pointer�� �ּҰ��� pointer�� �ּ� �ش簪 ��� const 	*/
	const int* const ptr_t3 = &value_t;


	// ���Ŀ� ������ ���� Ÿ�����ϱ� ��������.

	return 0;
}