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

	// ��� ����
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


	// || ��� ����
	int f = 1;
	if (f == 0 || f == 1)
		cout << "f is 0 or 1" << endl;


	/*	���� ���� 	short circuit evaluation 	*/
	int h = 1;
	int i = 2;
	int j = 2;

	if (h == 1 && i++ == 2)
	{
		// do something
	}
	cout << i << endl; // i�� 1�� ������ 3


	if (j == 1 && i++ == 2)
	{
		// do something
	}
	cout << i << endl; // i�� 2. => j != 1�̹Ƿ� if���� �������� ����.
	//=> && �����ڴ� ������ ���� ���������, false��� �������� ������� �ʰ� false�� return�Ѵ�.


	/* ����: ��𸣰� ��Ģ */
	int k = true;
	int l = false;
	!(k && l) != k && !l; 
	!(k && l) == !k || !l;
	
	!(k || l) != k || !l;
	!(k || l) == !k && !l;



	/*	XOR  ������
		
		false false = false
		false true  = true
		true false  = true
		true true   = false

	*/
 	cout << (false != false) << endl;	// 0
	cout << (false != true) << endl;	// 1
	cout << (true != false) << endl;	// 1
	cout << (true != true) << endl;		// 0



	/*	�켱���� ����:: AND( && ) �� OR( || ) �� ���� ���		*/
	//=> &&�� �켱������ || ���� ����
	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v3;	// ==> r1 = v1 || (v2 && v3);
	bool r2 = (v1 || v2) && v3;

	cout << r1 << endl; // 1
	cout << r2 << endl; // 0

	return 0;
}