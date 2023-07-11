// �ǵ����� ���� �Է��� �������� ������

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
			std::cin.ignore(32767, '\n'); // 32767�� ������ ū ����
			cout << "Invalid number, try again." << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); // 32767�� ������ ū ����

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
		// ����ڰ� ���� ���ڸ� �Է��������� ����ؼ� buffer clear
		std::cin.ignore(32767, '\n'); // 32767�� ������ ū ����

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