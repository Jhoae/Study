#include <iostream>
#include "MyConstants.h"

extern int l = 3;
// extern int l;  // �ʱ�ȭ �����ָ� Error �߻�

void sayHello()
{
	using namespace std;

	cout << "Hello" << endl;
	cout << "In test.cpp CON1 " << Constants::pi << "\t �ٸ� �ּ�: " << &Constants::pi << endl;
	cout << "In test.cpp CON2 " << Constantss2::py << "\t ���� �ּ�: " << &Constantss2::py << endl;

}