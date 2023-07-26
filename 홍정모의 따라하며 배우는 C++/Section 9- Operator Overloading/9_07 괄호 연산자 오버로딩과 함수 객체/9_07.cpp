
#include <iostream>
using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator() (int i) { return (m_counter += i); }
};

int main()
{

	Accumulator acc;
	cout << "acc(10):\t" << acc(10) << endl;	//  0 + 10 = 10
	cout << "acc(20):\t" << acc(20) << endl;	// 10 + 20 = 30

	return 0;
}