#include <iostream>

using namespace std;

int main()
{

	/*	다차원 배열   */

	const int num_rows = 3;
	const int num_columns = 5;

	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
			cout << '[' << row << ']' << '[' << col << ']' << '\t';

		cout << endl;
	}

	cout << endl;


	printf("\n");
	/*	2차원 배열 선언하는 방법			*/
	int array[num_rows][num_columns] = // row-major <-> column-major
	{
		{1, 2, },             // row[0]
		{6, 7, 8, 9, 10},     // row[1]
		{11, 12, 13, 14, 15}, // row[2]
	};


	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
		{
			cout << array[row][col] << '\t';
			// 다차원 배열의 주소값을 확인해보면 실제론 1차원			 
			cout << "주소: " << (int)&array[row][col] << '\t';

		}

		cout << endl;
	}

	cout << endl;


	/*	3차원 배열 - 선언 방식			  */
	int array[2][3][4] = {
		{
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
		},
		{
			{13, 14, 15, 16},
			{17, 18, 19, 20},
			{21, 22, 23, 24}
		}
	};



	return 0;
}