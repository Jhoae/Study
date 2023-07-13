#include <iostream>

using namespace std;

void doSomething_no(const int x)
{
	cout << "doS_no�� x: " << x << endl;
	cout << "doS_no�� &x: " << &x << endl;
}


void doSomething_ref(const int& x)
{
	cout << "doS_ref�� x: " << x << endl;
	cout << "doS_ref�� &x: " << &x << endl;
}


int main()
{
	int x = 5;
	int& ref_x = x;
	
	/*  */
	const int& ref_xc = x;
	const int& ref_x2 = ref_xc;
	
	
	/* 	������ const�϶�->ref���� const�� �ٿ��� 	*/
	const int no = 5;
	// Error:int& ref_no = no;
	const int& ref_notNo = 5;




	/* ref�� �����Ҷ��� �޸� �ּҰ� �־���Ѵ�.  */
	// Error:  int& ref_mn = 5;
	// Error:  int& ref_mn = 3 + 4;

	printf("\n");
	/* 	������ const�� ���̸� �����ϴ�	*/
	const int& ref_my = 3 + 4;
	cout << "ref_my: " << ref_my << endl;
	cout << "&ref_my: " << &ref_my << endl;


	/* const int x �� const int &x�� ���� 
		-> �Լ��� �Ű������� ������ 
			const int &x�� �ſ� �����ϴ�      */

	int a = 1;

	// �Ű������� ������ ������ ���簡 �Ͼ��
	doSomething_no(a);
	doSomething_no(1);
	doSomething_no(a + 3);
	doSomething_no(3 * 4);


	// �Ű������� ������ ������ ���簡 �Ͼ�� �ʴ´�
	doSomething_ref(a);
	doSomething_ref(1);
	doSomething_ref(a + 3);
	doSomething_ref(3 * 4);

	return 0;
}