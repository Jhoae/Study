#include <iostream>
#include <string>

using namespace std;

struct Person // member 4��
{
	double height;	
	float weight;
	int age = 26;	// �⺻�� ���� ����
	string name;

	/*	 */
	void print()
	{
		cout << "print" << height << " " << weight << " " << age << " " << name << endl;
	}


};

/*		�Լ��� struct �ۿ��� ����		*/
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
// => padding�߻� => X. 
// (2 +(2)) + 4 + 8 = 16bytes�� �ȴ�
{
	short	id;		// 2 bytes
	int		age;	// 4 bytes
	double	wage;	// 8 bytes
};


int main()
{

	/* ����
	double height;
	float weight;
	int age;
	string name;

	void printPerson(double height, float weight, int age, string name) 
	{}
	*/

	/*	����ü					*/

	
	/* 	���� ��� 1
	Person me;
	me.age = 20;
	me.name = "Jho";
	me.height = 2.0; 	*/

	// ���� ��� 2
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