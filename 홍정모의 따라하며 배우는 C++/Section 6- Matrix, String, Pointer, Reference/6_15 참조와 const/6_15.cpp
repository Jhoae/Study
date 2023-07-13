#include <iostream>

using namespace std;

void doSomething_no(const int x)
{
	cout << "doS_no의 x: " << x << endl;
	cout << "doS_no의 &x: " << &x << endl;
}


void doSomething_ref(const int& x)
{
	cout << "doS_ref의 x: " << x << endl;
	cout << "doS_ref의 &x: " << &x << endl;
}


int main()
{
	int x = 5;
	int& ref_x = x;
	
	/*  */
	const int& ref_xc = x;
	const int& ref_x2 = ref_xc;
	
	
	/* 	변수가 const일때->ref에도 const를 붙여야 	*/
	const int no = 5;
	// Error:int& ref_no = no;
	const int& ref_notNo = 5;




	/* ref를 선언할때는 메모리 주소가 있어야한다.  */
	// Error:  int& ref_mn = 5;
	// Error:  int& ref_mn = 3 + 4;

	printf("\n");
	/* 	하지만 const를 붙이면 가능하다	*/
	const int& ref_my = 3 + 4;
	cout << "ref_my: " << ref_my << endl;
	cout << "&ref_my: " << &ref_my << endl;


	/* const int x 와 const int &x의 차이 
		-> 함수의 매개변수로 넣을때 
			const int &x가 매우 유용하다      */

	int a = 1;

	// 매개변수로 전달한 변수의 복사가 일어난다
	doSomething_no(a);
	doSomething_no(1);
	doSomething_no(a + 3);
	doSomething_no(3 * 4);


	// 매개변수로 전달한 변수의 복사가 일어나지 않는다
	doSomething_ref(a);
	doSomething_ref(1);
	doSomething_ref(a + 3);
	doSomething_ref(3 * 4);

	return 0;
}