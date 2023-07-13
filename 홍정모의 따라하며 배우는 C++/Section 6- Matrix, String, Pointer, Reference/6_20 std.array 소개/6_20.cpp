#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// void printLength(array<int, 5> my_arr)
void printLength(const array<int, 5>& my_arr) 
// -> �Ű������� �������ʰ�(:const), ������� �ʱ⸦ ���Ҷ�(&:: ref���)
{
	cout << "printLength:\t" << my_arr.size() << endl;
}


int main()
{
	int arr[] = { 1,2,3,4,5 };

	// ����: ���ڰ� �� ������
	std::array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 0, 1,2,3,4 };
	my_arr = { 0, 1, 2 }; // ������ 0���� ä���� 

	cout << "my_arr[0]:\t" << my_arr[0] << endl;
	cout << "my_arr.at(0):\t" << my_arr.at(0) << endl;

	printf("\n.size()\n");
	cout << "my_arr.size():\t" << my_arr.size() << endl;
	printLength(my_arr);



	/*	����	  */
	array<int, 5> my_arr2 = { 1,21,3,40,5 };

	printf("\n����sort ��\n");
	for (auto &element : my_arr2) // &:: ���� ����
		cout << element << " ";
	cout << endl;

	// ����(sort)
	std::sort(my_arr2.begin(), my_arr2.end());

	printf("\n����sort ��\n");
	for (auto& element : my_arr2) // &:: ���� ����
		cout << element << " ";
	cout << endl;

	// ���� ���� (reverse-sort)
	std::sort(my_arr2.rbegin(), my_arr2.rend());

	printf("\n���� ����reverse-sort ��\n");
	for (auto& element : my_arr2) // &:: ���� ����
		cout << element << " ";
	cout << endl;

	return 0;
}