#include <iostream>
using namespace std;

class A
{
public:
	virtual void print_virt(int x) { cout << "A_virt" << endl; }

/* #1 parameter가 다르면 overriding할수가 없다*/
	virtual void print_override(int x) { cout << "A" << endl; }

/* #2 final 키워드 -> 더 이상 밑에서 override 불가능 */
	virtual void print_override2() { cout << "A" << endl; }

/* #3 공변 반환값 covariant return type */
	void print() { cout << "A" << endl; }
	virtual A* getThis() { cout << "A getThis" << endl; return this; }
};

class B : public A
{
public:

/* #1 parameter가 다르면 overriding할수가 없다*/
	void print_virt(short x) { cout << "B" << endl; }

	void print_override(int x) override { cout << "B" << endl; }

/* #2 final 키워드 -> 더 이상 밑에서 override 불가능 */
	void print_override2() final { cout << "B" << endl; }

/* #3 공변 반환값 covariant return type
	-> 일반적으로 return 타입이 다르면 override가 안되지만
	   A와 B는 부모자식 관계이기 때문에, overriding이 된다. 	*/

	void print() { cout << "B" << endl; }
	virtual B* getThis() { cout << "B getThis" << endl; return this; }
};


class C : public B
{
public:
	virtual void print() { cout << "C" << endl; }

/* #2 final 키워드 -> 더 이상 밑에서 override 불가능 */
// Error: void print_override2() { cout << "C" << endl; }
};


int main()
{
	A a;
	B b;
//	C c;

/* #1 parameter가 다르면 overriding할수가 없다*/
	A& ref = b;
	ref.print_virt(1); // 함수는 parameter가 다르면 overriding할수가 없다

/* #3 공변 반환값 covariant return type 
    -> 일반적으로 return 타입이 다르면 override가 안되지만 
	   A와 B는 부모자식 관계이기 때문에, overriding이 된다. 	*/
	A& ref2 = b;
	b.getThis()->print();   // *B->print();
	ref.getThis()->print(); 

	cout << "typeid(b.getThis()).name() :\t" 
		<< typeid(b.getThis()).name() << endl; 
	// "B getThis"
	// class B *

	cout << "typeid(ref.getThis()).name() :\t" 
		<< typeid(ref.getThis()).name() << endl; 
	// "B getThis"
	// class A *

	// -> ref가 A이기때문에, ref.getThis에서 B의 pointer를 return해줘도 그걸 다시 A의 pointer로 
	//    내부적으로 바꾼다음에 print를 호출하는 구조이다.

	return 0;
}