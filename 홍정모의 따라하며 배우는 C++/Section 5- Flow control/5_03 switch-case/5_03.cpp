#include <iostream>

using namespace std;

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
};

void printColorName(Colors color)
{
	/*
	if (color == Colors::BLACK)
		cout << "BLACK" << endl;
	else if (color == Colors::WHITE)
		cout << "WHITE" << endl;
	else if (color == Colors::RED)
		cout << "RED" << endl;
	else if (color == Colors::GREEN)
		cout << "GREEN" << endl;
	else if (color == Colors::BLUE)
		cout << "BLUE" << endl;
	*/

	
	/* switch ��� 1
	switch (color)
	{
	case Colors::BLACK :
		cout << "BLACK" << endl;
		break;
	case Colors::WHITE:
		cout << "WHITE" << endl;
	case Colors::RED:
		cout << "RED" << endl;
	// ...
	*/

	/* switch ��� 2		*/

	switch( static_cast<int>(color))
	{
	case 0:
		cout << "Black" << endl;
		break;
	case 1:
		cout << "White" << endl;
		break;
	// ...
	}

}


int main()
{

	int a;
	cin >> a;



	/*	��� ����		*/
	{
		switch (a)
		{
		case 0:
			cout << "Zero";
			break;
		case 1:
			cout << "One";
			break;
		case 2:
			cout << "Two";
			break;
		}
		cout << endl;
	}



	/*	���� ����	 - ����õ�ϴ� ����̱� ��.	*/
	int b;
	cin >> b;
	switch (b)
	{ 
		int c; // ������ ����
		// int d = 5; // ������ �Ұ���

	case 0:
		int e;
		int f;
		f = 5;
		break;

	case 1:
		e = 5;
		cout << e << endl;
		cout << f << endl;
	}


	/*	 ��õ ��� ���		  */
	int x;
	cin >> x;

	switch (x)
	{
		case 0:
		{
			int y = 5;
			y = y + x;
			cout << y << endl;
			break;
		}

		case 1:
		{
			int y = 5;
			y = y - x;
			cout << y << endl;
			break;
		}

		default:
			cout << "Undefined input" << endl;
			// break;
	}


	return 0;
}