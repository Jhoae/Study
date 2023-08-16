#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

/* #1 static binding (early binding) 
   ->  결과가 buildtime에 정리가 되어있다.*/
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;

/* #2 Dynamic binding (late binding)  
   -> func_ptr에 가리키는 주소가 runtime에 결정된다 */ 
	int (*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0:func_ptr = add; break;
	case 1:func_ptr = subtract; break;
	case 2:func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl;


/*  정리
	① 속도 : static 바인딩 > dynamic 바인딩 
	② 프로그램 유연성 : static 바인딩 < dynamic 바인딩 
*/

	return 0;
}