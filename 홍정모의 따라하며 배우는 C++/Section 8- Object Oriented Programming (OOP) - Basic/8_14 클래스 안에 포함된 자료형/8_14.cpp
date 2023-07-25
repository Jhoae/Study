#include <iostream>

using namespace std;

class Fruit
{
public:
/* 특정 class에서만 사용되는 data type은 class안으로 넣을수 있다. */
	// enum type
	enum FruitType
	{
		APPLE, BANANA, CHERRY,
	};
	
private:
	FruitType m_type; /* FruitType을 member variable로 사용 */

public:
	Fruit(FruitType type):m_type(type) 
	{}

	FruitType getType() { return m_type; }
};



/* #2 Enum class */
class Fruit_C
{
public:
/* ①②③:: 특정 class에서만 사용되는 data type은 
			class안으로 넣을수 있다. */

	
	// ① enum class
	enum class FruitType_C
	{
		APPLE, BANANA, CHERRY,
	};

	// ② Inner class
	class InnerClass
	{

	};

	// ③ Inner struct
	struct InnerStruct
	{

	};

private:
	FruitType_C m_type; /* FruitType을 member variable로 사용 */

public:
	Fruit_C(FruitType_C type) :m_type(type)
	{}

	FruitType_C getType() { return m_type; }
};

int main()
{
/* #1 Enum type 사용 */
	Fruit apple(Fruit::APPLE);

	if (apple.getType() == Fruit::APPLE)
	{
		cout << "Apple" << endl;
	}
	



/* #2 Enum class 사용 */
	Fruit_C banana(Fruit_C::FruitType_C::BANANA);

	if (banana.getType() == Fruit_C::FruitType_C::BANANA)
	{
		cout << "Banana" << endl;
	}

	return 0;
}