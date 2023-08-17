#include "MyArray.h"

int main()
{
	// MyArray my_array(10);
	MyArray<double> my_array(10);

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i * 0.5;

	my_array.print();



	MyArray<char> my_array_2(10);

	for (int i = 0; i < my_array_2.getLength(); ++i)
		my_array_2[i] = i + 65;

	my_array_2.print();

	return 0;
}