// 의도하지 않은 입력이 들어왔을때 대응법

#include <iostream>

using namespace std;

int getInt()
{

	while (true)
	{

		cout << "Enter a integer number : ";
		int x;
		cin >> x;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n'); // 32767은 적당히 큰 숫자
			cout << "Invalid number, try again." << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); // 32767은 적당히 큰 숫자

			return x;
		}
	}
}

char getOperator()
{
	while (true)
	{

		cout << "Enter an operator (+, -) : "; // TODO: more operator *, / etc
		char op;
		cin >> op;
		// 사용자가 여러 숫자를 입력했을때를 대비해서 buffer clear
		std::cin.ignore(32767, '\n'); // 32767은 적당히 큰 숫자

		if (op == '+' || op == '-')
			return op;
		else
			cout << "Invalid operator, please try again." << endl;
	}
}

void printfResult(int x, char op, int y)
{
	if (op == '+') cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else
	{
		cout << "Invalid operator" << endl;
	}
}



int main()
{

	int x = getInt();
	char op = getOperator();
	int y = getInt();

	printfResult(x, op, y);


	return 0;
}