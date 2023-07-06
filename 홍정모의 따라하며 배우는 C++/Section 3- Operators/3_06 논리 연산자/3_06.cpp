#include <iostream>

int main()
{
	using namespace std;

	// logical NOT: !
	bool a = true;
	cout << !a << endl;

	// logical AND: &&
	bool b = true;
	bool c = false;
	cout << (b && c) << endl;

	// 사용 예시
	bool hit = true;
	int health = 10;
	if (hit == true && health < 20)
		cout << "die" << endl;
	else
		health -= 20;



	// logical OR: ||
	cout << (b || c) << endl; // 

	// !=
	int d = 6;
	int e = 5;
	if (d != e)
		cout << "d not equal e" << endl;
	else
		cout << "d equal e" << endl;


	// || 사용 예시
	int f = 1;
	if (f == 0 || f == 1)
		cout << "f is 0 or 1" << endl;


	/*	주의 사항 	short circuit evaluation 	*/
	int h = 1;
	int i = 2;
	int j = 2;

	if (h == 1 && i++ == 2)
	{
		// do something
	}
	cout << i << endl; // i는 1이 증가한 3


	if (j == 1 && i++ == 2)
	{
		// do something
	}
	cout << i << endl; // i는 2. => j != 1이므로 if문이 동작하지 않음.
	//=> && 연산자는 왼쪽을 먼저 계산했을때, false라면 오른쪽을 계산하지 않고 false를 return한다.


	/* 참고: 드모르간 법칙 */
	int k = true;
	int l = false;
	!(k && l) != k && !l; 
	!(k && l) == !k || !l;
	
	!(k || l) != k || !l;
	!(k || l) == !k && !l;



	/*	XOR  연산자
		
		false false = false
		false true  = true
		true false  = true
		true true   = false

	*/
 	cout << (false != false) << endl;	// 0
	cout << (false != true) << endl;	// 1
	cout << (true != false) << endl;	// 1
	cout << (true != true) << endl;		// 0



	/*	우선순위 주의:: AND( && ) 와 OR( || ) 가 섞인 경우		*/
	//=> &&의 우선순위가 || 보다 높다
	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v3;	// ==> r1 = v1 || (v2 && v3);
	bool r2 = (v1 || v2) && v3;

	cout << r1 << endl; // 1
	cout << r2 << endl; // 0

	return 0;
}