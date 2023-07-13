/*

- 정적 배열을 대체할수있는 std::array
- 동적 배열을 대체할수있는 std::vector

std::vector
 -> new, delete를 사용하는
	동적 메모리 할당과 달리
	delete를 하지 않아도 메모리를 지워준다.
*/


#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	/*
	std::array<int, 5> arr; 과 달리 size를 안적어도됨
	*/
	std::vector<int> arr;

	// 초기화하는 방법
	std::vector<int> arr2 = { 1,2,3,4,5 };

	cout << "arr2.size():\t" << arr2.size() << endl;

	std::vector<int>arr3 = { 1,2,3 };

	cout << "arr3.size():\t" << arr3.size() << endl;

	std::vector<int>arr4 { 1,2,3 };

	cout << "arr4.size():\t" << arr4.size() << endl;



	printf("\n");
	/* resize하는 법				*/
	vector <int> arr_c = { 1,2,3,4,5 };

	arr_c.resize(10);

	for (auto& itr : arr_c)
		cout << "arr_c:\t" << itr << endl;
	
	printf("\nresize로 10으로 늘린 이후 arr_c\n");
	cout << "arr_c.size()\t" << arr_c.size() << endl;
	cout << "arr_c[1]:\t" << arr_c[1] << endl;
	cout << "arr_c.at(1):\t" << arr_c.at(1) << endl;


	printf("\nresize로 2로 줄인 이후 arr_c-> 사라진다\n");
	arr_c.resize(2); 

	for (auto& itr : arr_c)
		cout << "arr_c:\t" << itr << endl;

	cout << "arr_c.size()\t" << arr_c.size() << endl;
	cout << "arr_c[1]:\t" << arr_c[1] << endl;
	cout << "arr_c.at(1):\t" << arr_c.at(1) << endl;

	return 0;
}