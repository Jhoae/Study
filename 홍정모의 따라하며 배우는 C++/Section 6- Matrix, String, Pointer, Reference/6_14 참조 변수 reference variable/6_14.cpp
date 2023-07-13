#include <iostream>

using namespace std;

// void doSomething(int n) -> main�� ����X
// void doSomething(const int& n) // -> main�� ����X
void doSomething(int& n) // -> main�� ����O
{
	n = 10;
	cout << "In doSomething n: " << n << endl;
	cout << "In doSomething &n: " << &n << endl;
}

// void printElements(const int(&arr)[5]) // []�ȿ� �ݵ�� ���ڸ� �־�� �Ѵ�
void printElements(int (&arr)[5]) // []�ȿ� �ݵ�� ���ڸ� �־�� �Ѵ�
{
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int value = 5;

	/* pointer�� ����ϴ� �ڵ� */
	int* ptr = nullptr;
	ptr = &value;

	/* ref�� ����ϴ� �ڵ� */
	int& ref = value;

	cout << "ref:\t" << ref << endl;

	ref = 10;
	cout << "value:\t" << value << endl;
	cout << "ref:\t" << ref << endl;

	printf("\n");
	cout << "&value\t" << &value << endl;
	cout << "&ref\t" << &ref << endl;
	cout << "ptr\t" << ptr << endl;
	cout << "&ptr\t" << &ptr << endl;


	/* ������ Ư¡    */
	// Error: int& ref; -> �ݵ�� �ʱ�ȭ�Ǿ���Ѵ�.
	// int& ref = 104; -> literal�� �Ҵ�ɼ�����

	// 1
	int x = 5;
	int& ref_x = x;


	// 2
	const int y = 8;
	// Error: int& ref_y = y; -> const�� �Ҵ��Ҽ� ����
	const int& ref_y = y; // OK



	// 3
	printf("\n");
	int value_1 = 5;
	int value_2 = 10;

	int& ref_1 = value_1;

	cout << "ref_1== value_1\t" << ref_1 << endl;

	ref_1 = value_2;

	cout << "ref_1== value_2\t" << ref_1 << endl;

	printf("\n");
	/* �Լ��� �Ű������� ref�� ���� ��� */
	int n = 5;
	cout << "n: " << n << endl;

	doSomething(n);
	cout << "main�� n: " << n << endl;
	cout << "main�� &n: " << &n << endl;



	/*  Array�� �Լ��� �־��ٶ��� ref�� ��� ����	 */
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElements(arr);


	printf("\n");
	/*  struct������ ref�� ��� ����	 */
	struct Something
	{
		int v1;
		float v2;
	};
	struct Other
	{
		Something st;
	};

	Other ot;
	ot.st.v1 = 1;

	// ref�� ����Ѵٸ�
	int& v1 = ot.st.v1;
	v1 = 1;


	/* ref�� pointer ��			   */


	int value_a = 5;

	// �Ʒ� 2����� �����ϴ�.
	int* const ptr_a = &value_a;
	int& ref_a = value_a;
	
	// �Ʒ� 2����� �����ϴ�.
	*ptr_a = 10;
	ref_a = 10;

	return 0;
}