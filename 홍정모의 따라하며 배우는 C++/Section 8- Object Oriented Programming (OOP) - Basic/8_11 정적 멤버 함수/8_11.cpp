#include <iostream>

using namespace std;

/* #1 */
class Something
{
public:
	static int s_value; // ��� instance���� ���ٰ���. �Ѱ��� �ּҰ��� ����
	int m_value;

public:
/* #2 static member function���� this Ű���� ���Ұ� */
	static int getValue()
	{
		// ERROR :: return this->s_value; OR return s_value;
		// ERROR :: return this->m_value; OR return m_value;

		return s_value;
	}

	int get_this()
	{
		// this :: Ư�� instance�� ���� member�� ����ϴ� ��
		return this->s_value;
	}
};

// ���� ��� ���� �ʱ�ȭ
int Something::s_value = 77;




/* #4 class�ȿ� static member ������ �ʱ�ȭ �ϴ¹� */
class Class4
{
/* #4 Inner class ����Ͽ� static member variable �ʱ�ȭ*/
public:
	class _init
	{
	public:
		_init()
		{
			sc_value = 9999;
		}
	};

private:
	static int sc_value; // ��� instance���� ���ٰ���. �Ѱ��� �ּҰ��� ����
	int mc_value;

	static _init sc_initializer;


	/* #4 static member variable�� Constructor���� �ʱ�ȭ �Ұ��� */
public:
	Class4()
		: mc_value(123)
		// ERROR :: ,sc_value(1024),
		// -> �ٸ� ���(Inner class)���� �ʱ�ȭ 
	{}

	static int getValue()
	{
		// ERROR :: return this->s_value; OR return s_value;
		// ERROR :: return this->m_value; OR return m_value;

		return sc_value;
	}

	int get_this()
	{
		// this :: Ư�� instance�� ���� member�� ����ϴ� ��
		return this->sc_value;
	}
};

int Class4::sc_value = 1111;
Class4::_init Class4::sc_initializer;


int main()
{
	/* #1 Ư�� instance�� ������� �����ų�� �ִ�. */
	cout << "Something::s_value:\t" << Something::getValue() << endl;

	Something s1, s2;

	cout << "s1.getValue():\t" << s1.getValue() << endl;
	// cout << "s1.s_value" << s1.s_value << endl;


	printf("\n#3 member function�� pointer ��������\n");
/* #3 member function�� pointer ��������
	-> member function�� �ϳ��� �ּҰ��� ���´� */

/* #3-1 �Ϲ� ��� �Լ��� pointer */
	// ERROR :: int (Something:: * fptr1)() = s2.get_this;
	int (Something:: * fptr1)() = &Something::get_this;

	// ERROR :: cout << "(*fptr1)():\t" << (*fptr1)() << endl;
	
	// instance�� member function pointer�� �Ѱ��־� ����� �� �ִ�.
	// -> (instance�� ���ӵǾ��ִ�.)
	cout << "(s2.*fptr1)():\t" << (s2.*fptr1)() << endl;

/* #3-2 static ��� �Լ��� pointer 
		-> Ư�� instance�� ������� �����ų�� �ִ�. */

	// ERRROR :: int (Something:: * fptr2)() = &Something::getValue;

	// Ư�� instance�� ������� �����ų�� �ִ�.
	int (* fptr2)() = &Something::getValue;

	cout << "fptr2():\t" << fptr2() << endl;




	printf("\n#4\n");
/* #4 static member variable�� Constructor���� �ʱ�ȭ �Ұ��� */

	Class4 c1, c2;
	cout << "c1.getValue():\t" << c1.getValue() << endl;

	return 0;
}