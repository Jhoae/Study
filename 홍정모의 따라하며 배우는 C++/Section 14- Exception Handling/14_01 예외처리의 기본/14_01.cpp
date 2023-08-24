#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* #1 기본 예외처리 예시 */
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
/* #1 기본 예외처리 예시 */
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occured" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream input_file("temp.txt");
	if (!input_file)
		std::cerr << "Cannot open file" << std::endl;


/* #2 try, catch, throw 를 이용한 예외처리 */
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



/* #3 맞는 타입이 없는경우, casting을 해서 억지로 받는것이 아니라 
      runtime error를 발생시킨다*/
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



/* #4 throw 하는 type에 맞춰서 catch에서 받게 되어있다. */
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
