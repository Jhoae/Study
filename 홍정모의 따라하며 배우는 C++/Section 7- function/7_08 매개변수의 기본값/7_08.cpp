#include <iostream>
#include <string>

using namespace std;



void print(int x = 0) // default parameter
{
	cout << "x: " << x << endl;
}

void print_3(int x = 10, int y = 20, int z = 30)
{
	cout << "x: " << x 
		<< ", y: " << z 
		<< ", z: " << z << endl;
}

/* ����� ���Ǹ� �и��� ��� (Header file�� ����� ���)
	-> ���߿� �Ѱ������� �⺻���� �����ؾ���*/

void print_sepa(int x = 10, int y = 20, int z = 30); // ����
void print_sepa(int x, int y, int z) {} // ����


/* �Լ� overloading�� default value */
void print_od(std::string str) {}
void print_od(char ch = ' ') {}

void print_od2(int x) {}
void print_od2(int x, int y = 10) {}

int main()
{

/* default value */
	print(10);
	print();

	print_3();
	print_3(100);
	print_3(100, 200);
	print_3(100, 200, 300);


/* �Լ� overloading�� default value */
	print_od(); // print_od(char)

	// print_od2(10); // ambiguous Error

	


	return 0;
}