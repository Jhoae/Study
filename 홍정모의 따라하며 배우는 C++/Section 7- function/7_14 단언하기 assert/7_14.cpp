#include <iostream>
#include <cassert> // assert
#include <array>

using namespace std;

void printValue(const std::array<int, 5>&my_arr, const int &ix)
{
	assert(ix >= 0);
	assert(ix <= my_arr.size() - 1);

	cout << my_arr[ix] << endl;
}

int main()
{


/* assert�� runtime�� �����ϸ�,
	Debug��忡���� �����ϰ�, Release��忡���� �۵����� �ʴ´�. */
	int number = 5;

	// ... 
	// number�� 5���� �Ѵ�

	assert(number == 5);


/* array�� ����ϴ� �Լ����� assert�� ����ϴ� ���  */
	std::array<int, 5>my_arr{ 1,2,3,4,5 };
	printValue(my_arr, 2);
	


/* compile time�� �����ϴ� static assert 
   - �����Ϸ��� �̿��ؼ� ���α׷����� ���� ������  �̸� ���� */
	int k = 5;
	assert(k == 5);

	// compile time�� �����Ǵ°͸� ��밡��
	// k = 10; ó�� ���߿� �ٲ�� �ֱ� ������ �����߻�
	// static_assert(k == 5);  :: ERROR	

	const int c = 5;
	static_assert(c == 5, "c should be 5");



	return 0;
}