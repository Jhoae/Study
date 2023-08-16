#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}		
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}


void doSomething_2(Base b)
{
	b.print();
}


int main()
{
/* #1 다형성 발현이 발현되는 경우 */
	Derived d;
	Base& b = d; // 다형성 발현 

	b.print(); // "I'm Derived"
	doSomething(d); // 다형성 발현 -> "I'm Derived"


	
/* #2 객체 잘림 발생 - 다형성 사용 불가 */
	Derived d_2;
	Base b_2; 
	b_2 = d_2; 
	
	b_2.print(); // "I'm Base"
	doSomething_2(d); // 함수 매개변수에서 &지움 -> 다형성 발현x -> "I'm Base"



/* #3 vector 사용할때 */
	Base b_3;
	Derived d_3;

	std::vector<Base> my_vec;
	my_vec.push_back(b_3);
	my_vec.push_back(d_3);

	for (auto& ele : my_vec)
		ele.print(); // 다형성 구현 안됨 -> "I'm Base" 2번

	std::vector<Base*> my_vec_2;
	my_vec_2.push_back(&b_3);
	my_vec_2.push_back(&d_3);

	for (auto& ele : my_vec_2)
		ele->print(); // 다형성 유지O


/* #4 reference를 사용하고 싶을 경우 
      ->  std::vector<Base&> my_vec3; 처럼 작동하고 싶을 경우 */

	// Base의 reference를 저장하는 vector 선언
	std::vector<std::reference_wrapper<Base>> my_vec3;

	my_vec3.push_back(b_3);
	my_vec3.push_back(d_3);

	for (auto& ele : my_vec3)
		ele.get().print(); // 다형성 유지O

	return 0;
}