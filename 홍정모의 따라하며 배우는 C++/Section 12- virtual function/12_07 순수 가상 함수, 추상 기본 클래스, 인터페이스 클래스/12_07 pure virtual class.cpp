/*
# �����ϴ� �������� �⺻ class�� ���鶧 �ڽ� class���� ������ �ɾ�ΰ� �����ϴ� ���

�� ���� ���� �Լ� : body�� ����. �ڽ�class���� �ݵ�� overriding�� ����� ��.

�� �߻� �⺻ Ŭ���� : ���� ���� �Լ��� ���Ե� class�� �߻� class��� �Ѵ�.

�� �������̽� Ŭ���� : ���� ���� �Լ��θ� �̷���� class�� �������̽� Ŭ������� �Ѵ�.
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
	#1 function�� body�� ����
	   -> ���� ���� �Լ� pure virtual function
	*/
	virtual void speak() const = 0; 

	/*
	virtual void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
	*/
};

/* pure virtual function�� body
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
	// ERROR: Animal ani("Hi"); // -> speak�� body�� �����Ƿ� ���� �Ұ���
	// ERROR: ani.speak();

	Cow cow("cow"); // -> speak�Լ��� �ݵ�� override�ؾ� ���� ����
	cow.speak();

	return 0;
}