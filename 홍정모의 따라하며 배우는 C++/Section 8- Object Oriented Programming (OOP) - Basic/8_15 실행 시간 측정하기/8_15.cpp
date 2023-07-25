#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;


/* #1 Sorting�ϴ� �ð� ��� */

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	// Timer�� instance�� ��������� �ð��� member variable�� ����
	std::chrono::time_point<clock_t> start_time = clock_t::now();		


public:
	void elapsed() // ����ð��� Ȯ���Ͽ�, ��� �ð��� ���
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();
		
		cout << "elapsed:\t" << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};

/* ���� ����
* - random number�� vector(10)�� ����� �������.
* ���Ŀ� Timer�� �ð��� ��� �����ϰ�, sorting�� �ϰ�
* timer�� �� �ð��� ������ش�.
* sorting�� ���� ������, ��� Ȯ��

*/

int main()
{
	// random number�� vector(1000)�� ����� �������.
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(1000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;
	
	std::shuffle(begin(vec), end(vec), mersenne_engine);

	for (auto& e : vec) cout << e << " "; 
	cout<< endl;

	Timer timer; // ���Ŀ� Timer�� �ð��� ��� �����ϰ�

	std::sort(begin(vec), end(vec)); // sorting�� �ϰ�

	timer.elapsed(); // timer�� �� �ð��� ������ش�.

	// sorting�� ���� ������, ��� Ȯ��
	for (auto& e : vec) cout << e << " ";
	cout << endl;

	return 0;
}