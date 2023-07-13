/*
pointer나 reference를 
struct나 class에 대해서 사용할때, 
내부의 멤버를 선택하는 방법(연산자)
*/

#include <iostream>

using namespace std;

struct Person
{
	int age;
	double weight;
};

int main() 
{
	// 1. 일반적인 struct 사용
	Person person;

	person.age = 20;
	person.weight = 60.1;

	// 2. 참조를 사용할 경우
	Person& ref = person;
	ref.age = 5;
	ref.weight = 10.2;

	// 3. pointer를 사용할 경우
	Person* ptr = &person;
	ptr->age = 30;
	ptr->weight = 70.2;
	// "->" 또는 de-referencing operator가능
	(*ptr).age = 20;
	(*ptr).weight = 30.2;


	// 4. ref에 *pointer값을 할당 가능
	Person& ref2 = *ptr;
	ref2.age = 45;

	// -> 주소값이 같다
	cout << "&person:\t" << &person << endl;
	cout << "&ref2:\t\t" << &ref2 << endl;

	return 0;
}