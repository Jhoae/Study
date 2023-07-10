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

	
	/* switch 방법 1
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

	/* switch 방법 2		*/

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



	/*	사용 예시		*/
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



	/*	주의 사항	 - 비추천하는 방식이긴 함.	*/
	int b;
	cin >> b;
	switch (b)
	{ 
		int c; // 선언은 가능
		// int d = 5; // 대입은 불가능

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


	/*	 추천 사용 방식		  */
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