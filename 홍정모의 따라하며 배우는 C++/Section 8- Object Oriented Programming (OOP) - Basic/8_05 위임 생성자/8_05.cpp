//���� ������: �����ڰ� �ٸ� �����ڸ� ����ϴ°�

#include <iostream>
#include <string>

using namespace std;

/* #1 class �ۼ� */
class Student
{
private:
	int m_id;
	string m_name;

public:
/* #2 �̸��� �Է��ؼ� instance�� ����� ���� ��츦 ���� �Ʒ� �ڵ�(���ӻ�����)�� �ۼ� 
   -> �̷� ����� ����õ */

	Student(const string& name_in)
		// :m_id(0), m_name(name_in) :: �� �ٽ� �ʱ�ȭ�ϴ� ��ſ� �Ʒ�ó��
		// :Student(0, name_in)  /* #3 �����ʱ�ȭ �Լ� �ۼ����� �Ʒ��� ��ü�� ���� */
	{
		init(0, name_in);
	}
/* #2 �̸��� �Է��ؼ� instance�� ����� ���� ��츦 ���� �� �ڵ�(���ӻ�����)�� �ۼ� */

	Student(const int& id_in, const string& name_in)
	//	: m_id(id_in), m_name(name_in) 	/* #3 �����ʱ�ȭ �Լ� �ۼ����� �Ʒ��� ��ü�� ���� */
	{
		init(id_in, name_in);
	}

/* #3 �����ʱ�ȭ �Լ� �ۼ� */
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void print()
		{
			cout << "m_id" << m_id << endl;
			cout << "m_name" << m_name << endl;
		}
};


int main()
{

	Student st1(0, "Jack Jack");
	st1.print();


/* #2 �̸��� �Է��ؼ� instance�� ����� ���� ��츦 ���� �Ʒ� �ڵ�(���ӻ�����)�� �ۼ� */
	Student st2("Dash");
	st2.print();

	return 0;
}