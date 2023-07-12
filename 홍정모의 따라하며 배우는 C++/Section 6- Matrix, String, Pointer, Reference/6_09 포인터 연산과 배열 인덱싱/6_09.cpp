#include <iostream>

using namespace std;

int main()
{

	/*	int�� pointer ���� : 4�� ����			  */
	int value = 7;
	int* ptr = &value;

	cout << "uintptr_t(ptr - 1): " << uintptr_t(ptr - 1) << endl;
	cout << "uintptr_t(ptr): " << uintptr_t(ptr) << endl;
	cout << "uintptr_t(ptr + 1): " << uintptr_t(ptr + 1) << endl;
	cout << "uintptr_t(ptr + 2): " << uintptr_t(ptr + 2) << endl;



	printf("\n");
	/* double�� pointer ���� : 8�� ����		  */
	double value_d = 7.123;
	double* ptr_d = &value_d;

	cout << "uintptr_t(ptr_d - 1): " << uintptr_t(ptr_d - 1) << endl;
	cout << "uintptr_t(ptr_d): " << uintptr_t(ptr_d) << endl;
	cout << "uintptr_t(ptr_d + 1): " << uintptr_t(ptr_d + 1) << endl;
	cout << "uintptr_t(ptr_d + 2): " << uintptr_t(ptr_d + 2) << endl;


	/* short�� pointer ���� : 2�� ����		  */
	short value_s = 5;
	short* ptr_s = &value_s;

	cout << "uintptr_t(ptr_s - 1): " << uintptr_t(ptr_s - 1) << endl;
	cout << "uintptr_t(ptr_s): " << uintptr_t(ptr_s) << endl;
	cout << "uintptr_t(ptr_s + 1): " << uintptr_t(ptr_s + 1) << endl;
	cout << "uintptr_t(ptr_s + 2): " << uintptr_t(ptr_s + 2) << endl;




	printf("\n");
	/* intŸ���� Array - 4�� ����           */
	int array[] = { 9,7,5,3,1 };
	int* ptr2 = array;

	for (int i = 0; i < 5; ++i) {
		cout << "array[" << i << "]: " << array[i] << " " << (uintptr_t)(&array[i]) << endl;
	}

	printf("\n");
	for (int i = 0; i < 5; ++i) {
		cout << "(ptr2 + " << i << "): " << (ptr2 + i) << (uintptr_t)(ptr2 + i) << endl;
	}


	printf("\n");
	/* long long Ÿ���� Array - 8�� ����           */
	long long array_ll[] = { 9,7,5,3,1 };
	long long * ptr_ll = array_ll;

	for (int i = 0; i < 5; ++i) {
		cout << "array_ll[" << i << "]: " << array_ll[i] << " " << (uintptr_t)(&array_ll[i]) << endl;
	}

	printf("\n");
	for (int i = 0; i < 5; ++i) {
		cout << "(ptr_ll + " << i << "): " << (ptr_ll + i) << (uintptr_t)(ptr_ll + i) << endl;
	}

	printf("\n");
	/* ���ڿ� */
	char name[] = "Jack jack";
	char* ptr_c = name;

	const int n_name = sizeof(name) / sizeof(char);
	cout << "n_name: " << n_name << endl; // Null character�� ������ 10



	for (int i = 0; i < n_name; ++i)
	{
		cout << "*(name + " << i << "): " << *(name + i) << endl;
	}
	cout << endl;

	for (int i = 0; i < n_name; ++i)
	{
		cout << "*(ptr_c + " << i << "): " << *(ptr_c + i) << endl;
	}
	cout << endl;


	/* while���� pointer�� �̿��� ���			  */
	printf("\n");
	int count = 0;
	while (*ptr_c != '\0') 
	{
		cout << count << ": " << *ptr_c << endl;
        ptr_c++;
		count++;
    }

	return 0;
}