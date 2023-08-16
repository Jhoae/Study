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

// #3 virtual 키워드 -> 부모 class타입의 pointer인데, 자식 class인것처럼 작동
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

	printf("\n#1 cat과 dog의 주소를 Aniaml pointer에 넣기 \n");
/* #1 cat과 dog의 주소를 Aniaml pointer에 넣기 
	-> 자식 class를 부모 class의 pointer를 사용해서 casting하여 호출하면
	   부모 class처럼 작동한다. */
	Animal* ptr_animal_1 = &cat;
	Animal* ptr_animal_2 = &dog;

// #3 virtual 키워드 -> 부모 class타입의 pointer인데, 자식 class인것처럼 작동
	ptr_animal_1->speak(); // speak함수가 virtual이 아니라면 -> "???"
	ptr_animal_2->speak(); // speak함수가 virtual이 아니라면 -> "???"


/* #2 */ 
	Cat cats[] = { Cat("cat1"),Cat("cat2"),Cat("cat3"),Cat("cat4"),Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for(int i=0; i<5; ++i)
		cats[i].speak();

	for (int i = 0; i < 2; ++i)
		dogs[i].speak();

	// ...
	// 여러번 for문을 반복하는 대신, Animal class를 활용하여 반복 줄이기
	// ->
	Animal* my_animals[] = { &cats[0],&cats[1],&cats[2],&cats[3],&cats[4],
							&dogs[0],&dogs[1] };

// #3 virtual 키워드 -> 부모 class타입의 pointer인데, 자식 class인것처럼 작동
	for (int i = 0; i < 7; ++i)
		my_animals[i]->speak();

	return 0;
}