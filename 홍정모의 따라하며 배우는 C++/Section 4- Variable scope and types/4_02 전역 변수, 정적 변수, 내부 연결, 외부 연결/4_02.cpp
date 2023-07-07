#include <iostream>
#include "MyConstants.h"

using namespace std;

int value = 123;  // 전역변수
static int g_a = 1;	// static 전역변수 -> 다른 cpp파일에서 접근 불가

// 전방 선언 forward declaration 
extern void sayHello(); // 어딘가에 sayHello가 존재한다는 의미.
extern int l;
// extern int l = 456;  // 다시 초기화한다면 Error 발생
 
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
	/*	전역변수와 지역변수			*/
	cout << value << endl;
	

	int value = 1;	// 지역변수. (덮어쓰기)
	cout << value << endl;
	cout << ::value << endl; // 다른 영역에 정의된 변수 사용


	printf("\n");
	/*	Static	: 변수가 할당받은 메모리가 static된다는 뜻.	
		 => static으로 정의한 변수는 여러번 선언되어도 
		   "같은 메모리"를 쓰며, "초기화를 처음 실행시 1번밖에" 안한다. 
		   (반복되어 할당되는 메모리를 재사용한다.)
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

	sayHello();			// 다른 cpp 파일의 함수
	cout << l << endl;	// 다른 cpp 파일의 변수


	printf("\n");
	/*	다른 파일에서 가져와서 쓰기 - 내부연결/외부연결		*/

	cout << "In main.cpp file CON1 " << Constants::pi << "\t 다른 주소: " << &Constants::pi << endl;
	cout << "In main.cpp file CON2 " << Constantss2::py << "\t 같은 주소: " << &Constantss2::py << endl;
	sayHello();


	return 0;
}



/* 정리		

	int g_x;		// 외부 연결 external linkage
	static int g_x; // 내부 연결internal linkage
	const int g_x;	// -> 초기화 하지 않으면 Error

	extern int g_z;
	extern const int g_z; // 다른곳에서 초기화 해주어야함

	int g_y(1);			// 초기화된 external linkage
	static int g_y(1);	// 초기화된 internal linkage
	const int g_y(1);	// 일반적인 상수 선언 (같은 파일 안에서만 접근가능)

	extern int g_w(1);		// 초기화o, 전역변수, 외부(다른파일)에서 접근가능external linkage
	extern const int g_w(1); // 상수, 초기화o, 외부에서 접근가능external linkage

*/