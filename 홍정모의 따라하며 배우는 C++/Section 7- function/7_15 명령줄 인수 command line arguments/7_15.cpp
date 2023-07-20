#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	for (int count = 0; count < argc; ++count)
	{
		cout << "argv[count]: "  << argv[count] << endl;
	}

	printf("\nstring»ç¿ë\n");
	for (int count = 0; count < argc; ++count)
	{
		std::string argv_single = argv[count];

		if (count == 1)
		{
			int input_number = std::stoi(argv_single);
			cout << "input_number + 1" << input_number +1 << endl;
		}
		else
			cout << "argv_single: " << argv_single << endl;
	}

	return 0;
}