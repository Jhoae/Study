#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// void printLength(array<int, 5> my_arr)
void printLength(const array<int, 5>& my_arr) 
// -> 매개변수가 변하지않고(:const), 복사되지 않기를 원할때(&:: ref사용)
{
	cout << "printLength:\t" << my_arr.size() << endl;
}


int main()
{
	int arr[] = { 1,2,3,4,5 };

	// 단점: 숫자가 꼭 들어가야함
	std::array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 0, 1,2,3,4 };
	my_arr = { 0, 1, 2 }; // 나머지 0으로 채워줌 

	cout << "my_arr[0]:\t" << my_arr[0] << endl;
	cout << "my_arr.at(0):\t" << my_arr.at(0) << endl;

	printf("\n.size()\n");
	cout << "my_arr.size():\t" << my_arr.size() << endl;
	printLength(my_arr);



	/*	편리한	  */
	array<int, 5> my_arr2 = { 1,21,3,40,5 };

	printf("\n정렬sort 전\n");
	for (auto &element : my_arr2) // &:: 복사 생략
		cout << element << " ";
	cout << endl;

	// 정렬(sort)
	std::sort(my_arr2.begin(), my_arr2.end());

	printf("\n정렬sort 후\n");
	for (auto& element : my_arr2) // &:: 복사 생략
		cout << element << " ";
	cout << endl;

	// 역순 정렬 (reverse-sort)
	std::sort(my_arr2.rbegin(), my_arr2.rend());

	printf("\n역순 정렬reverse-sort 후\n");
	for (auto& element : my_arr2) // &:: 복사 생략
		cout << element << " ";
	cout << endl;

	return 0;
}