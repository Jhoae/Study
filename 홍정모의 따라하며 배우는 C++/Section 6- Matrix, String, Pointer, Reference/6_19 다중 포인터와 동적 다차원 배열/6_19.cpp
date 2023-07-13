#include <iostream>

using namespace std;

int main()
{

	int* ptr = nullptr;

	// 이중 포인터 - pointer에 대한 pointer
	int** ptrptr = nullptr; // 원래 변수는 int이다

	int value = 5;

	ptr = &value;
	ptrptr = &ptr; // ptr의 주소값

	cout << "ptr\t" << ptr << endl;
	cout << "*ptr\t" << *ptr << endl;
	cout << "&ptr\t" << &ptr << endl;

	printf("\n");
	cout << "ptrptr\t" << ptrptr << endl;
	cout << "*ptrptr\t" << *ptrptr << endl;
	cout << "&ptrptr\t" << &ptrptr << endl;
	cout << "*(*ptrptr)\t" << *(*ptrptr) << endl;



	// 3중 포인터, 4중 포인터... 도 가능 -> 잘안씀
	int*** ptr_3, **** int_4;



	printf("\n");
	/* 이중 행렬2D Array를 구현할때 이중포인터를 자주쓴다.		 */
	const int row = 3;
	const int col = 5;

	const int static2Darray[row][col] =
	{
		// 각각이 5개짜리 1차원 array
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
	};


	int* r1 = new int[col] {1, 2, 3, 4, 5};
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};


	/*
		이때 r이 몇개가 나올지 모르니.
		int의 pointer의 array를 만들수 있다
	*/
	int** rows = new int* [row] {r1, r2, r3};

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << rows[r][c] << " ";
		cout << endl;
	}

	/* 위를 for문으로 변경하기			  */	

	int** matrix = new int* [row];

	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			matrix[r][c] = static2Darray[r][c];
	}

	printf("\nfor문으로 처리\n");
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	// delete하기
	for (int r = 0; r < row; ++r)
		delete[] matrix[r];

	delete[] matrix;

	// delete[] r1;
	// delete[] r2;
	// delete[] r3;
	delete[] rows;



	printf("\n2중 행렬을 2중포인터 없이 구현하기\n");
	/* 2중 행렬을 2중포인터 없이 구현하기  
		-> 1차원 array를 2차원처럼 구부려서 사용하기
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


	/* vector를 사용하면 new, delete가 편해진다. */

	return 0;
}