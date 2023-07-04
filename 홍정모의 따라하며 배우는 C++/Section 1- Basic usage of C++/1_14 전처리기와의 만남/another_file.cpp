#include <iostream>


void doSomething()
{
using namespace std;

#ifdef LIKE_APPLE
	cout << "Apple" << endl;
#else
	cout << "Not Apple" << endl;
#endif // LIKE_APPLE

}