// Ư���� �ڷ����� ���� �ٸ� ����� �����Ҷ� ����ϴ� ���ø� Ư��ȭ
#include <iostream>
#include "Storage.h"
#include "Storage.cpp"

using namespace std;

/* #1 ���ø� �ۼ� */
template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

/* #2 Ư��ȭ specialization */
template<>
char getMax(char x, char y)
{
	cout << "Warning : char ��:\t";

	return (x > y) ? x : y;
}

/* #3 */
template<>
void Storage<double>::print()
{
	std::cout << "Double Type";
	std::cout << std::scientific << m_value << '\n';
}

int main()
{
	cout << getMax(1, 2) << endl; // #1
	cout << getMax('a', 'b') << endl; // #2

	printf("\n#3 \n");

	/* #3 */
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	return 0;
}