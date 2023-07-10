/*
while문과 다른점 ::

처음 1번은 반드시 실행된다.
*/ 

#include <iostream>

using namespace std;

int main()
{
	int selection; // 반드시 do.while loop 밖에서 선언해야 가능.

	do 
	{
		cout << "1. add" << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;
		cin >> selection;
	} while (selection <= 0 || selection >= 5);

	cout << "You selected " << selection << endl;

	return 0;
}