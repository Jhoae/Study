// 정적 배열 :: size가 compile_time에 결정됨
// 동적 배열 :: size가 run_time에 결정됨 -> 유동적 사용

#include <iostream>

using namespace std;

int main()
{
	/* 정적 배열			  */
	// int length = 5; // ->Error
	const int length = 5;
	int array[length];

	printf("\n동적 배열\n");
	/* 동적 배열			  */
	int length2;
	cin >> length2;
	int* array2 = new int[length2];

	array2[0] = 1;
	array2[1] = 2;
	for (int i = 0; i < length2; ++i)
	{
		cout << "(uintptr_t) & array2[i]:\t" << (uintptr_t) & array2[i] << endl;
		cout << "array2[i]:\t\t\t" << array2[i] << endl;
	}

	delete[] array2;


	printf("\n0으로 초기화\n");
	/*	다양한 초기화 방법	  */	
	int length3, length4;
	cin >> length3;

	int* array3 = new int[length3]();

	array3[0] = 100;
	for (int i = 0; i < length3; ++i)
	{
		cout << "(uintptr_t) & array3[i]:\t" << (uintptr_t)&array3[i] << endl;
		cout << "array3[i]:\t\t\t" << array3[i] << endl;
	}

	cin >> length4;
	int* array4 = new int[length4] {11, 22, 33, 44, 55, 66};
	for (int i = 0; i < length4; ++i)
	{
		cout << "(uintptr_t) & array4[i]:\t" << (uintptr_t)&array4[i] << endl;
		cout << "array4[i]:\t\t\t" << array4[i] << endl;
	}


	/*			  */
	int fixedArray[] = { 1,2,3,4,5 };

	int* array_d = new int[5] { 1, 2, 3, 4, 5 };
// Error: int* array_d = new int[] { 1, 2, 3, 4, 5 };

	delete[] array_d;

	return 0;
}