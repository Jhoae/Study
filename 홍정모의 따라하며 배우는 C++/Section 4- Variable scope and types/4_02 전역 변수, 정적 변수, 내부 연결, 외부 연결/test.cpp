#include <iostream>
#include "MyConstants.h"

extern int l = 3;
// extern int l;  // 초기화 안해주면 Error 발생

void sayHello()
{
	using namespace std;

	cout << "Hello" << endl;
	cout << "In test.cpp CON1 " << Constants::pi << "\t 다른 주소: " << &Constants::pi << endl;
	cout << "In test.cpp CON2 " << Constantss2::py << "\t 같은 주소: " << &Constantss2::py << endl;

}