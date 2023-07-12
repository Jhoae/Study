/*
- ���������� "����" �޸�
- ���� �Ҵ� �޸𸮴� "��" �޸�


ū �޸𸮿� ����Ǿ� �ִ� ������ �߿��� �Ϻκ��� 
CPU�� ����ϱ� ���Ͽ� �޸𸮷κ��� �����ö���
�޸� ��ü�� ��� �����鼭 ã�� ���� �ƴ϶�,
�ʿ��� �����Ͱ� ����Ǿ� �ִ� '�ּ�'�� ����Ͽ�
���� �����Ͽ� �����ɴϴ�.

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
pointer: �޸� �ּҸ� ��� ����. 
(�ּҸ� �����ϴ� ����)

pointer ��� ���� : 
���� �����͸� ó���Ҷ�(Ư�� �迭), �������� �ʱ� ���ؼ�.
pointer�� ù �ּҿ� ������ �˷��ָ� �迭�� ������ ó������������.
�׸��� ������ ����Ҷ� pointer�� �ּҸ� ������ ����

*/
	// typedef ��ĵ� ����
	// typedef int* pint;
	// pint ptr_x = &x;

	int* ptr_x = &x, * ptr_y = &x;

	cout << ptr_x << endl;
	cout << *ptr_x << endl;


	printf("\n");
	/* doubleŸ���� pointer			*/
	double d = 123.12;
	double* ptr_d = &d;

	cout << ptr_d << endl;
	cout << *ptr_d << endl;

	cout << "ptr_d�� typeid: " << typeid(ptr_d).name() << endl;

	/* pointer�� sizeof :: x86���� 4bytes, x64���� 8bytes.		 */
	printf("\npointer�� sizeof Ȯ��\n");
	cout << "sizeof(x) " << sizeof(x) << endl; // int
	cout << "sizeof(d) " << sizeof(d) << endl; // double
	cout << "sizeof(&x): " << sizeof(&x) << endl;
	cout << "sizeof(&d) " << sizeof(&d) << endl;
	cout << "sizeof(ptr_x) " << sizeof(ptr_x) << endl;
	cout << "sizeof(ptr_d) " << sizeof(ptr_d) << endl;



	printf("\n����ü�� size\n");
	struct Something
	{
		// 4 x 4 = 16 bytes
		int a, b, c, d;
	};

	Something ss;
	Something* ptr_s;

	cout << "sizeof(Something) " << sizeof(Something) << endl;
	cout << "sizeof(ptr_s) " << sizeof(ptr_s) << endl;

	/* �ʱ�ȭ�� �ȵ� ������ de-reference �ȵ�  */
	// int *ptr_k;
	// cout << *ptr_k << endl;


	return 0;
}