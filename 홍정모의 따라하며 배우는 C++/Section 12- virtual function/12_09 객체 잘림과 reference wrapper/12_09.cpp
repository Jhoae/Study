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
/* #1 ������ ������ �����Ǵ� ��� */
	Derived d;
	Base& b = d; // ������ ���� 

	b.print(); // "I'm Derived"
	doSomething(d); // ������ ���� -> "I'm Derived"


	
/* #2 ��ü �߸� �߻� - ������ ��� �Ұ� */
	Derived d_2;
	Base b_2; 
	b_2 = d_2; 
	
	b_2.print(); // "I'm Base"
	doSomething_2(d); // �Լ� �Ű��������� &���� -> ������ ����x -> "I'm Base"



/* #3 vector ����Ҷ� */
	Base b_3;
	Derived d_3;

	std::vector<Base> my_vec;
	my_vec.push_back(b_3);
	my_vec.push_back(d_3);

	for (auto& ele : my_vec)
		ele.print(); // ������ ���� �ȵ� -> "I'm Base" 2��

	std::vector<Base*> my_vec_2;
	my_vec_2.push_back(&b_3);
	my_vec_2.push_back(&d_3);

	for (auto& ele : my_vec_2)
		ele->print(); // ������ ����O


/* #4 reference�� ����ϰ� ���� ��� 
      ->  std::vector<Base&> my_vec3; ó�� �۵��ϰ� ���� ��� */

	// Base�� reference�� �����ϴ� vector ����
	std::vector<std::reference_wrapper<Base>> my_vec3;

	my_vec3.push_back(b_3);
	my_vec3.push_back(d_3);

	for (auto& ele : my_vec3)
		ele.get().print(); // ������ ����O

	return 0;
}