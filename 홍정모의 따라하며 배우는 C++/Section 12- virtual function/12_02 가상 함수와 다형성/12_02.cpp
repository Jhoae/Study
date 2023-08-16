#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }

/* #1 pointer 바꿔주기 -> overriding이 있을경우 */
	virtual void print_virt() { cout << "A_virt" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }

	void print_virt() { cout << "B_virt" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }

	void print_virt() { cout << "C_virt" << endl; }

};

class D : public C
{
public:
	void print() { cout << "D" << endl; }

/* #3 overriding을 할때 return 타입이 다를 경우 
      -> 맨 위 class의 함수 반환 타입과 일치하지 않는다면 ERROR가 발생 */

	void print_virt() { cout << "D_virt" << endl; }
	// int print_virt() { cout << "D_virt" << endl; return 0; }
};



int main()
{
	A a;
	B b;
	C c;
	D d;

	a.print();
	b.print();
	c.print();
	d.print();

	printf("\n#1 pointer 바꿔주기 \n");
/* #1 pointer 바꿔주기 -> overriding이 있을경우 */

	A& ref = b;
	ref.print(); // A의 reference -> "A"
	
	ref.print_virt(); // virtual -> B에서 overriding된 함수를 그대로 사용 -> "B_virt"

	A& ref_2 = c;
	ref_2.print_virt(); // "C_virt"

/* #2 가장 상위 class가 virtual이 되면 밑의 class도 virtual처럼 행동한다 */

	B& ref = c; // B의 print_virt 함수는 virtual이 아님
	ref.print_virt(); // "C_virt"

	return 0;
}