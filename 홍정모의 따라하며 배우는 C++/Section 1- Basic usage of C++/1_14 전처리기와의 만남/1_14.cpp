#include <iostream>
#include <algorithm>
using namespace std;

#define MY_NUMBER 9
#define LIKE_APPLE	// ���� ������ 1_14.cpp ���Ϲ��� ���� �����Ƿ� doSomething�� ����x

void doSomething();

int main()
{
	doSomething(); // ���� ������ 1_14.cpp ���Ϲ��� ���� �����Ƿ� doSomething�� ����x

#ifndef LIKE_APPLE	
	cout << "Orange" << endl;
#endif // !LIKE_APPLE

	cout << MY_NUMBER << endl;

	return 0;
}