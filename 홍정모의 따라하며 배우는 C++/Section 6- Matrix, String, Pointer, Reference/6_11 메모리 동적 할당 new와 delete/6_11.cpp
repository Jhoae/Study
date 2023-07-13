// 1. ���� �޸� �Ҵ�(����, static����) -> stack
// 2. �ڵ��޸� �Ҵ�(����,�����迭)
// 3. ���� �޸� �Ҵ�(pointer�� ����) -> heap

#include <iostream>

using namespace std;

int main()
{
	/*	�޸� �Ҵ�		*/
	int array[100];  // stack�� �����
	
	//int var;
	// var = 7;

	int* ptr = new int;	// 4bytes �޸��� �ּҰ� �����
	*ptr = 7;
	// int* ptr = new int{ 7 };	
	cout << "ptr: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl;

	delete ptr; // �޸� �ݳ�
	ptr = nullptr;

	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << "ptr: " << ptr << endl;
		cout << "*ptr: " << *ptr << endl;
	}



	/*	std::nothrow				*/	 
	int* ptr2 = new(std::nothrow)int{ 7 }; // �޸𸮰� �����ϴ��� �о���δ�.

	if (ptr2)
	{
		cout << "ptr2: " << ptr2 << endl;
		cout << "*ptr2: " << *ptr2 << endl;
	}
	else 
	{
		cout << "Could not allocate memory" << endl;
	}





/* ���� �ϴ� �Ǽ�  */

	int* ptr3 = new(std::nothrow)int{ 7 };
	int* ptr4 = ptr3;

	delete ptr3;
	ptr3 = nullptr;
	// ptr4 = nullptr; // -> �����Ұ��


	/* �޸� ����(leak)			  */

	/*
	while (true)
	{
		int* ptr5 = new int;
		cout << ptr5 << endl;

		delete ptr; // �޸𸮸� �������� ������ ������ �߻��Ѵ�.
	}
	*/
	




	return 0;
}