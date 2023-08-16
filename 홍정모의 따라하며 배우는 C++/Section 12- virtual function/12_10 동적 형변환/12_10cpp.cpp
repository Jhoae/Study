/* 동적 형변환
 다형성을 사용하다보면 자식 class의 pointer를 
 부모 class의 pointer로 바꿔줬다가,
 다시 자식 class의 pointer로 바꿔야 할 경우가 생긴다.
 이때 사용하는 동적 형변환이다.
*/

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};


int main()
{
	Derived1 d1;
	d1.m_j = 2048;

	// .......

	Base* base = &d1;
	// Error: 	base->m_j;

/* #1 base를 다시 Derived1으로 동적 형변환 */
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << "base_to_d1->m_j:\t " 
		<< base_to_d1->m_j << endl;

	base_to_d1->m_j = 2222;

	cout << "d1.m_j:\t " << d1.m_j << endl;


/* #2 주의할 점 - 문제가 될 경우 
 - dynamic_cast는 runtime에 경고를 발생,
 - static_cast는 상관없이 밀어붙인다
*/

	Derived1 d1_2;
	Base* base_2 = &d1_2;

	auto* base_to_d2_d = dynamic_cast<Derived2*>(base_2);
	auto* base_to_d2_s = static_cast<Derived2*>(base_2);

	/*
	  #2-1 dynamic_cast
	   runtime에서 error check를 해주어 문제를 잡아준다.
	   -> "d Failed"
	*/
	if (base_to_d2_d != nullptr)
		base_to_d2_d->print();
	else
		cout << "d Failed" << endl;

	/*
	  #2-2 static_cast
	    static_cast는 runtime에서 error check를 안하고 밀어붙인다.
        -> print()함수 실행
	*/
	if (base_to_d2_s != nullptr)
		base_to_d2_s->print();
	else
		cout << "s Failed" << endl;

	return 0;
}