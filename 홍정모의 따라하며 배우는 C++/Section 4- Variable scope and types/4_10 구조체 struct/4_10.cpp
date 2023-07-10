#include <iostream>
#include <string>

using namespace std;

struct Person // member 4개
{
	double height;	
	float weight;
	int age = 26;	// 기본값 설정 가능
	string name;

	/*	 */
	void print()
	{
		cout << "print" << height << " " << weight << " " << age << " " << name << endl;
	}


};

/*		함수를 struct 밖에서 정의		*/
void printPerson(Person per) 
{
	cout << per.height << " " << per.weight << " " << per.age << " " << per.name << endl;
}

struct Family
{
	Person me, bro, mom, dad;
};

Person getBro()
{
	Person bro{ 2.0, 100.0, 20, "Bro" };

	return bro;
}



struct Employee 
// 2 +4 +8= 14bytes? 
// => padding발생 => X. 
// (2 +(2)) + 4 + 8 = 16bytes가 된다
{
	short	id;		// 2 bytes
	int		age;	// 4 bytes
	double	wage;	// 8 bytes
};


int main()
{

	/* 불편
	double height;
	float weight;
	int age;
	string name;

	void printPerson(double height, float weight, int age, string name) 
	{}
	*/

	/*	구조체					*/

	
	/* 	정의 방식 1
	Person me;
	me.age = 20;
	me.name = "Jho";
	me.height = 2.0; 	*/

	// 정의 방식 2
	Person me{ 2.0, 100.0, 20, "Me" };
	Person me2(me);
	Person me3;
	me3 = me;

	printPerson(me);
	me.print();
	
	Person bro_from_func = getBro();
	bro_from_func.print();


	/*			*/
	Employee emp1;
	cout << sizeof(emp1) << endl;


	return 0;
}