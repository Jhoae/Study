// Literal Constants
#include <iostream>

int main()
{
	using namespace std;

	float pi = 3.14f;	// f: float  , l: long
	int i = 123424u;	// u: unsigned
					
	int ui = (unsigned)123424;	


	// ���� (����)
	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e-10;

	// 10���� Decimal: 0 1 2 3 4 5 6 7 8 9 10
	// 8���� Octal: 0 1 2 3 4 5 6 7 10 11 12 13 ...
	// 16���� Hexa: 0 1 2 3 4 5 6 7 8 9 A B C D E F 10

	
	int x = 012; // �տ� 0 �� ���̸� 8���� -> ��°�: 10
	cout << x << endl;

	int y = 0xF; // �տ� 0x �� ���̸� 16����-> ��°�: 15
	cout << y << endl;

	int z = 0b1010; // �տ� 0b �� ���̸� 2���� -> ��°�: 10
	cout << z << endl;

	int q = 0b1010'1111'1010; // ������� �̷������� ��� ���⵵ ����


	// Tip: ������ ���� ����ü���ٴ� ����� �ٲ�δ°��� ����
	const int price_per_item = 10;
	int num_items = 12;
//	int price = num_items * 10;
	int price = num_items * price_per_item;

	return 0;
}