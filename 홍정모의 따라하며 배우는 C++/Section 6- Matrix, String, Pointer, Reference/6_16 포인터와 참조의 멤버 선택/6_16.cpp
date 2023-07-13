/*
pointer�� reference�� 
struct�� class�� ���ؼ� ����Ҷ�, 
������ ����� �����ϴ� ���(������)
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
	// 1. �Ϲ����� struct ���
	Person person;

	person.age = 20;
	person.weight = 60.1;

	// 2. ������ ����� ���
	Person& ref = person;
	ref.age = 5;
	ref.weight = 10.2;

	// 3. pointer�� ����� ���
	Person* ptr = &person;
	ptr->age = 30;
	ptr->weight = 70.2;
	// "->" �Ǵ� de-referencing operator����
	(*ptr).age = 20;
	(*ptr).weight = 30.2;


	// 4. ref�� *pointer���� �Ҵ� ����
	Person& ref2 = *ptr;
	ref2.age = 45;

	// -> �ּҰ��� ����
	cout << "&person:\t" << &person << endl;
	cout << "&ref2:\t\t" << &ref2 << endl;

	return 0;
}