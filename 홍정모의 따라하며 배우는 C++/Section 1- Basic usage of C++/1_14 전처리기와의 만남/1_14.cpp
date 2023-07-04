#include <iostream>
#include <algorithm>
using namespace std;

#define MY_NUMBER 9
#define LIKE_APPLE	// 정의 범위는 1_14.cpp 파일범위 내에 있으므로 doSomething에 영향x

void doSomething();

int main()
{
	doSomething(); // 정의 범위는 1_14.cpp 파일범위 내에 있으므로 doSomething에 영향x

#ifndef LIKE_APPLE	
	cout << "Orange" << endl;
#endif // !LIKE_APPLE

	cout << MY_NUMBER << endl;

	return 0;
}