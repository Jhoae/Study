/*

void pointer 
�Ǵ� generic pointer(�������� ������)

*/

#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr;

	// ���� ����X
	ptr = &i;
	ptr = &f;
	// ptr = &c;

	// �ּҰ��� �����ϰ� �Ҵ�ȴ�.
	cout << "&f: " << &f << " " << "/ptr: " << ptr << endl;


	printf("\n");
	// intŸ�� pointer�� �����Ϳ���� de-ref�� �����ϴ�.
	int* ptr_i = &i; 	
	cout << "*ptr_i\t\t" << *ptr_i << endl;
	cout << "ptr_i\t\t" << ptr_i << endl;
	cout << "ptr_i + 1\t" << ptr_i + 1 << endl;


	printf("\n");
	/* 
	������ void pointer�� ������ ������ �ȵȴ�.
	 ���� -> +1�� �Ҷ�, �� bytes�� ���ؾߵǴ��� �˼� ���� ������
	// Error: cout << ptr + 1 << endl;
	
	���� de-referencing�� �ȵȴ�.
	 ���� -> � Ÿ������ �𸣱� ������
	// Error: cout << *ptr << endl;

	 
	 -> ���� ���� �����ö��� 
		������ ���� ������ casting�ؾ��Ѵ�.
	 */
	cout << "*(static_cast<float*>(ptr)):\t" << *(static_cast<float*>(ptr)) << endl;


	return 0;
}