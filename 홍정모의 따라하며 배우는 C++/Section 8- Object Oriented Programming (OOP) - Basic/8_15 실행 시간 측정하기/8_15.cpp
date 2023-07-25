#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;


/* #1 Sorting하는 시간 재기 */

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	// Timer의 instance가 만들어지는 시간을 member variable로 정의
	std::chrono::time_point<clock_t> start_time = clock_t::now();		


public:
	void elapsed() // 현재시간을 확인하여, 경과 시간을 출력
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();
		
		cout << "elapsed:\t" << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};

/* 예제 설명
* - random number로 vector(10)을 만들고 섞어줬다.
* 그후에 Timer로 시간을 재기 시작하고, sorting을 하고
* timer가 잰 시간을 출력해준다.
* sorting이 끝난 다음에, 결과 확인

*/

int main()
{
	// random number로 vector(1000)을 만들고 섞어줬다.
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(1000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;
	
	std::shuffle(begin(vec), end(vec), mersenne_engine);

	for (auto& e : vec) cout << e << " "; 
	cout<< endl;

	Timer timer; // 그후에 Timer로 시간을 재기 시작하고

	std::sort(begin(vec), end(vec)); // sorting을 하고

	timer.elapsed(); // timer가 잰 시간을 출력해준다.

	// sorting이 끝난 다음에, 결과 확인
	for (auto& e : vec) cout << e << " ";
	cout << endl;

	return 0;
}