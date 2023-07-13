// 1. 정적 메모리 할당(전역, static변수) -> stack
// 2. 자동메모리 할당(변수,정적배열)
// 3. 동적 메모리 할당(pointer와 관련) -> heap

#include <iostream>

using namespace std;

int main()
{
	/*	메모리 할당		*/
	int array[100];  // stack에 저장됨
	
	//int var;
	// var = 7;

	int* ptr = new int;	// 4bytes 메모리의 주소가 저장됨
	*ptr = 7;
	// int* ptr = new int{ 7 };	
	cout << "ptr: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl;

	delete ptr; // 메모리 반납
	ptr = nullptr;

	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << "ptr: " << ptr << endl;
		cout << "*ptr: " << *ptr << endl;
	}



	/*	std::nothrow				*/	 
	int* ptr2 = new(std::nothrow)int{ 7 }; // 메모리가 부족하더라도 밀어붙인다.

	if (ptr2)
	{
		cout << "ptr2: " << ptr2 << endl;
		cout << "*ptr2: " << *ptr2 << endl;
	}
	else 
	{
		cout << "Could not allocate memory" << endl;
	}





/* 흔히 하는 실수  */

	int* ptr3 = new(std::nothrow)int{ 7 };
	int* ptr4 = ptr3;

	delete ptr3;
	ptr3 = nullptr;
	// ptr4 = nullptr; // -> 깜빡할경우


	/* 메모리 누수(leak)			  */

	/*
	while (true)
	{
		int* ptr5 = new int;
		cout << ptr5 << endl;

		delete ptr; // 메모리를 지워주지 않으면 누수가 발생한다.
	}
	*/
	




	return 0;
}