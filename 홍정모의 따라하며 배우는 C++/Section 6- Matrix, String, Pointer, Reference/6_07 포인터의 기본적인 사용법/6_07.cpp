/*
- 지역변수는 "스택" 메모리
- 동적 할당 메모리는 "힙" 메모리


큰 메모리에 저장되어 있는 데이터 중에서 일부분을 
CPU가 사용하기 위하여 메모리로부터 가져올때는
메모리 전체를 모두 뒤지면서 찾는 것이 아니라,
필요한 데이터가 저장되어 있는 '주소'를 사용하여
직접 접근하여 가져옵니다.

*/

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int x = 5;
	// & : address-of operator
	cout << &x << endl; 
	cout << (int)&x << endl;


	printf("\n");
	/*	de-reference operator (*)	*/
	cout << *(&x) << endl;


	printf("\n");
/*
pointer: 메모리 주소를 담는 변수. 
(주소를 저장하는 변수)

pointer 사용 이유 : 
많은 데이터를 처리할때(특히 배열), 복사하지 않기 위해서.
pointer로 첫 주소와 개수만 알려주면 배열도 간단히 처리가능해진다.
그리고 변수를 사용할때 pointer로 주소를 보내면 좋음

*/
	// typedef 방식도 가능
	// typedef int* pint;
	// pint ptr_x = &x;

	int* ptr_x = &x, * ptr_y = &x;

	cout << ptr_x << endl;
	cout << *ptr_x << endl;


	printf("\n");
	/* double타입의 pointer			*/
	double d = 123.12;
	double* ptr_d = &d;

	cout << ptr_d << endl;
	cout << *ptr_d << endl;

	cout << "ptr_d의 typeid: " << typeid(ptr_d).name() << endl;

	/* pointer의 sizeof :: x86에선 4bytes, x64에선 8bytes.		 */
	printf("\npointer의 sizeof 확인\n");
	cout << "sizeof(x) " << sizeof(x) << endl; // int
	cout << "sizeof(d) " << sizeof(d) << endl; // double
	cout << "sizeof(&x): " << sizeof(&x) << endl;
	cout << "sizeof(&d) " << sizeof(&d) << endl;
	cout << "sizeof(ptr_x) " << sizeof(ptr_x) << endl;
	cout << "sizeof(ptr_d) " << sizeof(ptr_d) << endl;



	printf("\n구조체의 size\n");
	struct Something
	{
		// 4 x 4 = 16 bytes
		int a, b, c, d;
	};

	Something ss;
	Something* ptr_s;

	cout << "sizeof(Something) " << sizeof(Something) << endl;
	cout << "sizeof(ptr_s) " << sizeof(ptr_s) << endl;

	/* 초기화가 안된 변수는 de-reference 안됨  */
	// int *ptr_k;
	// cout << *ptr_k << endl;


	return 0;
}