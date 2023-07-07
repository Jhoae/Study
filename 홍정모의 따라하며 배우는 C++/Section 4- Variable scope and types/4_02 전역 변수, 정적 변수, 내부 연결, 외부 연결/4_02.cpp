#include <iostream>
#include "MyConstants.h"

using namespace std;

int value = 123;  // ��������
static int g_a = 1;	// static �������� -> �ٸ� cpp���Ͽ��� ���� �Ұ�

// ���� ���� forward declaration 
extern void sayHello(); // ��򰡿� sayHello�� �����Ѵٴ� �ǹ�.
extern int l;
// extern int l = 456;  // �ٽ� �ʱ�ȭ�Ѵٸ� Error �߻�
 
void GlobaldoSomething()
{
	++g_a;
	cout << g_a << endl;
}

void doSomething()
{
	int a = 1;
	++a;
	cout << a << endl;
}
void StaticDoSomething()
{
	static int a = 1;
	++a;
	cout << a << endl;
}





int main()
{
	/*	���������� ��������			*/
	cout << value << endl;
	

	int value = 1;	// ��������. (�����)
	cout << value << endl;
	cout << ::value << endl; // �ٸ� ������ ���ǵ� ���� ���


	printf("\n");
	/*	Static	: ������ �Ҵ���� �޸𸮰� static�ȴٴ� ��.	
		 => static���� ������ ������ ������ ����Ǿ 
		   "���� �޸�"�� ����, "�ʱ�ȭ�� ó�� ����� 1���ۿ�" ���Ѵ�. 
		   (�ݺ��Ǿ� �Ҵ�Ǵ� �޸𸮸� �����Ѵ�.)
	*/

	doSomething();	// 2
	doSomething();	// 2
	doSomething();	// 2
	
	GlobaldoSomething(); // 2
	GlobaldoSomething(); // 3
	GlobaldoSomething(); // 4

	StaticDoSomething(); // 2
	StaticDoSomething(); // 3
	StaticDoSomething(); // 4


	printf("\n");
	/*						 */

	sayHello();			// �ٸ� cpp ������ �Լ�
	cout << l << endl;	// �ٸ� cpp ������ ����


	printf("\n");
	/*	�ٸ� ���Ͽ��� �����ͼ� ���� - ���ο���/�ܺο���		*/

	cout << "In main.cpp file CON1 " << Constants::pi << "\t �ٸ� �ּ�: " << &Constants::pi << endl;
	cout << "In main.cpp file CON2 " << Constantss2::py << "\t ���� �ּ�: " << &Constantss2::py << endl;
	sayHello();


	return 0;
}



/* ����		

	int g_x;		// �ܺ� ���� external linkage
	static int g_x; // ���� ����internal linkage
	const int g_x;	// -> �ʱ�ȭ ���� ������ Error

	extern int g_z;
	extern const int g_z; // �ٸ������� �ʱ�ȭ ���־����

	int g_y(1);			// �ʱ�ȭ�� external linkage
	static int g_y(1);	// �ʱ�ȭ�� internal linkage
	const int g_y(1);	// �Ϲ����� ��� ���� (���� ���� �ȿ����� ���ٰ���)

	extern int g_w(1);		// �ʱ�ȭo, ��������, �ܺ�(�ٸ�����)���� ���ٰ���external linkage
	extern const int g_w(1); // ���, �ʱ�ȭo, �ܺο��� ���ٰ���external linkage

*/