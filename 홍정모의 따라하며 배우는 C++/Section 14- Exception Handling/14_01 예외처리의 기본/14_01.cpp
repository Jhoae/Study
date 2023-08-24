#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* #1 �⺻ ����ó�� ���� */
int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); index++)
		if (string[index] == ch)
			return index;

	return -1; // no match
}

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}

	success = false;
	return static_cast<double>(x) / y;
}


int main()
{
/* #1 �⺻ ����ó�� ���� */
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occured" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream input_file("temp.txt");
	if (!input_file)
		std::cerr << "Cannot open file" << std::endl;


/* #2 try, catch, throw �� �̿��� ����ó�� */
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) throw std::string("Negative input");

		cout << std::sqrt(x) << endl;
	}
	catch (std::string error_message)
	{
		// do something to respond
		cout << error_message << endl;
	}



/* #3 �´� Ÿ���� ���°��, casting�� �ؼ� ������ �޴°��� �ƴ϶� 
      runtime error�� �߻���Ų��*/
	try
	{
		// something happend ...
//		throw - 1;
		throw - 1.0;

	}
	catch (int x)
	{
		cout << "Catch integer " << x << endl;
	}
	catch (double x)
	{
		cout << "Catch double " << x << endl;
	}
	catch (std::string error_message)
	{
		cout << error_message << endl;
	}



/* #4 throw �ϴ� type�� ���缭 catch���� �ް� �Ǿ��ִ�. */
	try
	{
		// something happend
		// throw "My error message ";
		throw std::string("My error message ");
		
	}
	
	catch (const char* error_message)
	{
		cout << "Char * " << error_message << endl;
	}
	catch (std::string error_message)
	{
		cout << error_message << endl;
	}


	return 0;
}
