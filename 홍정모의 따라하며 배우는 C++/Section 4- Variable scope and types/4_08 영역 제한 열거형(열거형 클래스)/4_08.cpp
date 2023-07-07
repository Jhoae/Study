// Enum Class

#include <iostream>

int main()
{
	using namespace std;

	enum Color
	{
		RED,
		BLUE,
	};

	enum Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = RED;
	Fruit fruit = BANANA;


	if (color == fruit)
		cout << "1 equal?" << endl;


	// ����->

	enum class Color2
	{
		RED2,
		BLUE2,
	};

	enum class Fruit2
	{
		BANANA2,
		APPLE2,
	};

	Color2 color2 = Color2::RED2;
	Fruit2 fruit2 = Fruit2::BANANA2;




	/*	Error�� �߻�������
	if (color2 == fruit2)
		cout << "1 equal?" << endl;
	*/
	// ������ �񱳴� ����
	if (static_cast<int>(color2) == static_cast<int>(fruit2))
		cout << "2 equal? (����)" << endl;



	return 0;
}