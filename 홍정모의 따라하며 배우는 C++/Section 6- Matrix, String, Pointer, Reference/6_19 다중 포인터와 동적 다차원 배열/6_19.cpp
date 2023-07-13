#include <iostream>

using namespace std;

int main()
{

	int* ptr = nullptr;

	// ���� ������ - pointer�� ���� pointer
	int** ptrptr = nullptr; // ���� ������ int�̴�

	int value = 5;

	ptr = &value;
	ptrptr = &ptr; // ptr�� �ּҰ�

	cout << "ptr\t" << ptr << endl;
	cout << "*ptr\t" << *ptr << endl;
	cout << "&ptr\t" << &ptr << endl;

	printf("\n");
	cout << "ptrptr\t" << ptrptr << endl;
	cout << "*ptrptr\t" << *ptrptr << endl;
	cout << "&ptrptr\t" << &ptrptr << endl;
	cout << "*(*ptrptr)\t" << *(*ptrptr) << endl;



	// 3�� ������, 4�� ������... �� ���� -> �߾Ⱦ�
	int*** ptr_3, **** int_4;



	printf("\n");
	/* ���� ���2D Array�� �����Ҷ� ���������͸� ���־���.		 */
	const int row = 3;
	const int col = 5;

	const int static2Darray[row][col] =
	{
		// ������ 5��¥�� 1���� array
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
	};


	int* r1 = new int[col] {1, 2, 3, 4, 5};
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};


	/*
		�̶� r�� ��� ������ �𸣴�.
		int�� pointer�� array�� ����� �ִ�
	*/
	int** rows = new int* [row] {r1, r2, r3};

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << rows[r][c] << " ";
		cout << endl;
	}

	/* ���� for������ �����ϱ�			  */	

	int** matrix = new int* [row];

	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			matrix[r][c] = static2Darray[r][c];
	}

	printf("\nfor������ ó��\n");
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	// delete�ϱ�
	for (int r = 0; r < row; ++r)
		delete[] matrix[r];

	delete[] matrix;

	// delete[] r1;
	// delete[] r2;
	// delete[] r3;
	delete[] rows;



	printf("\n2�� ����� 2�������� ���� �����ϱ�\n");
	/* 2�� ����� 2�������� ���� �����ϱ�  
		-> 1���� array�� 2����ó�� ���η��� ����ϱ�
	*/
	
	int* matrix_no = new int[row * col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			matrix_no[c + col * r] = static2Darray[r][c];
	}


	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix_no[c + col * r] << " ";
		cout << endl;
	}

	delete[] matrix_no;


	/* vector�� ����ϸ� new, delete�� ��������. */

	return 0;
}