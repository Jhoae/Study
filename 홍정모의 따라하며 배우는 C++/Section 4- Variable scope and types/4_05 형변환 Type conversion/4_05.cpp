#include <iostream>
#include <typeinfo>
#include <iomanip>


int main()
{
	using namespace std;

	int a = 123;
	cout << typeid(4.0).name() << endl;	// � data type���� �������
	cout << typeid(a).name() << endl;	




	printf("\n");
	/* 	numeric conversion - �� ���������� �Ҵ�	*/
	float b = 1.0f;
	double c = a;	// numeric promotion :: f < d ==> �� ���� ���� �Ҵ� -> ����X



	/*	numeric conversion - �� ���������� �Ҵ�	*/		
	int i = 30000;
	char d = i; // char�� 30000�� ������ ����.
	cout << static_cast<int>(d) << endl;	// �� �������� �Ҵ�ǹǷ� ����� ����X


	double e = 0.123456789;
	float f = e;
	cout << std::setprecision(12) << f << endl;	// �� �������� �Ҵ�ǹǷ� ����� ����X

	float g = 3.14;
	int h = g;
	cout << std::setprecision(12) << h << endl;	// �� �������� �Ҵ�ǹǷ� ����� ����X


	cout << 5u - 10u << endl; // u: unsigned // ������ ���� == ����ȯ �켱����
	
	// ����ȯ �켱���� (��������)
	// int, unsigned int, long, unsigned long,
	// long long, unsigned long long, float, double
	// long double


	/*	����� casting	*/
	int k = int(4.0);
	int l = (int)4.0;
	int m = static_cast<int>(4.0);

	return 0;
}