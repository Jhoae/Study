/*
# 설계하는 관점에서 기본 class를 만들때 자식 class에게 제약을 걸어두고 강제하는 방법

① 순수 가상 함수 : body가 없음. 자식class에서 반드시 overriding을 해줘야 함.

② 추상 기본 클래스 : 순수 가상 함수가 포함된 class를 추상 class라고 한다.

③ 인터페이스 클래스 : 순수 가상 함수로만 이루어진 class를 인터페이스 클래스라고 한다.
*/

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

	/*
	#1 function의 body가 없음
	   -> 순수 가상 함수 pure virtual function
	*/
	virtual void speak() const = 0; 

	/*
	virtual void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
	*/
};

/* pure virtual function의 body
void Animal::speak() const
{
	cout << m_name << " ??? " << endl;
}
*/

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

class Cow : public Animal
{
public:
	Cow(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Moooo " << endl;
	}
};


int main()
{
	// ERROR: Animal ani("Hi"); // -> speak의 body가 없으므로 생성 불가능
	// ERROR: ani.speak();

	Cow cow("cow"); // -> speak함수를 반드시 override해야 생성 가능
	cow.speak();

	return 0;
}