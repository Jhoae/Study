#include <iostream>

using namespace std;

int main()
{

	/*	pointer와 value 모두 const	  */
	int value = 1;
	int* ptr = &value;
	*ptr = 11;

	cout << "*ptr: " << *ptr << endl;

	const int value2 = 2;
	const int* ptr2 = &value2;
	// Error:*ptr2 = 22;
	
	cout << "*ptr2: " << *ptr << endl;


	/*	pointer만 const	
	- 역참조로는 변경 불가능하지만, 
	  변수자체는 변경 가능  */
	int value3 = 3;
	const int* ptr3 = &value3;
	
	// Error: *ptr3 = 33;
	value3 = 33; // ok

	cout << "*ptr3" << *ptr3 << endl;


	/* 변수가 2가지인 경우			  
	- const int* 는 
	  가리키는 주소의 해당 값을 안바꾸겠다는 의미이지,
	  
	  ptr이 가리키는 주소값을
	  안바꾸겠다는 의미는 아니다.	
	*/

	int value_1 = 5;
	const int* ptr_1 = &value_1;
	// Error: ptr_1 = 7;

	int value_2 = 6;
	ptr_1 = &value_2; // 놀랍게도 가능.




	printf("\npointer 자체가 상수인 경우\n");
	/* pointer 자체가 const인 경우		  */
	int value_c = 5;
	int* const ptr_c = &value_c;

	*ptr_c = 10; // 가능
	int value_c2 = 8;
	// pointer의 주소값을 바꿀수 없다.
	// -> 진짜 변수로서 pointer의 const가 붙는 경우
	// Error: ptr_c = &value_c2;

	cout << "*ptr_c: " << *ptr_c << endl;


	int value_cc = 5;
	
	// const 이므로 초기값 필요
	// Error: const int* const ptr_cc; 

	const int* const ptr_cc = &value_cc;
	// const이므로 주소의 해당값 변경 불가
	// Error: ptr_cc = 10;



	/* 정리			 */
	int value_t = 5;

	/*
	1. const int* 
	 == pointer의 주소의 해당값만 const 

	- 역참조로 변경 불가능 
	  변수자체는 변경 가능

	  // Error: *ptr_t1 = 55;
	  // OK: value_t = 55;
	  // 놀랍게도 가능.
	  // - OK: ptr_t1 = &value_2; 
	*/
	const int* ptr_t1 = &value_t;



	/*
	2. int* const ptr
	  == pointer 자체가 const인 경우
	  -> pointer에 해당된 주소값은 변경 불가능
		
	  // Error: ptr_t2 = &value_t2
	  // OK: *ptr_t2 = 10; 
	  
	  // const 이므로 초기값 필요
	  // - Error: const int* const ptr_t2;
	*/
	int* const ptr_t2 = &value_t; 


	/* 	3. pointer의 주소값과 pointer의 주소 해당값 모두 const 	*/
	const int* const ptr_t3 = &value_t;


	// 이후에 참조를 배우면 타이핑하기 편해진다.

	return 0;
}