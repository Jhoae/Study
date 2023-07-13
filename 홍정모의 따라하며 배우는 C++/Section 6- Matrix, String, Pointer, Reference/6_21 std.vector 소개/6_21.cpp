/*

- ���� �迭�� ��ü�Ҽ��ִ� std::array
- ���� �迭�� ��ü�Ҽ��ִ� std::vector

std::vector
 -> new, delete�� ����ϴ�
	���� �޸� �Ҵ�� �޸�
	delete�� ���� �ʾƵ� �޸𸮸� �����ش�.
*/


#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	/*
	std::array<int, 5> arr; �� �޸� size�� �������
	*/
	std::vector<int> arr;

	// �ʱ�ȭ�ϴ� ���
	std::vector<int> arr2 = { 1,2,3,4,5 };

	cout << "arr2.size():\t" << arr2.size() << endl;

	std::vector<int>arr3 = { 1,2,3 };

	cout << "arr3.size():\t" << arr3.size() << endl;

	std::vector<int>arr4 { 1,2,3 };

	cout << "arr4.size():\t" << arr4.size() << endl;



	printf("\n");
	/* resize�ϴ� ��				*/
	vector <int> arr_c = { 1,2,3,4,5 };

	arr_c.resize(10);

	for (auto& itr : arr_c)
		cout << "arr_c:\t" << itr << endl;
	
	printf("\nresize�� 10���� �ø� ���� arr_c\n");
	cout << "arr_c.size()\t" << arr_c.size() << endl;
	cout << "arr_c[1]:\t" << arr_c[1] << endl;
	cout << "arr_c.at(1):\t" << arr_c.at(1) << endl;


	printf("\nresize�� 2�� ���� ���� arr_c-> �������\n");
	arr_c.resize(2); 

	for (auto& itr : arr_c)
		cout << "arr_c:\t" << itr << endl;

	cout << "arr_c.size()\t" << arr_c.size() << endl;
	cout << "arr_c[1]:\t" << arr_c[1] << endl;
	cout << "arr_c.at(1):\t" << arr_c.at(1) << endl;

	return 0;
}