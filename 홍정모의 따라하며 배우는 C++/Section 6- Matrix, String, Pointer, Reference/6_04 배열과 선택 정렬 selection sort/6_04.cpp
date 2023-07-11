#include <iostream>

using namespace std;

void printArray(const int array[], const int length)
{
	for (int index = 0; index < length; ++index)
		cout << array[index] << " ";
	cout << endl;
}


int main()
{

	/* 선택 정렬이 이루어지는 예시  */

	/*           value  index
	3 5 2 1 4      1      3
	1 5 2 3 4      2      2 
	1 2 5 3 4      3      3  
	1 2 3 5 4      4      4  
	1 2 3 4 5              
	*/


	/* 	위의 선택 정렬을 코드화  - 내 코드	*/
	
	const int length = 5;

	int array[length] = { 3, 5, 2, 1, 4 };

	printArray(array, length);

	for (int i = 0; i < length-1; ++i)
	{
		int value = array[i];
		int index = i;

		for (int j = i; j < length; j++)
		{
			if (value > array[j])
			{
				value = array[j];
				index = j;
			}
		}
			array[index] = array[i];
			array[i] = value;
	}

	printArray(array, length);




	printf("\n");
	/* 	위의 선택 정렬을 코드화  - 수업 코드	*/

	const int length2 = 5;

	int array2[length2] = { 3, 5, 2, 1, 4 };

	printArray(array2, length2);

	/* 	std::swap(...)
	
	int temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	*/

	for (int startIndex = 0; startIndex < length2 - 1; ++startIndex)
	{

		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length2; ++currentIndex)
		{
			if (array2[smallestIndex] > array2[currentIndex])
			{
				// index를 저장하면 value는 자연스레 알수있음
				smallestIndex = currentIndex; 
			}
		}

		// swap
		// std::swap(array2[smallestIndex], array2[startIndex]);
		int temp = array2[smallestIndex];
		array2[smallestIndex] = array2[startIndex];
		array2[startIndex] = temp;
	}
	
	printArray(array2, length2);


	// 추가 공부 :Bubble sort

	return 0;
}