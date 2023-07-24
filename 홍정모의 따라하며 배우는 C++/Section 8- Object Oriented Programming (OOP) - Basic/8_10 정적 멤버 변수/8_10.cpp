#include <iostream>

using namespace std;

/* #1 ��� ������ static���� ����*/
class Something
{
public:
	// ERROR:: static int m_value = 1;
	static int s_value;
	static const int c_value = 22; // static const�� ��� �̰����� �ʱ�ȭ
	static constexpr int ct_value = 33; // compile time�� �����Ǵ� ���
};

int Something::s_value = 77; // static member�� ��� ������Ϻ��� cpp���Ͽ� �����ϴ°��� ���� -> compile ���� ����

int main()
{
/* #1 ��� ������ static���� ����*/
	printf("#1 ��� ������ static���� ����\n");
	
	
	cout << "instance ������ Something::s_value:\t" << Something::s_value << endl;
	cout << "instance ������ &Something::s_value:\t" << &Something::s_value << endl;

	Something st1;
	Something st2;

	st1.s_value = 2;

	cout << "st1.m_value:\t" << st1.s_value << endl;
	cout << "&st1.m_value:\t" << &st1.s_value << endl;

	cout << "st2.m_value:\t" << st2.s_value << endl;
	cout << "&st2.m_value:\t" << &st2.s_value << endl;


	printf("\n");
	Something::s_value = 1024;
	cout << "Something::s_value = 1024���� Something::s_value:\t" << Something::s_value << endl;
	cout << "Something::s_value = 1024���� &Something::s_value:\t" << &Something::s_value << endl;


	return 0;
}