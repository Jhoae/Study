#include <iostream>

using namespace std;

class Fruit
{
public:
/* Ư�� class������ ���Ǵ� data type�� class������ ������ �ִ�. */
	// enum type
	enum FruitType
	{
		APPLE, BANANA, CHERRY,
	};
	
private:
	FruitType m_type; /* FruitType�� member variable�� ��� */

public:
	Fruit(FruitType type):m_type(type) 
	{}

	FruitType getType() { return m_type; }
};



/* #2 Enum class */
class Fruit_C
{
public:
/* ����:: Ư�� class������ ���Ǵ� data type�� 
			class������ ������ �ִ�. */

	
	// �� enum class
	enum class FruitType_C
	{
		APPLE, BANANA, CHERRY,
	};

	// �� Inner class
	class InnerClass
	{

	};

	// �� Inner struct
	struct InnerStruct
	{

	};

private:
	FruitType_C m_type; /* FruitType�� member variable�� ��� */

public:
	Fruit_C(FruitType_C type) :m_type(type)
	{}

	FruitType_C getType() { return m_type; }
};

int main()
{
/* #1 Enum type ��� */
	Fruit apple(Fruit::APPLE);

	if (apple.getType() == Fruit::APPLE)
	{
		cout << "Apple" << endl;
	}
	



/* #2 Enum class ��� */
	Fruit_C banana(Fruit_C::FruitType_C::BANANA);

	if (banana.getType() == Fruit_C::FruitType_C::BANANA)
	{
		cout << "Banana" << endl;
	}

	return 0;
}