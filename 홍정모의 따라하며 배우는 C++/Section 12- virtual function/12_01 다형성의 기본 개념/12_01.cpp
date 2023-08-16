#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		:m_name(name)
	{}

public:
	string getName() { return m_name; }

// #3 virtual Ű���� -> �θ� classŸ���� pointer�ε�, �ڽ� class�ΰ�ó�� �۵�
	virtual void speak() const 
	{
		cout << m_name << " ??? " << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};


int main()
{

	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	printf("\n#1 cat�� dog�� �ּҸ� Aniaml pointer�� �ֱ� \n");
/* #1 cat�� dog�� �ּҸ� Aniaml pointer�� �ֱ� 
	-> �ڽ� class�� �θ� class�� pointer�� ����ؼ� casting�Ͽ� ȣ���ϸ�
	   �θ� classó�� �۵��Ѵ�. */
	Animal* ptr_animal_1 = &cat;
	Animal* ptr_animal_2 = &dog;

// #3 virtual Ű���� -> �θ� classŸ���� pointer�ε�, �ڽ� class�ΰ�ó�� �۵�
	ptr_animal_1->speak(); // speak�Լ��� virtual�� �ƴ϶�� -> "???"
	ptr_animal_2->speak(); // speak�Լ��� virtual�� �ƴ϶�� -> "???"


/* #2 */ 
	Cat cats[] = { Cat("cat1"),Cat("cat2"),Cat("cat3"),Cat("cat4"),Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for(int i=0; i<5; ++i)
		cats[i].speak();

	for (int i = 0; i < 2; ++i)
		dogs[i].speak();

	// ...
	// ������ for���� �ݺ��ϴ� ���, Animal class�� Ȱ���Ͽ� �ݺ� ���̱�
	// ->
	Animal* my_animals[] = { &cats[0],&cats[1],&cats[2],&cats[3],&cats[4],
							&dogs[0],&dogs[1] };

// #3 virtual Ű���� -> �θ� classŸ���� pointer�ε�, �ڽ� class�ΰ�ó�� �۵�
	for (int i = 0; i < 7; ++i)
		my_animals[i]->speak();

	return 0;
}