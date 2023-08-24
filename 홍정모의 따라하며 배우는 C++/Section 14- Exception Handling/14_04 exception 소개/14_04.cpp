#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception
{
private:
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
/* #1 */
		std::string s;
		s.resize(-1);

/* #2 */
		throw std::runtime_error("Bad thing happend");

/* #3 */
		throw CustomException();

	}
	catch (std::length_error& exception)
	{
		std::cerr << "Length_Error" << std::endl;
		std::cerr << exception.what() << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << typeid(exception).name() << std::endl;
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}
