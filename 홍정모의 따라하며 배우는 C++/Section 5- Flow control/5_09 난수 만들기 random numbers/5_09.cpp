#include <iostream>
#include <cstdlib> // std::radn(), std::srand()
#include <ctime>
#include <random>

using namespace std;

unsigned int PRNG() // pseudo 코드
{
	static unsigned int seed = 5323;

	seed = 8253729 * seed + 2396403;

	return seed % 32768;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	
	return min + static_cast<int>((max - min + 1)* (std::rand() * fraction));
}

int main()
{

	/*	직접 구현		 */
	printf("\n직접 구현\n\n");
	for (int count = 1; count <= 100; ++count)
	{
	cout << PRNG() << "\t";

	if (count % 5 == 0) cout << endl;
	}
	
	/*	std::radn()		 */
	printf("\nstd::radn()\n\n");
	// std::srand(5323); // seed가 고정되면 계속 같은 랜덤숫자가 나온다.
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (int count = 1; count <= 100; ++count)
	{
		cout << std::rand() << "\t";

		if (count % 5 == 0) cout << endl;
	}


	printf("\nrandom number의 범위 설정하기\n\n");
	/*	random number의 범위 직접 설정하기		*/
	for (int count = 1; count <= 100; count++)
	{
		cout << getRandomNumber(5, 8) << "\t";

		if (count % 5 == 0) cout << endl;
	}

	//
	printf("\n");
	for (int count = 1; count <= 100; count++)
	{
		cout << rand() % 4 + 5 << "\t"; // 5 ~ 8

		if (count % 5 == 0) cout << endl;
	}

	printf("\nrandom number 라이브러리 사용\n\n");
	/*	random number 라이브러리			 */
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<>dice(1, 6);

	for (int count = 1; count <= 20; ++count)
		cout << dice(mersenne) << endl;


	return 0;
}