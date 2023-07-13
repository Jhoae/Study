/*

void pointer 
또는 generic pointer(포괄적인 포인터)

*/

#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr;

	// 전부 문제X
	ptr = &i;
	ptr = &f;
	// ptr = &c;

	// 주소값이 동일하게 할당된다.
	cout << "&f: " << &f << " " << "/ptr: " << ptr << endl;


	printf("\n");
	// int타입 pointer는 포인터연산과 de-ref가 가능하다.
	int* ptr_i = &i; 	
	cout << "*ptr_i\t\t" << *ptr_i << endl;
	cout << "ptr_i\t\t" << ptr_i << endl;
	cout << "ptr_i + 1\t" << ptr_i + 1 << endl;


	printf("\n");
	/* 
	하지만 void pointer는 포인터 연산이 안된다.
	 이유 -> +1을 할때, 몇 bytes를 더해야되는지 알수 없기 때문에
	// Error: cout << ptr + 1 << endl;
	
	또한 de-referencing이 안된다.
	 이유 -> 어떤 타입인지 모르기 때문에
	// Error: cout << *ptr << endl;

	 
	 -> 따라서 값을 가져올때는 
		다음과 같이 강제로 casting해야한다.
	 */
	cout << "*(static_cast<float*>(ptr)):\t" << *(static_cast<float*>(ptr)) << endl;


	return 0;
}