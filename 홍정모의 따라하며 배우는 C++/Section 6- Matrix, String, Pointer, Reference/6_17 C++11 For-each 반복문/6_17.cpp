#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,
							21,34,55,89 };

	// array�� value �ٲٱ� 
	for (auto number : fibonacci)  // -> x
		number *= 10;

	for (auto &number : fibonacci) // -> o
		number *= 10;


	printf("\n");
	// output
	for (const auto &number : fibonacci)
		cout << number << " ";
	cout << endl;



	/* ���� ū ���ڸ� ã�� ��� */

	int max_number = std::numeric_limits<int>::lowest();

	for (const auto& n : fibonacci)
		max_number = std::max(max_number, n);
	    
	cout << "max_number:\t" << max_number << endl;

	
	printf("\n");
	/* Array�� �����Ҵ��ϸ� for-each�� 
		����Ҽ� ���� ��ſ� vector��밡�� */
	
	std::vector<int> fibonacci_v = { 0,1,1,2,3,5,8,13,
							21,34,55,89 };
	
	int max_number_v = std::numeric_limits<int>::lowest();

	for (const auto& n : fibonacci_v)
		max_number_v = std::max(max_number_v, n);

	cout << "max_number_v:\t" << max_number_v << endl;

	return 0;
}
